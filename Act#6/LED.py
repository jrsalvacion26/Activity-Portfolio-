import serial
import time



try:
    # Replace 'COM5' with your Arduino's port
    with serial.Serial('COM5', 9600, timeout=1) as ard:
        time.sleep(2)  # Allow Arduino to initialize       

        # Turn LED on
        ard.write(b'1')
        print("Sent command: 1")       

        # Turn LED off
        time.sleep(1)
        ard.write(b'0')
        print("Sent command: 0")



except serial.SerialException as e:
    print(f"Serial exception: {e}")

except Exception as ex:
    print(f"Unexpected error: {ex}")
