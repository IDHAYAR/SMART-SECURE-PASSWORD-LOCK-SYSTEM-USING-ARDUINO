# *Smart Secure : Password Lock System*

Conventional mechanical locks are no longer sufficient for modern security needs. They are prone to tampering and key duplication, making them less reliable for safeguarding homes and offices. The need for an advanced system that reduces these risks and offers keyless entry through a simple password-based mechanism becomes essential in improving security.

The primary objective of the password-based Smart Door Lock System is to enhance the security of doors by enabling access control through password authentication. The system is designed to allow or restrict access based on a pre-programmed password. It should also be able to lock the door automatically.

## *Introduction*

In this project, we used an Arduino and a keypad to create a password-based security system. Thefts are becoming more common by the day, therefore security is becoming a serious worry. As a result, a smart lock with a digital code can simply secure our home, business, locker, and other valuables. It only unlocks a door when the correct password is supplied. 

Due to a password-based door lock mechanism, only authorized personnel are permitted access to the restricted areas. The Arduino is in charge of the project's overall operation. A 4×4 keypad can be used to input the necessary password.

## *Motivation*
The motivation behind developing a Password-Based Smart Door Lock System stems from the need for a more secure and convenient alternative to conventional mechanical locks. Traditional locks can be easily picked or duplicated, and often, their security depends heavily on the physical key's safekeeping. 

In contrast, a smart door lock system mitigates these issues by incorporating electronic components, which can offer features such as password protection, limited access attempts, and remote management, thus improving overall security and user control.

## *Applications*
- Enhancing home security by replacing traditional locks.
- Restricting access to sensitive areas within an office environment.
- Securing entry points in retail stores, warehouses, and other commercial spaces.
- Integrating with other smart home devices for a comprehensive security solution. 
- In hotels, keyless entry for guests using pre-assigned passwords for rooms.
- In Educational Institutions, used for secure access to restricted areas like server rooms or storage facilities.


## *Advantages*
- Eliminates the risk of lost or duplicated keys.
- Offers a more affordable solution compared to biometric systems.
- Simple password entry method for unlocking doors. Configurable to lock automatically after a preset duration.
- Can be integrated with mobile apps for remote password changes.



## *Limitations*
- Forgetting them can lead to lockout issues.
- The initial setup cost might be higher compared to traditional locks.
- Requires regular maintenance and updates to ensure the system functions correctly. 

**System Circuit Diagram**
| :--: |
![CIRCUIT DIAGRAM](https://github.com/user-attachments/assets/59e58dd5-9de6-4753-9500-9f7e680ad5cf)

## *Components Used*
- TINKERCAD Software
- Arduino Uno R3
- Breadboard
- Keypad 4 X 4
- Red LED
- Buzzer
- Micro Servo
- Potentiometer
- Resistor
- LCD 16 X 2

## *Algorithm for Password Lock System Circuit*
``` ruby
1) Set up the Arduino Uno and configure all components.
2) Continuously monitor the keypad and potentiometer for inputs.
3) Count the number of incorrect attempts from the keypad.
4) After too many incorrect attempts, activate the buzzer.
5) Based on correct input, control the LED, display information on the LCD, and adjust the servo motor using the potentiometer.
6) Repeat the process continuously for real-time interaction.

```

## *Operating Mechanism of Password Lock System*
``` ruby
Step 1 - Initialize the system with a predefined password.
Step 2 - Continuously monitor and retrieve the user's password input.
Step 3 - Compare the entered password with the predefined one.
Step 4 - If correct, unlock the system, light up the LED, and activate the servo motor.
Step 5 - If incorrect, lock the system and, after several wrong attempts, trigger the buzzer.
Step 6 - Repeat the process in a continuous loop to ensure real-time operation.

```

## *Results*

![Screenshot 2024-09-19 144551](https://github.com/user-attachments/assets/d1709a80-9c89-4a41-8049-dc599c474e45)
| :--: |
**WELCOMING MESSAGE WHEN THE SYSTEM IS STARTED**

![Screenshot 2024-09-19 144609](https://github.com/user-attachments/assets/5d396466-7441-4cf1-a572-c5a231d959e9)
| :--: |
**INSTRUCTED TO ENTER PASSWORD**

![Screenshot 2024-09-19 144632](https://github.com/user-attachments/assets/9ea1f0fb-04c3-49ef-9ddf-396cf824b365)
| :--: |
**WHEN THE PASSWORD MATCHES, IT SHOWS THE MESSAGE “DOOR IS OPEN” & THE LED IS GLOWING**

![Screenshot 2024-09-19 144833](https://github.com/user-attachments/assets/f39f3fc2-2651-46a0-98f7-6b689f2f2622)
| :--: |
**INSTRUCTED TO PRESS # TO CLOSE THE DOOR**

![Screenshot 2024-09-19 144901](https://github.com/user-attachments/assets/3bc23849-5377-4686-a36c-b64a84236682)
| :--: |
**AFTER PRESSING #, IT SHOWS THE MESSAGE “DOOR IS CLOSED”**

![Screenshot 2024-09-19 144923](https://github.com/user-attachments/assets/144ffbdf-466d-48d2-af88-610a80d78129)
| :--: |
**IT SHOWS THE MESSAGE “WRONG PASSWORD!” WHEN WRONG PASSWORD IS ENTERED**

![Screenshot 2024-09-19 144950](https://github.com/user-attachments/assets/15d2beaa-e41c-4593-b257-0b120a4318d7)
| :--: |
**INSTRUCTED TO TRY AGAIN**

![Screenshot 2024-09-19 145012](https://github.com/user-attachments/assets/d23e4744-60b7-4987-99cd-9d0744e5a1e7)
| :--: |
**IT SHOWS THE MESSAGE “TOO MANY ATTEMPTS!” WHEN MAXIMUM ATTEMPTS REACHED**

![Screenshot 2024-09-19 145220](https://github.com/user-attachments/assets/cde01114-c85e-40a9-bfcf-9c8f9f56463e)
| :--: |
**AFTER “TOO MANY ATTEMPTS!” , IT SHOWS THE MESSAGE “TRY AGAIN LATER” & THE BUZZER ALARMS TO INDICATE IT**

## *Conclusion*
The password-based Smart Door Lock System offers an effective and simple way to enhance security in homes and offices. It eliminates the need for traditional keys, providing a more secure and convenient method of access control.

## *Future scope*
- The future scope of the Password-Based Door Lock System encompasses a wide range of technological advancements and integrations. 
- By incorporating IoT capabilities, biometric authentication, voice control, and AI, the system can significantly enhance security, convenience, and user experience. 
- As technology continues to evolve, the Password-Based Door Lock System will likely become an integral part of smart and secure living environments.

  
## *References*
- https://how2electronics.com/password-based-security-system-arduino-keypad/
- https://circuitdigest.com/microcontroller-projects/digital-keypad-security-door-lock-using-arduino

