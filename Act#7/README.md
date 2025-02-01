# SENDING SERIAL CONNECTION USING ARDUINO AND PYTHON

## CODE EXPLANATION:

### Arduino Code (LabActivity.ino)

1. Pin Setup:
* buttonPin = 12: This defines the pin connected to the button (pin 12 in this case).
* INPUT_PULLUP: This sets the pin mode to input with an internal pull-up resistor enabled. The button will be pulled HIGH by default and will go LOW when pressed.
2. Debouncing Logic:
* Debouncing is used to eliminate false readings caused by the mechanical noise of button presses. When the button state changes, the code waits for a short period (debounce delay) to ensure the button press is stable.
* debounceDelay = 50: Sets the debounce delay to 50 milliseconds.
* millis(): A function that returns the number of milliseconds since the Arduino started running.
3. State Change Detection:

* The current button state is compared with the previous state to detect changes.
* If a change is detected, the debounce timer (lastDebounceTime) is reset.
4. Serial Output:
* After the debounce delay passes, if the button is pressed (LOW due to the pull-up resistor), the program sends "1" to the serial monitor.
* If the button is not pressed, it sends "0".
5. State Update:
* After each loop, the lastButtonState is updated to the current state for use in the next iteration.

### Python Code

1. Pin Setup:
* buttonPin = 12:
* This defines the pin number that is connected to the button. In this case, the button is connected to pin 12.

+ INPUT_PULLUP:
    * This sets the pin mode of buttonPin to INPUT_PULLUP. The internal pull-up resistor is enabled on the pin, which means the pin will read as HIGH by default (when the button is not pressed). When the button is pressed, it connects the pin to ground (GND), making it read as LOW.

2. Debouncing Logic:
+ Debouncing:
    * Debouncing is used to eliminate false readings that can occur due to the mechanical "bounce" when pressing or releasing a button. When the button is pressed, the physical contacts inside can cause multiple state changes in a very short time, which could result in false readings. This logic ensures that only stable, meaningful state changes are processed.

+ debounceDelay = 50:
    * This sets the debounce delay to 50 milliseconds. This delay is used to ignore any additional state changes within this time window after the button state has changed. It prevents the program from reacting to noise or bouncing during the button press.

+ millis():
    * This is a built-in Arduino function that returns the number of milliseconds since the program started running. It’s used here to keep track of when the button state last changed and to implement the debounce delay.

3. State Change Detection:
* The program compares the current button state with the previous button state to detect any changes. This is crucial for determining when the button has been pressed or released.

* If a state change is detected, the debounce timer (lastDebounceTime) is reset. This ensures that any false triggers within the debounce period are ignored.

4. Serial Output:
+ After the debounce delay has passed, the program checks whether the button is pressed or not:

    * If the button is pressed (i.e., the pin reads LOW due to the internal pull-up resistor), the program sends "1" to the serial monitor.
    * If the button is not pressed, the program sends "0" to the serial monitor.
This allows you to track the state of the button in real-time via the serial monitor.

5. State Update:
* After each loop iteration, the lastButtonState is updated to the current button state. This ensures that the state of the button is correctly recorded for comparison in the next loop cycle.
