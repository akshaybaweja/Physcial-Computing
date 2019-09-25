/*
   If button is pressed for 3 seconds, one LED should light up.
   If button is pressed for 6 seconds, another LED should light up.
   If a button is pressed and held for 6 seconds and a second button is pressed, make the LED do some special behavior.
   Explore combining behaviors.
   How many different LED behaviors can you get out of just two switches and measuring how long they're pressed?
*/

#define LED1 5
#define LED2 6
#define BTN1 2
#define BTN2 3

long time;
bool ledState = false;

void setup() {
  // pin definitions
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);

  time = millis();

  Serial.begin(115200);
}

void loop() {
  if (digitalRead(BTN1) == 1) {
    Serial.println("BTN1 is not pressed");
    time = millis();
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
  } else {
    Serial.println("BTN1 is pressed");
  }

  if (millis() - time > 3000) {
    Serial.println("BTN1 is pressed for 3s");
    digitalWrite(LED1, HIGH);
  }

  if (millis() - time > 6000) {
    Serial.println("BTN1 is pressed for 6s");
    digitalWrite(LED2, HIGH);
    if (digitalRead(BTN2) == 0) {
      Serial.println("BTN2 is pressed");
      blinky();
    }
  }
}

void blinky(){
  if(ledState){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    delay(500);
  } else {
    digitalWrite(LED2, LOW);
    digitalWrite(LED2, HIGH);
    delay(500);
  }
  ledState = !ledState;
}
