int sensePin = A0;
int ledPin = 9;
int ledPressPin= 8;
int pressPin = A2;
void setup () {

  Serial.begin(9600);
  pinMode (ledPin, OUTPUT);
  pinMode (ledPressPin, OUTPUT); 

}

void loop () {

  //Serial.println (analogRead (sensePin));
  Serial. println (analogRead (pressPin));

  int valLight = analogRead (sensePin);
  int valPress= analogRead (pressPin);
  
  if (valPress > 0) digitalWrite(ledPressPin, HIGH);
  else digitalWrite (ledPressPin, LOW);
  
  valLight = constrain (valLight, 750, 900);
  int ledLevel = map (valLight, 750, 900, 255, 0);

  analogWrite (ledPin, ledLevel);

  //  if (val < 800) digitalWrite (ledPin, HIGH); 
  //  else digitalWrite (ledPin, LOW);
}

