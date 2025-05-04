## 24-Channel USB high voltage driver

![Prototype build of the 24-channel USB high voltage driver.](https://raw.githubusercontent.com/dilshan/24ch-usb-high-voltage-driver/refs/heads/main/resources/24ch-relay-driver.jpg)

This project is a compact, driver-free USB module designed for high-voltage, medium-current output. It emphasizes ease of use, reliability, and flexibility for various control and automation applications. This module offers the following features:

- **24 independent high-voltage outputs:** Each output channel is controlled using [TPIC6B595](https://www.ti.com/lit/ds/symlink/tpic6b595.pdf) shift registers, which provide the capability for high-voltage and medium-current switching.

- **Dual power options:** Can choose between USB bus power and an external 5V supply using on-board jumpers.

- **Simple serial interface:** Communicate with the module through a virtual COM port using AT-style commands. You can easily set, get, and clear output states.

- **Device driver-free operation:** The module is recognized as a standard USB serial device (based on [CH340N](https://aitendo3.sakura.ne.jp/aitendo_data/product_img/ic/inteface/CH340N/ch340n.pdf)), meaning it requires no additional driver installation on most operating systems.

This is an open hardware project, and the repository includes the schematic, PCB design, firmware source code, and compiled firmware for this project. The complete [documentation](https://github.com/dilshan/24ch-usb-high-voltage-driver/wiki) for this project is available in the [wiki section](https://github.com/dilshan/24ch-usb-high-voltage-driver/wiki) of this repository. It includes all necessary details for producing the PCB, compiling and uploading the firmware, the command set, and more.

This is a an open-source hardware project. All the design files, documentation, firmware source code are available to download at the project source repository. All the content of this project are distributed under the terms of the following license:

 - Hardware License: [CERN-OHL-W](https://opensource.org/CERN-OHL-W)
 - Software License: [MIT License](https://github.com/dilshan/24ch-usb-high-voltage-driver/blob/main/LICENSE)
 - [Documentation](https://github.com/dilshan/24ch-usb-high-voltage-driver/wiki) License: [CC BY 4.0](https://creativecommons.org/licenses/by/4.0)
