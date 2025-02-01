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

1. Startup Event:

* @app.on_event("startup"): This decorator registers a function that will run when the FastAPI application starts up (i.e., when the server starts).

* serial.Serial('COM5', 9600, timeout=1): This opens a serial connection to the Arduino. The 'COM5' refers to the serial port the Arduino is connected to (on Windows). The baud rate is set to 9600, and a timeout of 1 second is applied for reading/writing to the serial port.

* time.sleep(2): This introduces a 2-second delay to give the Arduino time to initialize before attempting communication.

* Exception Handling: If the serial connection cannot be established, an exception (serial.SerialException) will be caught, and an error message will be printed.

2. Shutdown Event:

* @app.on_event("shutdown"): This decorator registers a function that will run when the FastAPI application shuts down (i.e., when the server is stopped).

* arduino.close(): If the serial connection is open, this will close the connection when the app shuts down to properly release the serial port.

#### API ENDPOINTS

1. LED ON:
* @app.post("/led/on"): This defines a POST endpoint at /led/on which turns the LED on.

* arduino.write(b'1'): This sends the byte b'1' over the serial connection to the Arduino. The Arduino is programmed to turn the LED on when it receives this command.

+ Response:
    * If the serial connection is open, the LED is turned on and the response will be {"status": "success", "message": "LED turned ON"}.
    * If the serial connection is not open, the response will indicate an error: {"status": "error", "message": "Serial connection is not open."}.


2. LED OFF

* @app.post("/led/off"): This defines a POST endpoint at /led/off which turns the LED off.

* arduino.write(b'0'): This sends the byte b'0' over the serial connection to the Arduino. The Arduino is programmed to turn the LED off when it receives this command.

+ Response:

    * If the serial connection is open, the LED is turned off and the response will be {"status": "success", "message": "LED turned OFF"}.
    * If the serial connection is not open, the response will indicate an error: {"status": "error", "message": "Serial connection is not open."}.

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

