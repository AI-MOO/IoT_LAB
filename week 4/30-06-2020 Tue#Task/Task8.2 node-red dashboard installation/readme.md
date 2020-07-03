# node-red, ESP8266 LED Control and Steam Sensor data monitoring Using node-red dashboard:


** Note: this tutorial is depending on ![alt text](https://github.com/AI-MOO/IoT_LAB/tree/master/week%204/29-06-2020%20Mon%23Task/Task8.1%20node-red%20dashboard%20installation)
**STEP1: after running node-red using cmd, follow the following images to design your dashboard on node-red:
https://nodejs.org/en/**


![alt text](https://github.com/AI-MOO/IoT_LAB/blob/master/week%204/30-06-2020%20Tue%23Task/Task8.2%20node-red%20dashboard%20installation/12.png)
![alt text](https://github.com/AI-MOO/IoT_LAB/blob/master/week%204/30-06-2020%20Tue%23Task/Task8.2%20node-red%20dashboard%20installation/13.png)
![alt text](https://github.com/AI-MOO/IoT_LAB/blob/master/week%204/30-06-2020%20Tue%23Task/Task8.2%20node-red%20dashboard%20installation/14.png)
![alt text](https://github.com/AI-MOO/IoT_LAB/blob/master/week%204/30-06-2020%20Tue%23Task/Task8.2%20node-red%20dashboard%20installation/15.png)
![alt text](https://github.com/AI-MOO/IoT_LAB/blob/master/week%204/30-06-2020%20Tue%23Task/Task8.2%20node-red%20dashboard%20installation/16.png)
![alt text](https://github.com/AI-MOO/IoT_LAB/blob/master/week%204/30-06-2020%20Tue%23Task/Task8.2%20node-red%20dashboard%20installation/17.png)
![alt text](https://github.com/AI-MOO/IoT_LAB/blob/master/week%204/30-06-2020%20Tue%23Task/Task8.2%20node-red%20dashboard%20installation/18.png)
![alt text](https://github.com/AI-MOO/IoT_LAB/blob/master/week%204/30-06-2020%20Tue%23Task/Task8.2%20node-red%20dashboard%20installation/19.png)
![alt text](https://github.com/AI-MOO/IoT_LAB/blob/master/week%204/30-06-2020%20Tue%23Task/Task8.2%20node-red%20dashboard%20installation/21.png)
![alt text](https://github.com/AI-MOO/IoT_LAB/blob/master/week%204/30-06-2020%20Tue%23Task/Task8.2%20node-red%20dashboard%20installation/22.png)
![alt text](https://github.com/AI-MOO/IoT_LAB/blob/master/week%204/30-06-2020%20Tue%23Task/Task8.2%20node-red%20dashboard%20installation/23.png)
![alt text](https://github.com/AI-MOO/IoT_LAB/blob/master/week%204/30-06-2020%20Tue%23Task/Task8.2%20node-red%20dashboard%20installation/24.png)
![alt text](https://github.com/AI-MOO/IoT_LAB/blob/master/week%204/30-06-2020%20Tue%23Task/Task8.2%20node-red%20dashboard%20installation/25.png)
![alt text](https://github.com/AI-MOO/IoT_LAB/blob/master/week%204/30-06-2020%20Tue%23Task/Task8.2%20node-red%20dashboard%20installation/26.png)
![alt text](https://github.com/AI-MOO/IoT_LAB/blob/master/week%204/30-06-2020%20Tue%23Task/Task8.2%20node-red%20dashboard%20installation/27.png)
![alt text](https://github.com/AI-MOO/IoT_LAB/blob/master/week%204/30-06-2020%20Tue%23Task/Task8.2%20node-red%20dashboard%20installation/28.png)


**your dashboard is ready to be connected with ESP8266**
![alt text](https://github.com/AI-MOO/IoT_LAB/blob/master/week%204/30-06-2020%20Tue%23Task/Task8.2%20node-red%20dashboard%20installation/29.png)

**STEP2: Open MQTT.FX and enter the Broker address and Broker Port as shown in the image below:**

![alt text](https://github.com/AI-MOO/IoT_LAB/blob/master/week%204/30-06-2020%20Tue%23Task/Task8.2%20node-red%20dashboard%20installation/30.png)


**STEP3: Connect and Subscribe to the following topics [you can change them to any topics you want but you have to respectively modify ESP8266 code ]:**
![alt text](https://github.com/AI-MOO/IoT_LAB/blob/master/week%204/30-06-2020%20Tue%23Task/Task8.2%20node-red%20dashboard%20installation/31.png)



**STEP4: Make the connection as shown in the image below  LED_Green = [GPIO5 (pin D1)]  LED_Blue [GPIO2 (pin D4)] Steam Sensor [pin s to Pin A0], [Pin + to 3v , Pin - to Ground ]**

![alt text](https://github.com/AI-MOO/IoT_LAB/blob/master/week%204/30-06-2020%20Tue%23Task/Task8.2%20node-red%20dashboard%20installation/32.png)

**STEP5: download ESP code and modify ssid and password to your network connection information moreover, if you have any modifications I highlighted and made some comments to modifiable parts**

![alt text](https://github.com/AI-MOO/IoT_LAB/blob/master/week%204/30-06-2020%20Tue%23Task/Task8.2%20node-red%20dashboard%20installation/33.png)
![alt text](https://github.com/AI-MOO/IoT_LAB/blob/master/week%204/30-06-2020%20Tue%23Task/Task8.2%20node-red%20dashboard%20installation/34.png)
![alt text](https://github.com/AI-MOO/IoT_LAB/blob/master/week%204/30-06-2020%20Tue%23Task/Task8.2%20node-red%20dashboard%20installation/35.png)
![alt text](https://github.com/AI-MOO/IoT_LAB/blob/master/week%204/30-06-2020%20Tue%23Task/Task8.2%20node-red%20dashboard%20installation/36.png)

**STEP6: Run the code and trigger the switches on node-red dashboard and observe steam sensor behavior**
![alt text](https://github.com/AI-MOO/IoT_LAB/blob/master/week%204/30-06-2020%20Tue%23Task/Task8.2%20node-red%20dashboard%20installation/37.png)
![alt text](https://github.com/AI-MOO/IoT_LAB/blob/master/week%204/30-06-2020%20Tue%23Task/Task8.2%20node-red%20dashboard%20installation/38.png)
