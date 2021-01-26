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
#define MY_DEBUG_OTA (201)

// Allow sending logs without MY_DEBUG_OTA enabled
// #define MY_OTA_LOG_SENDER_FEATURE

// Enable OTA log display
//#define MY_OTA_LOG_RECEIVER_FEATURE

// Disable echoing of debug messages
//#define MY_DEBUG_OTA_DISABLE_ECHO
#define MY_NODE_ID 200
// for NRF24DUINO you have to specify a different CE-Pin for NRF24L01+
#define MY_RF24_CE_PIN 7
// Enable and select radio type attached
#define MY_RADIO_RF24
//#define MY_RADIO_NRF5_ESB
//#define MY_RADIO_RFM69
//#define MY_RADIO_RFM95

// Enable repeater functionality for this node
#define MY_REPEATER_FEATURE

#include <MySensors.h>

#define RELAY_PIN 4  // Arduino Digital I/O pin number for first relay (second on pin+1 etc)
#define NUMBER_OF_RELAYS 1 // Total number of attached relays
#define RELAY_ON 1  // GPIO value to write to turn on attached relay
#define RELAY_OFF 0 // GPIO value to write to turn off attached relay

void before()
{
	for (int sensor=1, pin=RELAY_PIN; sensor<=NUMBER_OF_RELAYS; sensor++, pin++) {
		// Then set relay pins in output mode
		pinMode(pin, OUTPUT);
		// Set relay to last known state (using eeprom storage)
		digitalWrite(pin, loadState(sensor)?RELAY_ON:RELAY_OFF);
	}
}

void setup()
{
}

void presentation()
{
	// Send the sketch version information to the gateway and Controller
	sendSketchInfo("Relay", "1.0");

	for (int sensor=1, pin=RELAY_PIN; sensor<=NUMBER_OF_RELAYS; sensor++, pin++) {
		// Register all sensors to gw (they will be created as child devices)
		present(sensor, S_BINARY);
	}
}

void loop()
{

}

void receive(const MyMessage &message)
{
	// We only expect one type of message from controller. But we better check anyway.
	if (message.getType()==V_STATUS) {
		// Change relay state
		digitalWrite(message.getSensor()-1+RELAY_PIN, message.getBool()?RELAY_ON:RELAY_OFF);
		// Store state in eeprom
		saveState(message.getSensor(), message.getBool());
		// Write some debug info

		DEBUG_OUTPUT(PSTR("Incoming change for sensor: % " PRId16 ", New status: %" PRId16 "\n"), message.getSensor(), message.getInt());
	}
}
