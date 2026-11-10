void setup() {
  for(uint8_t i=2; i<14; i++)
    pinMode(i,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  if(Serial.available()){
    char cmd=Serial.read();
    if(cmd==' '){
      delay(1000);
    }
    else if(cmd>='A'&&cmd<='Z'){
      cmd=cmd-'A'+2;
      digitalWrite(cmd,HIGH);
      Serial.print("Set pin ");
      Serial.print((uint8_t)cmd);
      Serial.println(" HIGH");
    }else if(cmd>='a'&&cmd<='z'){
      cmd=cmd-'a'+2;
      digitalWrite(cmd,LOW);
      Serial.print("Set pin ");
      Serial.print((uint8_t)cmd);
      Serial.println(" LOW");
    }
  }

}
