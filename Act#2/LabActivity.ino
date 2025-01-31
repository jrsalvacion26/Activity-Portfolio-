int pinArray[] = {3, 5, 6, 9, 10};  
int brightnessLevel = 0;
int fadeValue = 5;
int pointer = 0;

void setup() {
  for (pointer = 0; pointer < 5; pointer++) {
    pinMode(pinArray[pointer], OUTPUT);
  }
}

void loop() {
  for (pointer = 0; pointer < 5; pointer++) {
    fadeLED(pinArray[pointer], true);   
  }
  
  for (pointer = 0; pointer < 5; pointer++) {
    fadeLED(pinArray[pointer], false);  
  }
}

void fadeLED(int pin, bool fadeIn) {
  int brightnessLevel = (fadeIn) ? 0 : 255;  
  int fadeValue = (fadeIn) ? 5 : -5;  

  while ((fadeIn && brightnessLevel <= 255) || (!fadeIn && brightnessLevel >= 0)) {
    analogWrite(pin, brightnessLevel);      
    brightnessLevel += fadeValue;           
    delay(20);                          

    if (brightnessLevel < 0 || brightnessLevel > 255) break;
  }
}
