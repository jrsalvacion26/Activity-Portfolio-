
void setup() {
  pinMode(13, OUTPUT); // LED on pin 13
  Serial.begin(9600); // Start serial communication
  Serial.println("Ready. Send '1' to turn ON and '0' to turn OFF the LED.");
}

void loop() {
  // Check if there's any data available in the serial buffer
  if (Serial.available() > 0) {
    char command = Serial.read(); // Read the incoming byte
    
    // Process the command
    if (command == '1') {
      digitalWrite(13, HIGH); // Turn LED on
      Serial.println("LED is ON");
    } 
    else if (command == '0') {
      digitalWrite(13, LOW); // Turn LED off
      Serial.println("LED is OFF");
    } 
    else {
      Serial.println("Invalid command. Send '1' to turn ON and '0' to turn OFF.");
    }
    
    delay(100); // Small delay to prevent serial flooding
  }
}
