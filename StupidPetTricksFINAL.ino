int analogPin = A0;    // potentiometer in A0
int ledPin13 = 13;     // LED1 in dig pin 13
int ledPin11 = 11;     // LED1 in dig pin 11
int ledPin9 = 9;       // LED1 in dig pin 9
int ledPin7 = 7;       // LED1 in dig pin 7
int ledPin5 = 5;       // LED1 in dig pin 5
int ledPin4 = 4;       // LED1 in dig pin 4
int ledPin3 = 3;       // LED1 in dig pin 3
int trick1 = 699;      // trick1 at 699 so I can set it to trigger <
int trick2 = 700;      // trick2 at 700 so I can set it to trigger >
int off = 0;           // tried to make this work but no success

void setup() {
  pinMode(analogPin, INPUT);   // potentiometer is the input
  pinMode(ledPin13, OUTPUT);   //indicates led13 is an output
  pinMode(ledPin11, OUTPUT);   //indicates led11 is an output
  pinMode(ledPin9, OUTPUT);    //indicates led9 is an output
  pinMode(ledPin7, OUTPUT);    //indicates led7 is an output
  pinMode(ledPin5, OUTPUT);    //indicates led5 is an output
  pinMode(ledPin4, OUTPUT);    //indicates led4 is an output
  pinMode(ledPin3, OUTPUT);    //indicates led3 is an output
  Serial.begin(9600);          //so I can see the voltage number
}

void loop() {
  int analogValue = analogRead(analogPin); //analogreads the voltage on potentiometer
  /*code below makes the lights blink all at once if the analog value
    is between 0 - 699 */
  if (analogValue <= trick1) {
    //turns on all the LEDS
    digitalWrite(ledPin13, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin11, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin9, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin7, HIGH);
    delay(100);
    // turns off all the LEDS after 100 ms delay
    digitalWrite(ledPin13, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin11, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin9, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin7, LOW);
    delay(100);
    
  } 
  /*code below makes the lights light up in sequence if the analog value
    is between 700 - 1023; each light has a 100 ms delay */
  if (analogValue >= trick2) {
    digitalWrite(ledPin13, HIGH);
    delay(100);
    digitalWrite(ledPin11, HIGH);
    delay(100);
    digitalWrite(ledPin13, LOW);
    delay(100);
    digitalWrite(ledPin9, HIGH);
    delay(100);
    digitalWrite(ledPin11, LOW);
    delay(100);
    digitalWrite(ledPin7, HIGH);
    delay(100);
    digitalWrite(ledPin9, LOW);
    delay(100);
    digitalWrite(ledPin5, HIGH);
    delay(100);
    digitalWrite(ledPin7, LOW);
    delay(100);
    digitalWrite(ledPin4, HIGH);
    delay(100);
    digitalWrite(ledPin5, LOW);
    delay(100);
    digitalWrite(ledPin3, HIGH);
    delay(100);
    digitalWrite(ledPin4, LOW);
    delay(100);
    digitalWrite(ledPin3, LOW);
    delay(50);
  } 
 
  Serial.println(analogValue);    // writes what the voltage is for reference
  delay(1);
}

