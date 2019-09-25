// CLAP SWITCH

#define LED 3
#define CLAP_SENSE A0

bool ledState = false;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(CLAP_SENSE);
  if (sensorValue > 230)
    ledState = !ledState;
  digitalWrite(LED, ledState);
}
