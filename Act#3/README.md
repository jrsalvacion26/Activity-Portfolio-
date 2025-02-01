# Arduino Basic Sensor

## Code Explanation:


1. Global Variables:
+ potPin, thermistorPin, ldrPin, buzzerPin:
   * These store the pins where the potentiometer, thermistor, LDR, and buzzer are connected to the microcontroller (likely an Arduino).
+ potValue, tempValue, lightValue, temperatureThreshold:
   * These store the analog readings from the potentiometer, thermistor, and LDR, as well as the calculated temperature threshold.

2. setup() Function:
+ Serial.begin(9600):
    * Initializes the serial communication at a baud rate of 9600 bits per second. This allows the Arduino to send data to the Serial Monitor.
+ pinMode(buzzerPin, OUTPUT): TV a
    * Sets the buzzer pin as an output, allowing the microcontroller to control the buzzer.


3. loop() Function:
+ Analog Reads:

    * potValue = analogRead(potPin): Reads the value from the potentiometer (range 0-1023) and stores it in potValue.
    * tempValue = analogRead(thermistorPin): Reads the value from the thermistor (temperature sensor) and stores it in tempValue.
    * lightValue = analogRead(ldrPin): Reads the light level from the LDR and stores it in lightValue.


+ Temperature Threshold Calculation:
    * temperatureThreshold = map(potValue, 0, 1023, 0, 100): Maps the potentiometer value (range 0-1023) to a range of 0-100. This value will be used as a temperature threshold for triggering the buzzer.
Temperature Mapping:
    *int temperature = map(tempValue, 0, 1023, -40, 125): Maps the thermistor value (range 0-1023) to a temperature range of -40 to 125°C, assuming the thermistor is calibrated to this range.

+ Temperature Mapping:
    * int temperature = map(tempValue, 0, 1023, -40, 125): Maps the thermistor value (range 0-1023) to a temperature range of -40 to 125°C, assuming the thermistor is calibrated to this range.
 

+ Buzzer Control:

    * if (temperature >= temperatureThreshold): Checks if the temperature is greater than or equal to the threshold set by the potentiometer. If so, it adjusts the buzzer:
    * int buzzerFrequency = map(lightValue, 0, 1023, 100, 2000): Maps the LDR value (light level) to a frequency range of 100Hz to 2000Hz. This will be the frequency of the buzzer.
    * tone(buzzerPin, buzzerFrequency): Generates a tone at the mapped frequency on the buzzer.
* else: If the temperature is lower than the threshold, it turns off the buzzer using noTone(buzzerPin).
