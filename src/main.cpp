#include <Arduino.h>
/*
 * The MySensors Arduino library handles the wireless radio link and protocol
 * between your home built sensors/actuators and HA controller of choice.
 * The sensors forms a self healing radio network with optional repeaters. Each
 * repeater and gateway builds a routing tables in EEPROM which keeps track of the
 * network topology allowing messages to be routed to nodes.
 *
 * Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
 * Copyright (C) 2013-2019 Sensnology AB
 * Full contributor list: https://github.com/mysensors/MySensors/graphs/contributors
 *
 * Documentation: http://www.mysensors.org
 * Support Forum: http://forum.mysensors.org
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 *******************************
 *
 * DESCRIPTION
 *
 * Example for sending debug messages over the air (OTA).
 *
 */

#define MY_BAUD_RATE 115200

// Enable debug
#define MY_DEBUG

// Enable OTA debugging to Node 0
// #define MY_DEBUG_OTA (201)

// Allow sending logs without MY_DEBUG_OTA enabled
// #define MY_OTA_LOG_SENDER_FEATURE

// Enable OTA log display
#define MY_OTA_LOG_RECEIVER_FEATURE

// Disable echoing of debug messages
//#define MY_DEBUG_OTA_DISABLE_ECHO
#define MY_NODE_ID 254
// for NRF24DUINO you have to specify a different CE-Pin for NRF24L01+
#define MY_RF24_CE_PIN 7
// Enable and select radio type attached
#define MY_RADIO_RF24
//#define MY_RADIO_NRF5_ESB
//#define MY_RADIO_RFM69
//#define MY_RADIO_RFM95

#include <MySensors.h>

// void receive(const MyMessage &message)
// {
// 	OTADebugReceive(message);
// }

void setup()
{
}

void presentation()
{
	// Send the sketch version information to the gateway and Controller
	sendSketchInfo("DebugSensor", "1.0");
}

// Arduino loop
int c=0;
void loop()
{
	// Wait some time
	// if (sleep(3000)==MY_SLEEP_NOT_POSSIBLE) {
	// 	delay(3000);
	// }

	// // Count loops
	// c++;

	// // A debug message
	// DEBUG_OUTPUT(PSTR("DEBUG\nc=%" PRId16 "\nmillis=%" PRId32 "\n"), c, hwMillis());

	// // Send a log message to a node, requesting that the message is echoed back to this node
	// // OTALog(0, true, PSTR("LOG\nc=%" PRId16 "\nmillis=%" PRId32 "\n"), c, hwMillis());
	// Serial.println(".");
}
