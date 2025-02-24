
# Anemometer Project

This project is a refactored, industrial-grade firmware for an ESP32-based 4-Wheeler. The code has been reorganized using a class-based, object-oriented approach in C++ to improve modularity, maintainability, and readability—all while preserving the original logic.

## Project Structure

```
ark - 2/
├── lib
│   ├── BluetoothHandler
│   │   ├── BluetoothHandler.h
│   │   └── BluetoothHandler.cpp
│   ├── BT_String
│   │   └── BluetoothCommand.h
│   ├── Motor
│   │   ├── Motor.h
│   │   └── Motor.cpp
│   ├── PinDef
│   │   ├── PinDef.h
│   │   └── PinDef.cpp
│   └── StateMachine
│       ├── RobotController.h
│       └── RobotController.cpp
└── src
    └── main.cpp
```

## Features

- **Modular Design:** Each hardware and logical component is encapsulated within its own class.
- **State Machine:** Implements a robust state machine for movement.
- **Bluetooth Communication:** Supports commands via Bluetooth using the ESP32's BluetoothSerial.
- **Visual Feedback:** Uses LED patterns for status indication and debugging.
- **Motor Control:** Utilizes the L298N driver library for robust motor control.

## Getting Started

### Requirements

- **Hardware:** ESP32 (esp32doit-devkit-v1 recommended)  
- **Libraries:** 
  - Arduino framework for ESP32   
  - Preferences (included with ESP32 Arduino framework)

### Setup and Build

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/austin207/Mark-2-Advanced.git
   cd Mark-2-Advanced

2. **Build and Upload:**

   Use PlatformIO or your preferred IDE to build and upload the firmware to your ESP32.

   For PlatformIO:

   ```bash
   platformio run --target upload
   ```

## Usage

Once uploaded, the firmware will:

- Control motor actions based on the state machine implemented in `RobotController.cpp`.
- Allow control via physical buttons or over Bluetooth with commands like `FORWARD` and `BACKWARD`.

## Contributing

Contributions are welcome! Please fork the repository and submit pull requests with any improvements or bug fixes.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
