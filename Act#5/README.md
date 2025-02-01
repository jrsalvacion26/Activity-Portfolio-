# Code Explanation 

1. Global Variables:
* photoResistorPin: Pin connected to the photoresistor (light sensor).
* greenLedPin, yellowLedPin, redLedPin: Pins for the green, yellow, and red LEDs, respectively.
* lowThreshold and highThreshold: Thresholds for the light intensity that determine which LED should be lit. These thresholds can be dynamically adjusted in Automatic Mode or manually set in Manual Mode.
* isAutomaticMode: A boolean indicating whether the system is in Automatic Mode (true) or Manual Mode (false).
* lastUpdateTime: A timestamp to control the interval between updates on the Serial Monitor.
* updateInterval: The interval (in milliseconds) at which to update the Serial Monitor, set to 1000ms (1 second).

2. setup() Function:
* Serial.begin(9600): Initializes serial communication with the computer, allowing data to be sent to the Serial Monitor.
* pinMode(greenLedPin, OUTPUT), pinMode(yellowLedPin, OUTPUT), pinMode(redLedPin, OUTPUT): Configures the pins connected to the LEDs as outputs so they can control the LEDs.
* turnOffAllLeds(): Turns off all the LEDs initially to ensure they start in an off state.
* Serial.println("System Initialized."): Prints a message to indicate that the system has been initialized.

3. loop() Function:
+ Light Intensity Reading:
    * int sensorValue = analogRead(photoResistorPin): Reads the analog value from the photoresistor. The value will range from 0 to 1023 based on the light level.
    * int lightIntensity = map(sensorValue, 0, 1023, 0, 100): Maps the raw sensor value to a percentage (0-100), representing the light intensity.
+ Automatic Mode:
    * If isAutomaticMode is true, the function adjustThresholdsBasedOnLight(lightIntensity) dynamically adjusts the lowThreshold and highThreshold based on the light intensity. This is used to modify the behavior of the system depending on the current lighting conditions.
+ LED and Environment Determination:
    * The function determineActiveLed(lightIntensity) checks the light intensity and lights up one of the LEDs (green, yellow, or red) based on the thresholds.
    * The function determineEnvironment(lightIntensity) returns a string indicating the environment based on the light intensity (e.g., "Cloudy", "Normal", "Bright Sunlight").
+ Serial Monitor Updates:
    * Every second, determined by if (millis() - lastUpdateTime >= updateInterval), the status (light intensity, current mode, active LED, and environment) is printed to the Serial Monitor.
+ Handle Serial Commands:
    * The function handleSerialCommands() listens for incoming serial data. It processes commands like switching between modes, and adjusting the lowThreshold and highThreshold (in Manual Mode). It also handles invalid commands and prints error messages.

4. adjustThresholdsBasedOnLight(int lightIntensity) Function:
* Dynamically adjusts the light thresholds (lowThreshold and highThreshold) depending on the current light intensity.
* If the light intensity is low (<=40), the threshold is set to a low range (0-40).
* For medium light (41-70), the threshold is set to a range between 41 and 70.
* For high light intensity (>70), it sets the thresholds to a range of 71-100.

5. determineActiveLed(int lightIntensity) Function:
+ Based on the light intensity, it determines which LED to light up:
    * Green LED: If the light intensity is between 0 and lowThreshold, indicating low light.
    * Yellow LED: If the light intensity is between lowThreshold and highThreshold, indicating normal lighting.
    * Red LED: If the light intensity is above highThreshold, indicating bright sunlight or a high light level.
* It ensures all LEDs are turned off before lighting up the relevant LED by calling turnOffAllLeds().


6. determineEnvironment(int lightIntensity) Function:
+ Returns a string representing the environment based on the light intensity:
    * "Cloudy": For low light levels (0-40%).
    * "Normal": For moderate light levels (41-70%).
    *"Bright Sunlight": For high light levels (71-100%).
* If the light intensity is out of range, it returns "Invalid Light Intensity".

7. displayStatus(int lightIntensity, String activeLed, String environment) Function:
+ Displays the system status on the Serial Monitor:
    * Prints the light intensity as a percentage.
    * Prints the current mode ("Automatic" or "Manual").
    * Prints the active LED color.
    *Prints the determined environment based on the light intensity.

8. handleSerialCommands() Function:
+ Reads and processes serial input from the user. It supports:
    * MODE AUTO: Switches to Automatic Mode.
    * MODE MANUAL: Switches to Manual Mode.
    * SET LOW [value]: Sets the lowThreshold if in Manual Mode.
    * SET HIGH [value]: Sets the highThreshold if in Manual Mode.
* If any invalid command is entered, it prints an error message.

9. turnOffAllLeds() Function:
* Ensures that all LEDs are turned off by setting the pins for all LEDs (green, yellow, red) to LOW.


