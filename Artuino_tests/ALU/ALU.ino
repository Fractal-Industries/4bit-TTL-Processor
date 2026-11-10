uint8_t A, B, Amax=15, Bmax=15, Out, Sum;

void setup() {
  Serial.begin(9600);
  for(A=2;A<10;A++)
    pinMode(A,OUTPUT);
  for(A=10;A<14;A++)
    pinMode(A,INPUT);
  pinMode(A0,INPUT);
  delay(5000);
}


void loop() {
  delay(2000);
  Serial.print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  for(A=0;A<=Amax;A++){
    for(B=0;B<=Bmax;B++){
      digitalWrite(2,A>>3);
      digitalWrite(3,(A>>2)&1);
      digitalWrite(4,(A>>1)&1);
      digitalWrite(5,A&1);
      Serial.print(A>>3);
      Serial.print((A>>2)&1);
      Serial.print((A>>1)&1);
      Serial.print(A&1);
      Serial.print(" + ");
      digitalWrite(6,B>>3);
      digitalWrite(7,(B>>2)&1);
      digitalWrite(8,(B>>1)&1);
      digitalWrite(9,B&1);
      Serial.print(B>>3);
      Serial.print((B>>2)&1);
      Serial.print((B>>1)&1);
      Serial.print(B&1);
      Serial.print(" = ");
      //delay(500);
      //delay(1000);
      Serial.print(digitalRead(A0));
      Serial.print(digitalRead(10));
      Serial.print(digitalRead(11));
      Serial.print(digitalRead(12));
      Serial.print(digitalRead(13));
      Out=digitalRead(A0)<<4;
      Out|=digitalRead(10)<<3;
      Out|=digitalRead(11)<<2;
      Out|=digitalRead(12)<<1;
      Out|=digitalRead(13);
      Serial.print("  ");
      Serial.print(Out);
      Sum=A+B;
      if(Sum==Out)
        Serial.println("  ok");
      else{
        Serial.print("  WRONG (");
        Serial.print(Sum);
        Serial.println(")");
      }
    }
    Serial.println("");
  }
}
