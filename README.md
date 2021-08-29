# h730duino firmware test

This repository contains the hardware test for [h730 duino board](https://github.com/martinribelotta/h730duino)

## Project content

 - Initialization code
 - Makefile based construction system
 - VSCode integration
 - USB CDC Serial console with command line with various commands:
   - reset, version and help
   - blinking speed change (background demostration)
   - sd commands (df, ls, cat)
   - qspi commands (WIP)

## Required tools:

 - ARM GCC embedded
 - GNU Make
 - Python3 with pyusb (install with `pip install pyusb`)
 - Optionally, tio or similar terminal

## VSCode required plugins

 - [ms-vscode.cpptools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
 - [spmeesseman.vscode-taskexplorer](https://marketplace.visualstudio.com/items?itemName=spmeesseman.vscode-taskexplorer)
 - [marus25.cortex-debug](https://marketplace.visualstudio.com/items?itemName=marus25.cortex-debug)
 - [ms-vscode.makefile-tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.makefile-tools)

## Status

 - [x] Blinking
 - [x] MCU work at 550MHz
 - [x] microSD access
 - [x] USB dev
 - [ ] USB host
 - [ ] QSPI access (WIP)
 - [ ] HyperRAM access
 - [ ] RTC working (TBD)
 - [ ] Ethernet
 - [ ] CAN
 - [ ] ADC/DAC performance test
 - [ ] SPI/i2c/serial access
 - [ ] PWM test
