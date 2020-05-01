// 업로드시 RX, TX핀을 제거하고 업로드

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);   
  pinMode(2, OUTPUT);             

//Begin Serial Monitor
  Serial.begin(9600); //블루투스 시리얼
  Serial.write("ESP8266 DEMO");
  Serial.println();            


  
}


void loop() {

  static boolean flag = true;


  if (Serial.available()) {    
    char br = Serial.read();


  switch(br){
      case '1' : //0.5초 간격으로 LED 깜박임
        for(int i=0;i<3;i++){
        digitalWrite(2, HIGH);
        digitalWrite(LED_BUILTIN, LOW);
        delay(500);
        digitalWrite(2, HIGH);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(500);
      }
      break;

      case '2' :     //3초 간격으로 깜박임
        for(int i=0;i<3;i++){
        digitalWrite(2, HIGH);
        digitalWrite(LED_BUILTIN, LOW);
        delay(3000);
        digitalWrite(2, HIGH);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(3000);
      }
      break;

      case '3' :    //누르고 있는동안 ON
        digitalWrite(2, HIGH);
        digitalWrite(LED_BUILTIN, LOW);
        delay(30);
      break;

      case '4' :    //스위치 형식의 ON/OFF
      {
        switch(flag){      
        case true:      //LED 2개가 교대로 깜박임
          digitalWrite(2, HIGH);
          digitalWrite(LED_BUILTIN, LOW);
          flag=false;
          break;
        case false:
          digitalWrite(2, HIGH);
          digitalWrite(LED_BUILTIN, HIGH);
           flag=true;
           break;
      }
      break;
      }
      
      case '5' :      
        for(int i=0;i<3;i++){
        digitalWrite(2, HIGH);
        digitalWrite(LED_BUILTIN, LOW);
        delay(500);
        digitalWrite(2, LOW);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(500);
      }
      digitalWrite(2, HIGH);
      digitalWrite(LED_BUILTIN, HIGH);
      break;
  
        case 'a' :
        digitalWrite(2, HIGH);
        digitalWrite(LED_BUILTIN, HIGH);
        break;
    }

  }

}