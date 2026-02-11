int pinLED = 4;
int pinBUT = 1;
int pinMOT = 9;
int pinENC = 2;
unsigned long timeStart = 0;
unsigned long timeStop = 0;
//bool ledState = LOW;           // Stato attuale del LED
bool lastButtonState = HIGH;    // Ultimo stato del pulsante
bool currentButtonState = LOW; // Stato corrente del pulsante
bool stateEncover = LOW;
int pinVel = A0;
int v;
int imp = 0;
float s;
float rps;
float rpm;
float count = 0;
float more;
float time;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLED, OUTPUT);
  pinMode(pinBUT, INPUT);
  pinMode(pinMOT, OUTPUT);
  pinMode(pinENC, INPUT);
  Serial.begin(115200);
}

void loop() {
  timeStart = millis();
  timeStop = timeStart + 1000;  // 1 secondo

//  currentButtonState = digitalRead(pinBUT);
  
/*  if (digitalRead(pinBUT) == HIGH && lastButtonState != currentButtonState){
    ledState = !ledState;
    digitalWrite(pinLED, ledState);
    // delay per evitare problemi
    delay(100);
    if(ledState){
    for(int rm = 0; rm <= 255; rm++){
      analogWrite(pinMOT, rm);
      delay(50) ;
    }
    }else{
    for(int rm = 255; rm >= 0; rm -- ){
      analogWrite(pinMOT, rm);
      delay (50);
    }
    }
  }
  lastButtonState = currentButtonState; */ 

  if(digitalRead(pinBUT) == HIGH && currentButtonState != lastButtonState){   // cambiare stato attuale di currentButton State
    currentButtonState = !currentButtonState;
    lastButtonState = !lastButtonState;
    
  }

  if(currentButtonState == HIGH){      // posso cambiare la velocità tramite potenziometro solo currentButtonState == HIGH
    v = map(analogRead(pinVel), 0, 1023, 0, 255);
    analogWrite(pinLED, v);
    analogWrite(pinMOT, v);
  }else{
    while(v >= 0){
      analogWrite(pinMOT, v);
      analogWrite(pinLED, v);
      
      --v;
    }
  }  

  if(currentButtonState){
  while(millis() < timeStop){ // impulsi in 1 secondo
    if(digitalRead(pinENC)){
      ++imp;
      ++count;
      while(digitalRead(pinENC));
    }
  }
 
  more = millis(); 

  while(count < 20){
    if(digitalRead(pinENC) && digitalRead(pinENC) != stateEncover){
      ++count;
      stateEncover = digitalRead(pinENC);
    }
    time = millis() - more;
    stateEncover = digitalRead(pinENC);  
  }
  
  s = imp;
  rps = imp/20;
  rpm = rps*60;
  imp = 0;
  count = 0;
 
 
  
  
  Serial.print(" rps = ");  // rotazioni al secondo
  Serial.print(rps);
  Serial.print(" rpm = ");  // rotazioni al minuto
  Serial.print(rpm);
  Serial.print(" tempo un giro = ");
  Serial.print(time);
  Serial.println(" ");
  
  }

  delay(1);
}
