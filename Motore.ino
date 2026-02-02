int pinLED = 1;
int pinBUT = 2;
int pinMOT = 9;
bool ledState = LOW;           // Stato attuale del LED
bool motState = LOW;
int rm;
bool lastButtonState = LOW;    // Ultimo stato del pulsante
bool currentButtonState = LOW; // Stato corrente del pulsante

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLED, OUTPUT);
  pinMode(pinBUT, INPUT);
  pinMode(pinMOT, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly
  currentButtonState = digitalRead(pinBUT);

  if (digitalRead(pinBUT) == HIGH && lastButtonState != currentButtonState){
    ledState = !ledState;
    motState = !motState;
    digitalWrite(pinLED, ledState);
    
    if(motState == HIGH){
      for(rm = 0; rm <= 255; rm++){
        analogWrite(pinMOT, rm);  // gestisce quanta corrente fornisco al motore e di conseguenza la velocità
      // analog è disponibile solo su alcuni pin ~ (tilde)
        delay(50);
      }
    }else{
      for(rm = 255; rm >= 0; rm--){
       analogWrite(pinMOT, rm);
       delay(50);
      }
    }
    // delay per evitare problemi
    delay(100);
  }
  lastButtonState = currentButtonState;
}
