#include <Servo.h>

int led = 10;
int servoPin = 9;
int trigger = 11;
int echo = 12;
int dist = 0;

Servo servoMotor;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);

  servoMotor.attach(servoPin);
}

void loop() {
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  
  dist = pulseIn(echo, HIGH);
  dist = dist / 58;
  
  Serial.println("Distancia = " + String(dist) + "cm");
 
  if (Serial.available() > 0) {
    char comando = Serial.read();

    if (comando == 'M') {
      servoMotor.write(180);
    } else if (comando == 'L') {
      servoMotor.write(90);
    } else if (comando == 'R') {
      servoMotor.write(0);
    } else if (comando == 'A') {
      digitalWrite(led, HIGH);
    } else if (comando == 'B') {
      digitalWrite(led, LOW);
    }
  }
  Serial.println(dist);
  delay(2000);
}
