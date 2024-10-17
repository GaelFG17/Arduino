#include <Servo.h>

// Configurar pines
Servo miServo;
#define pinSensor 12
#define pinBuzzer 9
#define pinServo 7
#define pinLR 3
#define pinLG 2
#define pinLB 1
int detecciones = 0;
int dato; // Contador de detecciones

// Configurar pines
void setup()
{
  pinMode(pinSensor, INPUT);
  pinMode(pinBuzzer, OUTPUT);
  pinMode(pinServo, OUTPUT);
  pinMode(pinLR, OUTPUT);
  pinMode(pinLG, OUTPUT);
  pinMode(pinLB, OUTPUT);
  miServo.attach(pinServo); // Inicializa el servo en el pin correspondiente
  miServo.write(20);
  Serial.begin(9600);
}

// Ciclo repetitivo
void loop()
{
  int lectura = digitalRead(pinSensor);

  if (lectura == LOW)
  {
    if (detecciones < 1)
    {
      ledRojo();
      digitalWrite(pinServo, HIGH);
      Serial.print(1);
      detecciones++;
    }
  }

  if (lectura == HIGH)
  {
    ledVerde();
  }

  // Esperar a que se reciba el valor 2 para levantar el servo a 90 grados
  if (Serial.available() > 0)
  {
    dato = Serial.read();
    if (dato == '2')
    {
      miServo.write(120);
      delay(10000);
      miServo.write(20);
      detecciones = 0;
    }else if (dato == '3'){
      void ledRojo();
      detecciones = 0;
    }
  }
}

void ledVerde()
{
  analogWrite(pinLR, 0);
  analogWrite(pinLG, 255);
  analogWrite(pinLB, 0);
}

void ledRojo()
{
  analogWrite(pinLR, 255);
  analogWrite(pinLG, 0);
  analogWrite(pinLB, 0);
}
