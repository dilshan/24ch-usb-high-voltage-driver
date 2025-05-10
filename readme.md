## 24-Channel USB high voltage driver

![Prototype build of the 24-channel USB high voltage driver.](https://raw.githubusercontent.com/dilshan/24ch-usb-high-voltage-driver/refs/heads/main/resources/24ch-relay-driver.jpg)

This project is a compact, driver-free USB module designed for high-voltage, medium-current output. It emphasizes ease of use, reliability, and flexibility for various control and automation applications. This module offers the following features:

- **24 independent high-voltage outputs:** Each output channel is controlled using [TPIC6B595](https://www.ti.com/lit/ds/symlink/tpic6b595.pdf) shift registers, which provide the capability for high-voltage and medium-current switching.

- **Dual power options:** Can choose between USB bus power and an external 5V supply using on-board jumpers.

- **Simple serial interface:** Communicate with the module through a virtual COM port using AT-style commands. You can easily set, get, and clear output states.

- **Device driver-free operation:** The module is recognized as a standard USB serial device (based on [CH340N](https://aitendo3.sakura.ne.jp/aitendo_data/product_img/ic/inteface/CH340N/ch340n.pdf)), meaning it requires no additional driver installation on most operating systems.

This repository includes the [schematic](https://github.com/dilshan/24ch-usb-high-voltage-driver/blob/main/design/24-ch-relay-driver-kicad.pdf), PCB design, firmware source code, and [compiled firmware](https://github.com/dilshan/24ch-usb-high-voltage-driver/releases) for this project. The complete [documentation](https://github.com/dilshan/24ch-usb-high-voltage-driver/wiki) for this project is available in the [wiki section](https://github.com/dilshan/24ch-usb-high-voltage-driver/wiki) of this repository. It includes all necessary details for producing the PCB, compiling and uploading the firmware, the command set, and more.

This is a [certified open-source hardware project](https://certification.oshwa.org/lk000015.html). All the design files, [documentation](https://github.com/dilshan/24ch-usb-high-voltage-driver/wiki), firmware source code are available to download at the project source repository. All the content of this project are distributed under the terms of the following license:

 - Hardware license: [CERN-OHL-W](https://opensource.org/license/cern-ohl-w)
 - Software license: [MIT License](https://github.com/dilshan/24ch-usb-high-voltage-driver/blob/main/LICENSE)
 - [Documentation](https://github.com/dilshan/24ch-usb-high-voltage-driver/wiki) license: [CC BY 4.0](https://creativecommons.org/licenses/by/4.0)
 
 ![LK000015](https://raw.githubusercontent.com/dilshan/24ch-usb-high-voltage-driver/refs/heads/main/resources/LK000015.png)
