#define LED_PIN 3
#define SENSOR A0

unsigned int current_time;
float ease_time, ledValue;
boolean pauseCode;

void setup() {
  ease_time = 2500.0;
  current_time = 0;
  ledValue = 0;
  pauseCode = false;

  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  current_time = millis();
  ledValue = sin(2 * PI / ease_time * current_time);
  
  if (analogRead(SENSOR) > 600) {
    digitalWrite(LED_PIN, LOW);
    pauseCode = false;
  }

  if (!pauseCode && ledValue > 0.0) {
    Serial.println(ledValue);

    if (ledValue > 0.0) {
      ledValue = 255 * ledValue;
      analogWrite(LED_PIN, int(ledValue));
      Serial.println("\tDONE!");
    }

    if (int(round(ledValue * 10) / 10) == 255) {
      pauseCode = true;
    }
  }
}
