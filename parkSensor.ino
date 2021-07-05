
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPinr = 13;
const int ledPing = 8;
const int ledPiny = 7;

// defines variables
long duration;
int distance;
int safetyDistance;


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(ledPinr, OUTPUT);
pinMode(ledPiny, OUTPUT);
pinMode(ledPing, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}


void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

safetyDistance = distance;
 if (safetyDistance <= 5){
      digitalWrite(buzzer, HIGH);
      digitalWrite(ledPinr, HIGH);
      digitalWrite(ledPiny, LOW);
      digitalWrite(ledPing, LOW);
    }
    else if(safetyDistance <=10){
      digitalWrite(buzzer, HIGH);
      digitalWrite(ledPiny, HIGH);
      digitalWrite(ledPing, LOW);
      digitalWrite(ledPinr, LOW);
      delay(50);
      digitalWrite(buzzer, LOW);
      digitalWrite(ledPiny, LOW);
      digitalWrite(ledPing, LOW);
      digitalWrite(ledPinr, LOW);
      delay(50);
      }
    else if(safetyDistance <=15){
      digitalWrite(buzzer, HIGH);
      digitalWrite(ledPiny, HIGH);
      digitalWrite(ledPing, LOW);
      digitalWrite(ledPinr, LOW);

      delay(100);
      digitalWrite(buzzer, LOW);
      digitalWrite(ledPiny, LOW);
      digitalWrite(ledPing, LOW);
      digitalWrite(ledPinr, LOW);
      delay(100);
      }
    else if(safetyDistance <=20){
      digitalWrite(buzzer, HIGH);
      digitalWrite(ledPing, HIGH);
      digitalWrite(ledPiny, LOW);
      digitalWrite(ledPinr, LOW);
      delay(150);
      digitalWrite(buzzer, LOW);
      digitalWrite(ledPing, LOW);
      digitalWrite(ledPiny, LOW);
      digitalWrite(ledPinr, LOW);
      delay(150);
      }
    else{
      digitalWrite(buzzer, LOW);
      digitalWrite(ledPinr, LOW);
      digitalWrite(ledPiny, LOW);
      digitalWrite(ledPing, LOW);
      
    }

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}
