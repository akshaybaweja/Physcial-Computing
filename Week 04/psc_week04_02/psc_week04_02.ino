// Touch Sensor
#include <CapacitiveSensor.h>

#define LED 3

CapacitiveSensor cs_4_2 = CapacitiveSensor(4, 2);
void setup()
{
  pinMode(LED, OUTPUT);
}

void loop()
{
  long start = millis();
  long total1 =  cs_4_2.capacitiveSensor(30);

  if (total1 > 1900) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }

  delay(10);
}
