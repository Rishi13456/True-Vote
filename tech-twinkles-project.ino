int buzzer=22;

void setup() {
  projectInit();
}

void loop() {
  if(Serial.available()){
    rfidFlag=1;
    String rfidData="";
    buzzerControl("on");
    delay(2000);
    while(Serial.available()){
      char c=Serial.read();
      rfidData+=c;
      delay(10);
    }
    buzzerControl("off");
    Serial.print("#");
    Serial.print(",");
    Serial.print(rfidData);
    Serial.print(",");
    Serial.println("~");
  }   
}

void projectInit(){
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void buzzerControl(String a){
  if(a=="on"){
    digitalWrite(buzzer,1);
  } else if(a=="off"){
    digitalWrite(buzzer,0);
  }
}
