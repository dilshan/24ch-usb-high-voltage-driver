## 24-Channel USB high voltage driver

This project is a compact, driver-free USB module designed for high-voltage, medium-current output. It emphasizes ease of use, reliability, and flexibility for various control and automation applications. This module offers the following features:

- **24 Independent High-Voltage Outputs:** Each output channel is controlled using TPIC6B595 shift registers, which provide the capability for high-voltage and medium-current switching.

- **Dual Power Options:** You can choose between USB bus power and an external 5V supply using on-board jumpers. This provides flexibility depending on the power requirements of your application.

- **Simple Serial Interface:** Communicate with the module through a virtual COM port using AT-style commands. You can easily set, get, and clear output states.

- **Driver-Free Operation:** The module is recognized as a standard USB serial device, based on document number CH340N, meaning it requires no additional driver installation on most operating systems.

This is an open hardware project, and the repository includes the schematic, PCB design, firmware source code, and compiled firmware for this project.
