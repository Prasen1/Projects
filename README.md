# Temperature and Humidity Monitoring with IOT
This project uses a NodeMCU module with DHT11 sensor for recording ambient temperature and humidity. The data is uploaded to ThingsSpeak platform for charting and analysis.

## Hardware Requirements
1. NodeMCU: -
The NodeMCU (Node Microcontroller Unit) is an open source software and hardware development environment that is built around a very inexpensive System-on-a-Chip (SoC) called the ESP8266. The ESP8266, designed and manufactured by Espressif Systems, contains all crucial elements of the modern computer: CPU, RAM, networking (Wi-Fi), and even a modern operating system and SDK.

2. DHT11 sensor
This DHT11 Temperature and Humidity Sensor features a calibrated digital signal output with the temperature and humidity sensor complex. Its technology ensures the high reliability and excellent long-term stability. A high-performance 8-bit microcontroller is connected. This sensor includes a resistive element and a sense of wet NTC temperature measuring devices. 

The DHT11 sensor has 3 functioning pins VCC, data pin and ground.

3. Jumper wires
Jumper wires are simply wires that have connector pins at each end, allowing them to be used to connect two points to each other without soldering. Jumper wires are typically used with breadboards and other prototyping tools in order to make it easy to change a circuit as needed.

### Connecting the hardware
The connections in the project are as follows: -
  NodeMCU Vin > DHT11 Vcc
  NodeMCU GND > DHT11 GND
  NodeMCU D3 > DHT11 Serial out.
 
The 2nd pin is of DHT11 is a data pin, it can send temperature and humidity value to the 3rd pin of NodeMCU. 1st and 4th pin of DHT11 is Vcc and Gnd and 3rd pin is no connection. The NodeMCU processes the temperature and humidity value and sends it to ESP8266 Wi-Fi module. Which uploads the data to the cloud platform where we perform various operations on the data using MATLAB functions to get graphs and analytics. 

## Software Requirements

1. Arduino IDE
The Arduino integrated development environment (IDE) is a cross-platform application (for Windows, macOS, Linux) that is written in the programming language Java. It is used to write and upload programs to Arduino board. We use this IDE to write our main code that is burned onto the NodeMCU. The Arduino program Uses DHT library. After compiling and uploading the program, the Temperature and Humidity data is uploaded on ThingSpeak platform. And we can also see the uploaded data from serial port of Arduino IDE.

**Note:**
The SSID and password of the Wi-Fi hotspot has to be entered to which the ESP8266 module will connect. MyChannelNumber and myWriteAPIKey perform the validation by selecting our ThingsSpeak cloud platform’s channel number and our own API key respectively. As soon as the Wi-Fi is connected it will upload data every 15 seconds.


  readChannelID = 563560;
  fieldID1 = 1;
  fieldID2 = 2;
  readAPIKey = 'yourapikey';
  % Read first data variable
  data1 = thingSpeakRead(readChannelID, 'Field', fieldID1, 'NumPoints', 30, 'ReadKey', readAPIKey);
  % Read second data variable
  data2 = thingSpeakRead(readChannelID, 'Field', fieldID2, 'NumPoints', 30, 'ReadKey', readAPIKey);
  % Concatenate the two data variables
  data = [data1, data2];
  thingSpeakArea(data,'Legend',{'Temperature','Humidity'});

The above MATLAB code using Thingspeak functions will take the two fields – temperature and humidity and plot them in a 2D graph. This can be used to see the recent changes in temperature and humidity and their relation. Using similar functions, we can-

•	Plot our data
•	Use a histogram to understand variation in data
•	Visualize directional data with compass plot
•	Use area plot to compare traffic data sets
•	Visualize our data using MATLAB Toolbox functions

