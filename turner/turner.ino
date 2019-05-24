int pinLedSol = 7;
int pinLedOrta = 6;
int pinLedSag = 5;

int delayTime = 300;
char gelenData, sonData;

void setup() {
  pinMode(pinLedSol, OUTPUT);
  pinMode(pinLedOrta, OUTPUT);
  pinMode(pinLedSag, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    gelenData = Serial.read();
    if (gelenData != sonData) sonData = gelenData;
  }

  if (sonData == '0') {
    digitalWrite(pinLedSol, LOW);
    digitalWrite(pinLedOrta, LOW);
    digitalWrite(pinLedSag, LOW);
  }
  else if (sonData == '1') {
    digitalWrite(pinLedOrta, LOW);
    
    digitalWrite(pinLedSol, HIGH);
    delay(delayTime);
    digitalWrite(pinLedSol, LOW);
    delay(delayTime);
  }
  else if (sonData == '2') {
    digitalWrite(pinLedOrta, HIGH);
  }
  else if (sonData == '3') {
    digitalWrite(pinLedOrta, LOW);
    
    digitalWrite(pinLedSag, HIGH);
    delay(delayTime);
    digitalWrite(pinLedSag, LOW);
    delay(delayTime);
  }

  delay(30);
}
