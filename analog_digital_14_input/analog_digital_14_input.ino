////////////////////////////
//12 INPUTS,  1 BREADBOARD//
//ANALOG:                 //
//  MOISTURE1:         A0 //
//  MOISTURE2:         A1 //
//  VIBRATION1:        A2 //
//  VIBRATION2:        A3 //
//  PHOTORESISTOR*:    A4 //
//DIGITAL*:               //
//  FSR1:              12 //
//  FSR2:              11 //  
//  FSR3:              10 //
//  TILT:              09 //
//  PB1:               08 //
//  PB2:               07 //
//  PB3:               06 //
//  PB4:               05 //
//  PB5:               04 //
//*10K OHM RESISTOR NEEDED//
////////////////////////////

//what's in the digital pins
const int FSR1Pin = 12;     
const int FSR2Pin = 11;
const int FSR3Pin = 10;
const int TILTPin = 9;
const int PB1Pin = 8;
const int PB2Pin = 7;
const int PB3Pin = 6;
const int PB4Pin = 5;
const int PB5Pin = 4;

//relative digital test LEDs
const int FSR1ledPin =  13;      
const int FSR2ledPin =  13;
const int FSR3ledPin =  13;
const int TILTledPin =  3;
const int PB1ledPin =  2;
const int PB2ledPin =  2;
const int PB3ledPin =  2;
const int PB4ledPin =  1;
const int PB5ledPin =  1;

//what's in the analog pins
const int moistureIn1 = A0;
const int moistureIn2 = A1;
const int vibrationIn1 = A2;
const int vibrationIn2 = A3;
const int photoresistorIn1 = A4;

//relative output pins
const int analogOutPin0 = 0;
const int analogOutPin1 = 0;
const int analogOutPin2 = 0;
const int analogOutPin3 = 0;
const int analogOutPin4 = 0;


//the variables that will change for digital
int FSR1State = 0;
int FSR2State = 0;
int FSR3State = 0;
int TILTState = 0;
int PB1State = 0;
int PB2State = 0;
int PB3State = 0;
int PB4State = 0;
int PB5State = 0;

//the variables that will change for analog
int moisture1ReadValue = 0;       
int moisture2ReadValue = 0;
int vibration1ReadValue = 0;
int vibration2ReadValue = 0;
int photoresistor1ReadValue = 0;

int moisture1OutputValue = 0;
int moisture2OutputValue = 0;
int vibration1OutputValue = 0;
int vibration2OutputValue = 0;
int photoresistor1OutputValue = 0;
int photoresistor15OutputValue = 0;


void setup() {
  
//initialise serial communications at 9600 bps:
Serial.begin(9600);


//initialising the LEDs as the digital outputs
  pinMode(FSR1ledPin, OUTPUT);
  pinMode(FSR2ledPin, OUTPUT);
  pinMode(FSR3ledPin, OUTPUT);
  pinMode(TILTledPin, OUTPUT);
  pinMode(PB1ledPin, OUTPUT);
  pinMode(PB2ledPin, OUTPUT);
  pinMode(PB3ledPin, OUTPUT);
  pinMode(PB4ledPin, OUTPUT);
  pinMode(PB5ledPin, OUTPUT);

// initialising the different digital inputs
  pinMode(FSR1Pin, INPUT);
  pinMode(FSR2Pin, INPUT);
  pinMode(FSR3Pin, INPUT);
  pinMode(TILTPin, INPUT);
  pinMode(PB1Pin, INPUT);
  pinMode(PB2Pin, INPUT);
  pinMode(PB3Pin, INPUT);
  pinMode(PB4Pin, INPUT);
  pinMode(PB5Pin, INPUT);
  
}


void loop() {

//read the state of the digital inputs
  FSR1State = digitalRead(FSR1Pin);
  FSR2State = digitalRead(FSR2Pin);
  FSR3State = digitalRead(FSR3Pin);
  TILTState = digitalRead(TILTPin);
  PB1State = digitalRead(PB1Pin);
  PB2State = digitalRead(PB2Pin);
  PB3State = digitalRead(PB3Pin);
  PB4State = digitalRead(PB4Pin);
  PB5State = digitalRead(PB5Pin);

//read the value of the analog inputs
  moisture1ReadValue = analogRead(moistureIn1);
  moisture2ReadValue = analogRead(moistureIn2);
  vibration1ReadValue = analogRead(vibrationIn1);
  vibration2ReadValue = analogRead(vibrationIn2);
  photoresistor1ReadValue = analogRead(photoresistorIn1);

//map the analog input to a certain range  
  moisture1OutputValue = map(moisture1ReadValue, 0, 1023, 21, 60);
  moisture2OutputValue = map(moisture2ReadValue, 0, 1023, 61, 100);
  vibration1OutputValue = map(vibration1ReadValue, 0, 1023, 101, 140);
  vibration2OutputValue = map(vibration2ReadValue, 0, 1023, 141, 180);
  photoresistor1OutputValue = map(photoresistor1ReadValue, 0, 1023, 181, 210);
  photoresistor15OutputValue = map(photoresistor1ReadValue, 0, 1023, 211, 240);

//change the analog out value:
  analogWrite(analogOutPin0, moisture1OutputValue);
  analogWrite(analogOutPin1, moisture2OutputValue);
  analogWrite(analogOutPin2, vibration1OutputValue);
  analogWrite(analogOutPin3, vibration2OutputValue);
  analogWrite(analogOutPin4, photoresistor1OutputValue);


//change the state of the digital inputs
//FSR1
if (FSR1State == HIGH) {
    // turn LED on:
    digitalWrite(FSR1ledPin, HIGH);
    Serial.write(1);
  } else {
    // turn LED off:
    digitalWrite(FSR1ledPin, LOW);
    Serial.write(0);
  }

//FSR2
  if (FSR2State == HIGH) {
    // turn LED on:
    digitalWrite(FSR2ledPin, HIGH);
    Serial.write(3);
  } else {
    // turn LED off:
    digitalWrite(FSR2ledPin, LOW);
    Serial.write(2);
  }

//FSR3
  if (FSR3State == HIGH) {
    // turn LED on:
    digitalWrite(FSR3ledPin, HIGH);
    Serial.write(5);
  } else {
    // turn LED off:
    digitalWrite(FSR3ledPin, LOW);
    Serial.write(4);
  }

//TILT
  if (TILTState == HIGH) {
    // turn LED on:
    digitalWrite(TILTledPin, HIGH);
    Serial.write(7);
  } else {
    // turn LED off:
    digitalWrite(TILTledPin, LOW);
    Serial.write(6);
  }

//PB1
  if (PB1State == HIGH) {
    // turn LED on:
    digitalWrite(PB1ledPin, HIGH);
    Serial.write(9);
  } else {
    // turn LED off:
    digitalWrite(PB1ledPin, LOW);
    Serial.write(8);
  }

//PB2
  if (PB2State == HIGH) {
    // turn LED on:
    digitalWrite(PB2ledPin, HIGH);
    Serial.write(11);
  } else {
    // turn LED off:
    digitalWrite(PB2ledPin, LOW);
    Serial.write(10);
  }

//PB3
  if (PB3State == HIGH) {
    // turn LED on:
    digitalWrite(PB3ledPin, HIGH);
    Serial.write(13);
  } else {
    // turn LED off:
    digitalWrite(PB3ledPin, LOW);
    Serial.write(12);
  }
  
//PB4
  if (PB4State == HIGH) {
    // turn LED on:
    digitalWrite(PB4ledPin, HIGH);
    Serial.write(15);
  } else {
    // turn LED off:
    digitalWrite(PB4ledPin, LOW);
    Serial.write(14);
  }
  
//PB5
  if (PB5State == HIGH) {
    // turn LED on:
    digitalWrite(PB5ledPin, HIGH);
    Serial.write(17);
  } else {
    // turn LED off:
    digitalWrite(PB5ledPin, LOW);
    Serial.write(16);
  }

//Send analog results
//Moisture 1
Serial.write(moisture1OutputValue);
//Moisture 2
Serial.write(moisture2OutputValue);
//Vibration 1
Serial.write(vibration1OutputValue);
//Vibration 2
Serial.write(vibration2OutputValue);
//Photoresistor for Volume
Serial.write(photoresistor1OutputValue);
//Photoresistor for Granulation
if(photoresistor15OutputValue < 211) {
  Serial.write(210);
} else {
  Serial.write(photoresistor15OutputValue);
}

////Print results to serial monitor
////Moisture 1
//  Serial.print("moisture sensor 1 = ");
//  Serial.print(moisture1ReadValue);
//  Serial.print("\t m1output = ");
//  Serial.println(moisture1OutputValue);
//
////Moisture 2
//  Serial.print("moisture sensor 2 = ");
//  Serial.print(moisture2ReadValue);
//  Serial.print("\t m2output1 = ");
//  Serial.println(moisture2OutputValue);
//
////Vibration 1
//  Serial.print("vibration sensor 1 = ");
//  Serial.print(vibration1ReadValue);
//  Serial.print("\t v1output2 = ");
//  Serial.println(vibration1OutputValue);
//
////Vibration 2
//  Serial.print("vibration sensor 2 = ");
//  Serial.print(vibration2ReadValue);
//  Serial.print("\t v2output3 = ");
//  Serial.println(vibration2OutputValue);
//
////Photoresistor
//  Serial.print("photoresistor 1 = ");
//  Serial.print(photoresistor1ReadValue);
//  Serial.print("\t poutput4 = ");
//  Serial.println(photoresistor1OutputValue);
//
////FRS 1
//  Serial.print("FSR 1 = ");
//  Serial.println(FSR1State);
//
////FSR2
//  Serial.print("FSR 2 = ");
//  Serial.println(FSR2State);
//
////FSR3
//  Serial.print("FSR 3 = ");
//  Serial.println(FSR3State);
//
////Tilt
//  Serial.print("Tilt = ");
//  Serial.println(TILTState);
//
////PB 1
//  Serial.print("PB 1 = ");
//  Serial.println(PB1State);
//
////PB 2
//  Serial.print("PB 2 = ");
//  Serial.println(PB2State);
//
////PB 3
//  Serial.print("PB 3 = ");
//  Serial.print(PB3State);
//
////PB 4
//  Serial.print("PB 4 = ");
//  Serial.println(PB4State);
//
////PB 5
//  Serial.print("PB 5 = ");
//  Serial.println(PB5State);

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(200);
}

  

