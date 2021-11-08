# MyEnvironmentNode
Project to build a Temperature / Humidity Node based on NRF24Duino from Electrodragon

This is a Arduino Pro mini clone with a NRF24L01 and a Flash-Memory on board.

see https://www.electrodragon.com/w/NRF24L01

buy at https://www.electrodragon.com/product/nrf24duino-arduino-mini-plus-nrf24l01-board/

This is a Battery driven Project.
 
To Minimize the Power consumption fallowing changes on the module is done
- remove the external Flash chip (small 8 pin)
- open the Solderbridge near of Vin (also remove the power Regulator small 3 pin chip)

From Software site we have created a environment 'nrfduino1Mhz'. 
This is allready setup to build the Software for 1MHz and ready to set the fuses for the AVR. 
For Fuses we need to use a Programmer. So this setup is prepared for a AVRisp MKII on USB.
Burning the software to the Controller can also be done with this setup. 
For the fuses use:  pio run --target fuses
It is recommendet firs change the fuse then write the software.

the correct Fuses for this Setup are
board_fuses.lfuse = 0x7F
board_fuses.hfuse = 0xDA
board_fuses.efuse = 0xFE


On this node fallowing extra defines rerouted to fallowing Build flag in the environment

 - #define MY_BAUD_RATE SERIALSPEED

 - #define MY_NODE_ID NODEID

  // for NRF24DUINO you have to specify a different CE-Pin for NRF24L01+
 - #define MY_RF24_CE_PIN 7

 - the third Build-Flag is used to set the minimum battery Voltage to calculate the right battery percentage.
 
