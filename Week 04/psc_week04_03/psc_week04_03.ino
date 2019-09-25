//POTENTIOMETER CONTROLLED BLINKING

#define LED 3
#define POT A0

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(POT);
  blink(sensorValue);
}

void blink(int sensorValue){
  digitalWrite(LED, HIGH);
  delay(sensorValue);
  digitalWrite(LED, LOW);
  delay(sensorValue);
}
