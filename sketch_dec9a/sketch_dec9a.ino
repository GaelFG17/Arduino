#include <SPI.h>
#include <Servo.h>
Servo miServo;
int servoPin = 7;
int TRIG = 10;
int ECO = 9;  
int detecciones = 0;
int DURACION;
int DISTANCIA;

int ledrojo = 2;
int ledazul = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  pinMode(ledrojo,OUTPUT);
  pinMode(ledazul,OUTPUT);
  Serial.begin(9600);
  miServo.attach(servoPin);  // Inicializa el servo en el pin correspondiente
  miServo.write(20);          // Gira el servo a 0 grados al inicio
  delay(500);

}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(TRIG, HIGH);
    digitalWrite(TRIG, LOW);
    DURACION = pulseIn(ECO, HIGH);
    DISTANCIA = DURACION / 58.2;
    Serial.println(DISTANCIA);

    if (DISTANCIA <= 20 && DISTANCIA >= 0) {
      if (detecciones < 1) {
        delay(DISTANCIA * 10);
        Serial.println('1');
        detecciones++;
      }
    } else {
      Serial.print('0');
      detecciones = 0; // Reiniciar contador solo cuando no se detecta el objeto
    }
}
