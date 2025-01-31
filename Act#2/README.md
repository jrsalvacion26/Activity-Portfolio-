# Code Explanation:

1. setup():
* The setup() function runs once at the start of the program.
* It initializes each pin in pinArray[] as an OUTPUT to control the LEDs.

2. Loop():
* The first for loop fades each LED in by calling fadeLED(pin, true).
* The second for loop fades each LED out by calling fadeLED(pin, false).

3. fadeLED():
* Parameters:
 * + pin: The pin number where the LED is connected.
 * + fadeIn: A boolean that specifies whether the LED should fade in (true) or fade out (false).

The function gradually increases or decreases the brightnessLevel of the LED, stepping by fadeValue (5 for fading in, for fading out). The analogWrite() function is used to set the LED brightness, and the function uses a 20ms delay to control the speed of the fade effect.
 
