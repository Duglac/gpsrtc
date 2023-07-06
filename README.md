# Overview
This repository contains files used to display values from an RTC (Real-Time Clock) and GPS module integrated into a BeagleBone board. The BeagleBone does not have an onboard RTC, so an external RTC module was added to provide accurate timekeeping. Additionally, the GPS module provides latitude and longitude information.

# Components
The project utilizes the following components:

* BeagleBone: The main development board used for this project.
* RTC Module: An external Real-Time Clock module connected to the BeagleBone via the I2C interface. This module provides accurate timekeeping capabilities.
* GPS Module: A GPS module connected to the BeagleBone via UART (Universal Asynchronous Receiver-Transmitter) communication. It provides latitude and longitude information.

# File Structure
The repository is organized as follows:

* server.js: This file is the main Node.js server script. It communicates with the GPS module and retrieves the time and GPS coordinates. It utilizes the executable file generated from gpsparser.c to handle the low-level communication with the GPS module.
* gpsparser.c: This file is responsible for parsing GPS data using the NMEA 0183 protocol. It utilizes UART communication to receive data from the GPS module and extract the time and GPS coordinates. It shows only latitude and longitude.
* README.md: This file provides an overview and instructions for using the files in this repository.

# Other
Thanks for your time!
