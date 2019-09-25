#define LED 3
#define LDR A0

bool ledState = false;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(LDR);
  analogWrite(LED, map(sensorValue, 0, 1023, 0, 255));
}
