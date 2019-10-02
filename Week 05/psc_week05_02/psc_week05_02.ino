#define LED_PIN 3
#define SENSOR A0

boolean flag;

void setup() {
  flag = false;

  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  if (analogRead(SENSOR) > 600) {
    digitalWrite(LED_PIN, LOW);
    delay(500);
    flag = true;
  }

  if (flag){
    for (float i = 0.00; i < 1.57; i += 0.05) {
      analogWrite(LED_PIN, int(255 * sin(i)));
      delay(100);
    }
    flag = false;
  }
}