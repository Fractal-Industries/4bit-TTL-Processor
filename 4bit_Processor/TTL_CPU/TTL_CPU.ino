/*

Connectioins (from most significant bit to least):
Input A: 5, 4, 3, 2
Input B: 9, 8, 7, 6
ALU Output: 13, 12, 11, 10

*/

uint8_t A, B, Out;
unsigned int i;

void setup() {
  for(i=2;i<10;i++)
    pinMode(i, OUTPUT);
  for(i=10;i<14;i++)
    pinMode(i, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, OUTPUT);
  Serial.begin(9600);
}

void TestValue(unsigned int testDelay){
  digitalWrite(2, A&1);
  digitalWrite(3, (A>>1)&1);
  digitalWrite(4, (A>>2)&1);
  digitalWrite(5, (A>>3)&1);

  digitalWrite(6, B&1);
  digitalWrite(7, (B>>1)&1);
  digitalWrite(8, (B>>2)&1);
  digitalWrite(9, (B>>3)&1);

  delay(testDelay);

  Serial.print((A>>3)&1);
  Serial.print((A>>2)&1);
  Serial.print((A>>1)&1);
  Serial.print(A&1);
  Serial.print("+");
  Serial.print((B>>3)&1);
  Serial.print((B>>2)&1);
  Serial.print((B>>1)&1);
  Serial.print(B&1);
  Serial.print("=");
  //Serial.print(digitalRead(13));
  Serial.print(digitalRead(12));
  Serial.print(digitalRead(11));
  Serial.print(digitalRead(10));
  Serial.print("    ");
  Serial.print(analogRead(A0));
  Serial.print("  ");
  Serial.println(digitalRead(A0));
}

void TestTransistor(unsigned int testDelay){
  digitalWrite(A1, LOW);
  delay(testDelay);
  Serial.print(digitalRead(A0)); 
  Serial.print(" ");
  Serial.println(analogRead(A0));
  digitalWrite(A1, HIGH);
  delay(testDelay);
  Serial.print(digitalRead(A0)); 
  Serial.print(" ");
  Serial.println(analogRead(A0));
}

void loop() {
  char command=0;
  if(Serial.available())
    command=Serial.read();
  switch(command){
    case 's':
      for(i=0;i<20;i++)
        Serial.println("");
      for(A=0;A<4;A++){
        for(B=0;B<4;B++){
          TestValue(100);
          delay(200);
        }
      }
      break;
    case 't':
      Serial.println("");
      Serial.println("");
      TestTransistor(100);
    default:
      break;
  }
}
