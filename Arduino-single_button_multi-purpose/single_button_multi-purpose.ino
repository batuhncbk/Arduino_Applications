
const int ledPin = 6;         
const int buttonPin = 10;


int buttonState = 0;  
int deger=0;

void setup() {
  
  pinMode(ledPin, OUTPUT);    
  pinMode(buttonPin, INPUT);  
}

void loop() {

  buttonState = digitalRead(buttonPin); 

  if ((buttonState == HIGH) && (deger==0))
  {          
    digitalWrite(ledPin, HIGH);          
  deger=1;
  delay(10);
  }
  if ((buttonState == LOW) && (deger==1))
  {           
    digitalWrite(ledPin, LOW);          
  deger=2;
  delay(10);
  }
  if ((buttonState == HIGH) && (deger==2))
  {          
    digitalWrite(ledPin, HIGH);        
  deger=0;
  delay(10);
  }

}
