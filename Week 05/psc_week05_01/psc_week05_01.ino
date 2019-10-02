#define LED_PIN 3
#define SENSOR_PIN A0

const int threshold = 600;

float currentValue;
float targetValue;
float easingAmount;
int sensorValue;

int lastTime;
bool ledState = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);

  currentValue = 0;
  targetValue = 255;
  easingAmount = .125;

  Serial.begin(9600);
  lastTime = millis();
}

void loop() {
  //reading analog sensor value
  sensorValue = analogRead(SENSOR_PIN);
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  if (sensorValue > threshold) {

    currentValue += easingAmount * ( targetValue - currentValue );

    Serial.print("currentValue: ");
    Serial.print(currentValue);
    Serial.print("\t targetValue: ");
    Serial.println(targetValue);

    int cv = round(currentValue * 10) / 10;

    if (cv == 255) {
      targetValue = 0;
    } else if (cv == 0) {
      targetValue = 255;
    }

    analogWrite(LED_PIN, (int) currentValue);

    delay(50);

  } else {
    ledState = !ledState;

    Serial.print("LED State: ");
    Serial.println(ledState);

    digitalWrite(LED_PIN, ledState);
    delay(250);
  }

}
