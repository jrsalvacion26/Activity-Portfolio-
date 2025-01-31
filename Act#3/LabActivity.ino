int potPin = A0; 
int thermistorPin = A1; 
int ldrPin = A2; 
int buzzerPin = 9; 

int potValue = 0;
int tempValue = 0;
int lightValue = 0;
int temperatureThreshold = 0;

void setup() {
  Serial.begin(9600); 
  pinMode(buzzerPin, OUTPUT); 
}

void loop() {

  potValue = analogRead(potPin); 
  tempValue = analogRead(thermistorPin); 
  lightValue = analogRead(ldrPin); 

  temperatureThreshold = map(potValue, 0, 1023, 0, 100);

  int temperature = map(tempValue, 0, 1023, -40, 125); 

  Serial.print("Potentiometer Value (Threshold): ");
  Serial.println(temperatureThreshold);
  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.print("Light Level: ");
  Serial.println(lightValue);

  if (temperature >= temperatureThreshold) {

    int buzzerFrequency = map(lightValue, 0, 1023, 100, 2000);
    tone(buzzerPin, buzzerFrequency);
  } else {
    noTone(buzzerPin);
  }

  delay(500); 
}
