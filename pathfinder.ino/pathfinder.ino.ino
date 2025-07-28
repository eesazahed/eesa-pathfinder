int BUT1 = D0;
int BUT2 = D1;
int BUT3 = D2;
int BUT4 = D7;

int LED1 = D3;
int LED2 = D4;
int LED3 = D5;
int LED4 = D6;

unsigned long pressStart = 0;
bool longPressActive = false;

void setup() {
  pinMode(BUT1, INPUT_PULLUP);
  pinMode(BUT2, INPUT_PULLUP);
  pinMode(BUT3, INPUT_PULLUP);
  pinMode(BUT4, INPUT_PULLUP);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void loop() {
  digitalWrite(LED1, digitalRead(BUT1) == LOW ? HIGH : LOW);
  digitalWrite(LED2, digitalRead(BUT2) == LOW ? HIGH : LOW);
  digitalWrite(LED3, digitalRead(BUT3) == LOW ? HIGH : LOW);

  if (digitalRead(BUT4) == LOW && pressStart == 0) {
    pressStart = millis();
  }
  if (digitalRead(BUT4) == HIGH && pressStart != 0) {
    unsigned long pressDuration = millis() - pressStart;
    pressStart = 0;
    if (pressDuration > 2000 && !longPressActive) {
      longPressActive = true;
      patternMode();
      longPressActive = false;
    }
  }
}

void patternMode() {
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  delay(300);

  for (int i = 0; i < 3; i++) {
    digitalWrite(LED1, HIGH); delay(150);
    digitalWrite(LED1, LOW);  delay(50);
    digitalWrite(LED2, HIGH); delay(150);
    digitalWrite(LED2, LOW);  delay(50);
    digitalWrite(LED3, HIGH); delay(150);
    digitalWrite(LED3, LOW);  delay(50);
    digitalWrite(LED4, HIGH); delay(150);
    digitalWrite(LED4, LOW);  delay(50);

    digitalWrite(LED3, HIGH); delay(150);
    digitalWrite(LED3, LOW);  delay(50);
    digitalWrite(LED2, HIGH); delay(150);
    digitalWrite(LED2, LOW);  delay(50);
    digitalWrite(LED1, HIGH); delay(150);
    digitalWrite(LED1, LOW);  delay(50);
  }

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
}
