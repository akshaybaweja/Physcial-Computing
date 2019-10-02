#define LED_PIN 3

float ledValue;

void setup() {
  ledValue = 0;

  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
    ledValue = 108.3 * (exp(sin(millis() / 2000.0*PI) - 0.36787944));
    analogWrite(LED_PIN, int(ledValue));
}
