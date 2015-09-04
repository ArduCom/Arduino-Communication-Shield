int yonB = 10;
int yonA = 9;
int motorPwmB = 2;
int motorPwmA = 3;



void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);


  pinMode(yonB, OUTPUT);
  pinMode(yonA, OUTPUT);
  pinMode(motorPwmA, OUTPUT);
  pinMode(motorPwmB, OUTPUT);
  pinMode(motorPwmB, OUTPUT);
  analogWrite(motorPwmA, 0);
  analogWrite(motorPwmB, 0);

}

void ileri()
 {
              //    Serial.println("ileri"); 
                  analogWrite(motorPwmA, 255);
                  analogWrite(motorPwmB, 255);
                  digitalWrite(yonA, LOW);
                  digitalWrite(yonB, LOW);
                  delay(100);
                  analogWrite(motorPwmA, 128);
                  analogWrite(motorPwmB, 128); 
             //     Serial.println("ileri");   
 }
 void geri()
 {
              //    Serial.println("geri"); 
                  analogWrite(motorPwmA, 255);
                  analogWrite(motorPwmB, 255);
                  digitalWrite(yonA, HIGH);
                  digitalWrite(yonB, HIGH);
                  delay(100);
                  analogWrite(motorPwmA, 128);
                  analogWrite(motorPwmB, 128); 
              //    Serial.println("geri");   
 }

void loop() {
  digitalWrite(5, HIGH);ileri();
  delay(1000);
  digitalWrite(5, LOW);geri();
  delay(1000);


  Serial.print("Analog 0 \t");
  Serial.println(analogRead(0));
  Serial.print("Analog 1 \t");
  Serial.println(analogRead(1));
}
