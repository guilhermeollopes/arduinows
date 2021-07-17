#include <Arduino.h>

#define rele 3
#define buz 4
#define ledSta 5
#define ledOn 6
#define ledAque 7
#define ledOk 8
#define ledResf 9
#define btnStart 10
#define btnTestBuz 11

int status = 0;
int testBuz = 0;

void setup() {
    //Definição das Saidas
  pinMode(rele, OUTPUT);
  pinMode(buz, OUTPUT);
  pinMode(ledOn, OUTPUT);
  pinMode(ledSta, OUTPUT);
  pinMode(ledAque, OUTPUT);
  pinMode(btnStart, INPUT_PULLUP);
  pinMode(btnTestBuz, INPUT_PULLUP);

  //Iniciando Sistema
  digitalWrite(ledSta, HIGH);
  tone(buz, 2000);
  delay(100);
  noTone(buz);
  digitalWrite(rele, LOW);
}

void loop() {
  if (digitalRead(btnStart) == LOW && status == 0) {
    digitalWrite(ledSta, LOW);
    digitalWrite(ledOn, HIGH);
    digitalWrite(rele, HIGH);
    digitalWrite(ledAque, HIGH);
    digitalWrite(ledOk, LOW);
    digitalWrite(ledResf, LOW);

    tone(buz, 2000);
    delay(100);
    noTone(buz);

    delay(180000);
    digitalWrite(ledAque, LOW);
    digitalWrite(ledOk, HIGH);
    digitalWrite(ledResf, LOW);
    tone(buz, 2000);
    delay(500);
    noTone(buz);
    delay(200);
    tone(buz, 2000);
    delay(500);
    noTone(buz);
    delay(200);
    tone(buz, 2000);
    delay(500);
    noTone(buz);
    delay(10);
    status = 1;

  }
  if (digitalRead(btnStart) == LOW && status == 1) {
    digitalWrite(ledOn, LOW);
    digitalWrite(rele, LOW);
    digitalWrite(ledAque, LOW);
    digitalWrite(ledOk, LOW);
    digitalWrite(ledResf, HIGH);

    tone(buz, 2000);
    delay(100);
    noTone(buz);

    delay(180000);
    digitalWrite(ledAque, LOW);
    digitalWrite(ledOk, LOW);
    digitalWrite(ledResf, LOW);
    digitalWrite(ledSta, HIGH);
    tone(buz, 2000);
    delay(1000);
    noTone(buz);
    delay(10);
    status = 0;
  }
  if (digitalRead(btnTestBuz) == LOW && testBuz == 0) {
    tone(buz, 2000);
    testBuz = 1;
    delay(500);
  }
  if (digitalRead(btnTestBuz) == LOW && testBuz == 1) {
    noTone(buz);
    testBuz = 0;
    delay(500);
  }
}
