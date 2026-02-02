int pinLED = 1;
int pinBUT = 2;

bool ledState = LOW;           // Stato attuale del LED
bool lastButtonState = LOW;    // Ultimo stato del pulsante
bool currentButtonState = LOW; // Stato corrente del pulsante

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLED, OUTPUT);
  pinMode(pinBUT, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly
  currentButtonState = digitalRead(pinBUT);

  if (digitalRead(pinBUT) == HIGH && lastButtonState == LOW){
    ledState = !ledState;
    digitalWrite(pinLED, ledState);
    delay(100); // per evitare il debuncing 
  }
  lastButtonState = currentButtonState;
}
