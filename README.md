# HPatternShift
Shifting with H Patern gearboxes. incl. Clutch automation

# *********************************************************************************************
# Project Developed by @carbon_GTV , support me on instagram, also donations are very welcome!
# https://www.paypal.com/donate/?hosted_button_id=97RF22P434J84
# *********************************************************************************************

### Paddleshift Control for H-Pattern Gearbox

#### Completed Arduino Code
The code controls a pneumatic clutch and two servo motors for gear shifting. Each gear and the neutral position are individually adjustable. A digital output indicates the engaged gear.

#### Parts List
1. **Arduino Uno**: Control unit of the system.
2. **PCA9685 PWM Driver Board**: For controlling the servo motors.
3. **Pneumatic Cylinder**: For actuating the clutch.
4. **3/2-Way Valve**: For controlling the pneumatic cylinder.
5. **Servo Motors**: Two pieces, for gear shifting.
6. **Pushbuttons**: For neutral position.
7. **Paddles**: Two pieces, for upshifting and downshifting.
8. **Relay Module**: For controlling the pneumatic valve.
9. **Compressed Air Source**: Compressor or compressed air tank.
10. **Hoses and Connectors**: For connecting the valve, cylinder, and compressed air source.
11. **Pressure reducer**: for the outlet of the pneumatic cluch cylinder, so you can slowly engage the cluch

# Videos
You need all the parts you see here:
https://www.instagram.com/reel/C0_A3zPI9OU/?utm_source=ig_web_copy_link&igsh=MzRlODBiNWFlZA==
and those you see here:
https://www.instagram.com/reel/CylktuAssMe/?utm_source=ig_web_copy_link&igsh=MzRlODBiNWFlZA==


#### Connection Plan
- **Pneumatic Clutch**:
  - To Pin 2 of the Arduino.
- **Digital Output for Engaged Gear**:
  - To Pin 3 of the Arduino.
- **Neutral Position Pushbutton**:
  - To Pin 4 of the Arduino.
  - Reverse Gear button to Pin 7 of the Arduino.
- **Paddles**:
  - Upshift to Pin 5 of the Arduino.
  - Downshift to Pin 6 of the Arduino.
- **Servo Motors**:
  - Connected to the PCA9685 PWM driver board.
- **Relay Module**:
  - For controlling the pneumatic valve.

#### Installing and Setting Up the Arduino IDE
1. **Download and Install Arduino IDE**: Visit the [official Arduino website](https://www.arduino.cc/en/software) and download the Arduino IDE for your operating system. Follow the installation instructions.
2. **Connect Arduino Uno**: Connect the Arduino Uno to your computer using a USB cable.
3. **Install Drivers**: Your operating system should automatically install the necessary drivers. If not, you can find the drivers on the Arduino website.
4. **Launch Arduino IDE**: Open the Arduino IDE.
5. **Select Board and Port**: Under `Tools` -> `Board`, select your Arduino Uno. Then, under `Tools` -> `Port`, choose the port to which your Arduino is connected.
6. **Upload Code**: Copy the provided code into the Arduino IDE. Click the Upload button to transfer the code to your Arduino Uno.

#### Additional Notes
- **Safety and Testing**: Ensure that all components are correctly connected, and the power supply is adequate. Test the system carefully.
- **Calibration**: Adjust the delay times and servo positions in the code to suit your specific needs.

With this guide, you should be able to install and operate your Paddleshift system for an H-pattern gearbox.
