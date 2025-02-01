# Recieving Serial Connection Using Arduino and Python

## Code Explanation 


### Arduino Code
1. setup()

* pinMode(13, OUTPUT):
This initializes pin 13 as an output pin, which is typically connected to the onboard LED on most Arduino boards. You can also use this pin to control an external LED.

* Serial.begin(9600):
This starts serial communication at a baud rate of 9600 bits per second. It allows the Arduino to communicate with a connected computer or other serial devices.

* Serial.println("Ready..."):
This sends an initial message to the serial monitor indicating that the program is ready and instructs the user to send commands ('1' to turn the LED on and '0' to turn it off).

2. loop()
* Serial.available() > 0:
This checks if any data is available in the serial buffer. If there is data, the program proceeds to read it.

* char command = Serial.read();
This reads the incoming byte from the serial buffer and stores it in the variable command.

+ Processing the Command:

    * If the command is '1':

        * The program turns the LED on by writing a HIGH signal to pin 13 using digitalWrite(13, HIGH).
        * The serial monitor outputs "LED is ON" to confirm the action.
    * If the command is '0':

        * The program turns the LED off by writing a LOW signal to pin 13 using digitalWrite(13, LOW).
        * The serial monitor outputs "LED is OFF" to confirm the action.
    * For any other command:

        * The program recognizes that the input is invalid and sends the message "Invalid command. Send '1' to turn ON and '0' to turn OFF." to the serial monitor.
* delay(100);
This introduces a small 100-millisecond delay to prevent flooding the serial monitor with too many messages. This also allows for a slight pause between successive serial reads and actions.


#### API



### LED


1. Serial.available() > 0:

* Purpose:
    * This checks if any data is available in the serial buffer. The serial buffer stores incoming data sent from a serial device (like a computer or another microcontroller).
  
* Explanation:
    * The function `Serial.available()` returns the number of bytes available to read from the serial buffer. If this value is greater than 0 (i.e., data is available), the program proceeds to read the incoming data. If no data is available, the program simply waits.


2. char command = Serial.read();

* Purpose:
    * This reads the incoming byte from the serial buffer and stores it in the variable `command`.

* Explanation:
    * The function `Serial.read()` reads one byte of incoming data from the serial buffer. The byte is then stored in the `command` variable as a `char` (character). This byte can be any ASCII character sent over the serial connection (in this case, typically `'1'`, `'0'`, or any other character input by the user).


3. Processing the Command:

* If the command is `'1':
    * Action:
        * The program turns the LED on by writing a `HIGH` signal to pin 13 using `digitalWrite(13, HIGH)`.
    
    * Explanation: 
        When the user sends the character `'1'`, the Arduino turns on the LED connected to pin 13 by sending a `HIGH` signal (5V). This activates the LED.

    * Serial Output:
        * The serial monitor outputs the message `"LED is ON"` to confirm the action, letting the user know that the LED has been successfully turned on.

* If the command is `'0':
    * Action:
        The program turns the LED off by writing a `LOW` signal to pin 13 using `digitalWrite(13, LOW)`.
    
    * Explanation:
        * When the user sends the character `'0'`, the Arduino turns off the LED by sending a `LOW` signal (0V) to pin 13. This deactivates the LED.

    * Serial Output:**  
        * The serial monitor outputs the message `"LED is OFF"` to confirm the action, indicating that the LED has been successfully turned off.

* For any other command:**
    * Action: 
        * If the user sends any character other than `'1'` or `'0'`, the program recognizes it as an invalid command.
    
    * Serial Output:
        * The program responds by sending the message `"Invalid command. Send '1' to turn ON and '0' to turn OFF."` to the serial monitor, instructing the user to send the correct commands for controlling the LED.


4. delay(100);

* Purpose: 
    * This introduces a small 100-millisecond delay to prevent flooding the serial monitor with too many messages.
  
* Explanation:
    * The `delay(100)` function pauses the program for 100 milliseconds before continuing to the next iteration of the loop. This helps:
  - Prevent excessive serial communication that could overwhelm the serial buffer.
  - Allow for a slight pause between successive serial reads and actions, giving the user time to see the results in the serial monitor.

