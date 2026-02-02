int pinLED = 4;
int pinBUT = 1;
int pinMOT = 9;
bool ledState = LOW;           // Stato attuale del LED
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
    digitalWrite(pinLED, ledState);
    digitalWrite(pinMOT, ledState);
    // delay per evitare problemi
    delay(100);
  }
  lastButtonState = currentButtonState;
}
