int led1 = 7;
int led2 = 8;
int led3 = 12;

int led4 = 2;
int led5 = 4;
int led6 = 13;


void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led1, HIGH);
  digitalWrite(led6, HIGH);
  delay(10000);
  digitalWrite(led1, LOW);
  delay(10);
  digitalWrite(led2, HIGH);
  delay(1000);
    for (int i = 0; i<3;i++){
    digitalWrite(led2, HIGH);
    delay(500);
    digitalWrite(led2, LOW);
    delay(500);
  }
  digitalWrite(led2, LOW);
  digitalWrite(led6, LOW);
  delay(10);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  delay(10000);
  digitalWrite(led4, LOW);
  delay(10);
  digitalWrite(led5, HIGH);
  delay(20);
  for (int i = 0; i<3;i++){
    digitalWrite(led5, HIGH);
    delay(500);
    digitalWrite(led5, LOW);
    delay(500);
  }
  digitalWrite(led3, LOW);
  digitalWrite(led5, LOW);
  delay(10);
}