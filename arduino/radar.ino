#include <Servo.h>

#define echo 3
#define trig 2
#define servoPin 9

// Creating Servo Object using Servo Library to deal with servo motor
Servo servo;

int distance;
int duration;

void setup() {
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  // Attaching servo to a pin
  servo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  // Looping up to 180 to make servo motor rotate 180 degrees, deg by deg. and calculating distance at each degree
  for (int i = 0; i < 180; i++) {
    servo.write(i);
    delay(30);
    distance = calculateDistance()

    // Printing/Sending current degree and distance in the form (currentDeg,Distance.) for formatting in processing
    Serial.print(i); // Degree
    Serial.print(",");
    Serial.print(distance); // Current Distance
    Serial.print(".")
  }

  // Looping from 180 to 0 to return back to original point and repeat
  for (int i = 180; i > 0; i--) {
    servo.write(i);
    delay(30);
    distance = calculateDistance()

    // Printing/Sending current degree and distance in the form (currentDeg,Distance.) for formatting in processing
    Serial.print(i); // Degree
    Serial.print(",");
    Serial.print(distance); // Current Distance
    Serial.print(".")
  }
}

int calculateDistance() {
  // Sets trigger on sensor to low to stop sending waves
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  // Then setting it to high to start sending waves
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  // After 10ms, Set trigger to low again to stop sending waves and start calculating
  digitalWrite(trig, LOW);

  // Requesting echo to start reading waves travel time
  duration = pulseIn(echo, HIGH);

  // Calculating distance using speed * time, dividing by 2 because pulseIn returns the total duration for both going and returning back
  distance = (duration * 0.0343) / 2;

  return distance;
}
