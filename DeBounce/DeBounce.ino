/* Debounce sketch
 
 */

const int inputPin = 2;
const int ledPin = 13;
const int debounceDelay = 10;

void setup(){
  pinMode(inputPin, INPUT);
  pinMode(ledPin, OUTPUT);

}


void loop(){

  if(debounce(inputPin){
    digitalWrite(outPin, HIGH);
  }

}

boolean debounce(int pin){
  boolean state;
  boolean previousState;

  previousState = digitalRead(pin);
  for(int counter = 0; counter < debounceDelay; counter++){
    delay(1);
    state = digitalRead(pin);
    if(state != previousState){
      counter = 0;
      previousState = state;
    }
  }
  // here when the switch sate has been stable longer than the debounce period
  return state;
}




