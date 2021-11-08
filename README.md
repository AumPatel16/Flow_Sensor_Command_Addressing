# Flow_Sensor_Command_Addressing
Code to sniff commands of the device, and recreate commands for precise control of a commercial produc

Project done while on Coop at EMTS Lab.
There was a commercial flow sensor that was being used. In orrder to intergate that into our custom system, we needed control of all the commands without using their propriatery software.
There are 2 parts in here, there is a sniffer code that was created with the help of a senior engineer, but the sniffing, configuration of commands over serial ports, using SPI lines, and creation of a custom string  builder library with functions to address the device directly from C was made by me.
