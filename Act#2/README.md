# Code Explanation:

1. setup():
* The setup() function runs once at the start of the program.
* It initializes each pin in pinArray[] as an OUTPUT to control the LEDs.

2. Loop():
* The first for loop fades each LED in by calling fadeLED(pin, true).
* The second for loop fades each LED out by calling fadeLED(pin, false).

3. fadeLED():
* Parameters:
 + pin: The pin number where the LED is connected.
 + fadeIn: A boolean that specifies whether the LED should fade in (true) or fade out (false).
