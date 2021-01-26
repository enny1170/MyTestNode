# MyLoggerNode
Project to build a Debug Node based on NRF24Duino from Electrodragon

This is a Arduino Pro mini clone with a NRF24L01 and a Flash-Memory on board.

see https://www.electrodragon.com/w/NRF24L01

buy at https://www.electrodragon.com/product/nrf24duino-arduino-mini-plus-nrf24l01-board/

On this node fallowing extra defines set:

    #define MY_BAUD_RATE 115200

    // Enable debug
    #define MY_DEBUG

    #define MY_NODE_ID 254
    // for NRF24DUINO you have to specify a different CE-Pin for NRF24L01+
    #define MY_RF24_CE_PIN 7

    // Enable OTA log display
    #define MY_OTA_LOG_RECEIVER_FEATURE


On all nodes tht will send OTA Log you have to set this:

    define MY_DEBUG_OTA (254)  //254 is Id of node that will receive the ota-log 