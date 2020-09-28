# Transformers Load Monitoring
## Monitoring Transformers Load with Arduino.

**With this project you can make a prototype consisting of 3 phase transformer and monitor their loads.**

* If you can't access 3 phase transformer you can 3 single phase transformers.
* After testing this project you can use it on 3 phase transformer without any problem.

I'm assuming you know how to make a 3 phase transformer out of 3 single phase ones.

After creating the 3 phase transformer, do the following:
1. Fix Arduino UNO/MEGA, Transformers and Components (Wires, ACS712 Sensor, LM7805 Regulator, Connectors) on a Board.
2. Connect 3 ACS712 Pins together and then to Arduino's GND.
3. Connect Sensor's VCC to Arduino 5V.
4. Connect the Output Pins to Arduino Analog Pins.
5. Use different color wires to know which Transformer is which.

* Monitoring application is designed in VB.