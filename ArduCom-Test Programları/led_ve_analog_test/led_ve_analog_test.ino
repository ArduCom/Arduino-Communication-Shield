

void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);
}

void loop() {
  digitalWrite(5, HIGH);   
  delay(1000);            
  digitalWrite(5, LOW);    
  delay(1000);  


  Serial.print("Analog 0 \t");
  Serial.println(analogRead(0));
  Serial.print("Analog 1 \t");
  Serial.println(analogRead(1));
}
