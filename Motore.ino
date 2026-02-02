int pinLED = 1;
int pinBUT = 2;
int b = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLED, OUTPUT);
  pinMode(pinBUT, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly
  
  if (digitalRead(pinBUT) == HIGH){
    if(b == 0){
      digitalWrite(pinLED, HIGH);
      b = 1;
    }else{
      digitalWrite(pinLED, LOW);
      b = 0;
    }
  }
  delay(2000);
}
