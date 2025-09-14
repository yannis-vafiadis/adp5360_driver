# ADP5360 Battery Management PMIC Driver

A platform-independent HAL driver for the ADP5360 . This driver provides an interface to configure the charger, fuel gauge, buck/buck boost regulators, and monitor the status of the IC.

## Features

- **Initialization & Discovery**: Full device initialization and presence verification.
- **Charger Management**: Enable/disable battery charging and monitor charger status (trickle, constant current, constant voltage and charged).
- **Battery Protection**: Check battery status flags (normal, over voltage, under voltage, and high temperature).
- **Voltage Regulator Control**: Enable/disable the integrated Buck and Buck-Boost regulators.
- **Register Management**: Comprehensive functions to read from and write to the ADP5360's register map, which is integrated into the driver.
- **Interrupt Handling**: Framework for handling and processing device interrupts.
- **Hardware Abstraction**: Decoupled from the specific MCU, relying only on the STM32 HAL I2C library for portability across the STM32 family, but easily modifiable for any platform.

## Hardware Requirements

- A MCU with an I2C peripheral (tested on STM32U0 series).
- The Analog Devices ADP5360 PMIC.
- The appropriate pull-up resistors on the `SDA` and `SCL` lines.

## Hardware Connection

The driver assumes the ADP5360 is connected to the MCU's I2C peripheral. You must define the handle for this port in your main application.

| MCU Pin | ADP5360 Pin | Function |
| :--- | :--- | :--- |
| `GPIOx.SCL` | `SCL` | I2C Serial Clock |
| `GPIOx.SDA` | `SDA` | I2C Serial Data |
| `GPIOx` | `INT` | Interrupt Line |

## Dependencies

- **STM32Cube HAL**: This driver is using the STM32 HAL for I2C communication, but any HAL layer can be used with minimal modification.
- **Standard C Libraries**

## Usage

### 1. Include the Header

```c
#include "adp5360.h"
#include "adp5360_reg.h"
```

### 2. Define the I2C Handle

In your main file (e.g., main.c), you must declare and define the I2C handle that the driver will use to communicate with the ADP5360 and initialize the HAL and I2C (In case you use the STM32 HAL layer, otherwise follow your HAL's documentation).
```c
I2C_HandleTypeDef hi2c1;
```
### 3. Initialize the Driver

Call the initialization function at the start of your program. This function validates the presence of the chip and sets its default configuration.

```c
if (!adp5360_init()) {
  // Handle initialization error
}
```

### 4. Use Driver Functions
- **Enable Battery Charging**:
```c
  adp5360_en_charging(true);
```

- **Check if the Device is Charging**:
```c
if (adp5360_is_charging(true)) { // 'true' forces a fresh read of the status register
  // Battery is currently charging.
}
```

- **Get Detailed Charger Status**:
```c
CHARGER_STATUS status = adp5360_get_charger_status(false); // 'false' uses the cached register value

switch(status) {
  case CHARGER_STATUS_OFF:
    // Charging disabled
    break;
  case CHARGER_STATUS_TRICKLE:
    // Trickle charge mode
    break;
  case CHARGER_STATUS_FAST_CHARGE_CC:
    // Fast charge (Constant Current)
    break;
  case CHARGER_STATUS_FAST_CHARGE_CV:
    // Fast charge (Constant Voltage)
    break;
  case CHARGER_STATUS_CHARGE_COMPLETE:
    // Charging complete
    break;
}
```

### 5. Handling Interrupts

 Call the driver's interrupt handler from your GPIO ISR.
```c
// Example in stm32u0xx_it.c
void EXTI2_3_IRQHandler(void) {
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2); // Assuming INT is on Pin 2
}

// Callback function in main.c
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
  if (GPIO_Pin == ADP5360_INT_PIN) {
    adp5360_interrupt_handler();
  }
}
```

## API Reference

### Core Functions

| Function | Description |
| :--- | :--- |
| `bool adp5360_init(void)` | Initializes the driver and validates the chip's presence. Returns `true` on success. |
| `bool adp5360_validate_presence(bool read)` | Checks the manufacturer and revision IDs. |
| `HAL_StatusTypeDef adp5360_read_registers(adp5360_regs_t *regs, uint8_t start_reg, uint8_t count)` | Low-level function to read a block of registers. |
| `HAL_StatusTypeDef adp5360_write_registers(adp5360_regs_t *regs, uint8_t start_reg, uint8_t count)` | Low-level function to write a block of registers. |

### Charger Functions

| Function | Description |
| :--- | :--- |
| `bool adp5360_en_charging(bool enable)` | Enables or disables the battery charger. |
| `CHARGER_STATUS adp5360_get_charger_status(bool read)` | Returns the charging state. |
| `bool adp5360_is_charging(bool read)` | Checks if charging is active. |

### Battery Functions

| Function | Description |
| :--- | :--- |
| `BAT_CHG_STATUS adp5360_get_battery_status(bool read)` | Returns the battery status. |
| `bool adp5360_is_battery_ok(bool read)` | Checks if the battery status is OK. |

### Regulator Functions

| Function | Description |
| :--- | :--- |
| `bool adp5360_en_buck(bool enable)` | Enables or disables the Buck regulator. |
| `bool adp5360_en_buck_boost(bool enable)` | Enables or disables the Buck-Boost regulator. |

### Interrupt Function

| Function | Description |
| :--- | :--- |
| `void adp5360_interrupt_handler(void)` | Processes pending interrupts. Should be called from an ISR. |

### Parameter Guide
- `bool read`: When `true`, forces a fresh read from hardware registers. When `false`, uses cached values.
- `bool enable`: When `true`, enables the feature. When `false`, disables it.
- `*regs`: Pointer to the register structure containing data to read/write.
- `start_reg`: The starting register address for the read/write operation.
- `count`: Number of consecutive registers to read/write.

### Return Values
- `bool`: `true` = success, `false` = failure
- `HAL_StatusTypeDef`: STM32 HAL status codes (`HAL_OK`, `HAL_ERROR`, etc.)
- `CHARGER_STATUS`: Charger state enumeration
- `BAT_CHG_STATUS`: Battery status enumeration

## Configuration
- **Register Settings**: The default configuration is set in adp5360_init() within adp5360.c. Modify this function to change default behavior (e.g., charge current, voltage thresholds, timer settings).
- **I2C Port**: The I2C port is set by defining the global ADP5360_I2C_PORT handle.

## Examples
See the Usage section above for practical code examples.

## License
This project is licensed under the MIT License - see the LICENSE file for details.

## References
- **[ADP5360 Datasheet by Analog Devices](https://www.analog.com/media/en/technical-documentation/data-sheets/adp5360.pdf)**
- **STM32U0xx HAL Documentation**
