int left_forward = 3;                 // pin that moves the left motor forward
int left_backward = 5;                // pin that moves the right motor forward
int right_forward = 6;                // pin that moves the left motor backward
int right_backward = 9;               // pin that moves the right motor backward
int sensor_2 = 8;                     // this is a pin for the right sensor
int sensor_1 = 7;                     // this is a pin for the left sensor
int send = 13;                        // this pin is the one attached to the trigpin of the ultrasound sensor
int recieve = 12;                     // this pin is attached to the echo pin of the ultra sound sensor
long distance;                        
int button = 11;                      // this is the pin of the switch 
int forward_speed = 80;                        
int backward_speed = 63;                        

void forward(int speed)                        // function to run both the motors forward
{
  analogWrite(right_forward, speed);  
  analogWrite(left_forward, speed);
  analogWrite(left_backward, 0);
  analogWrite(right_backward, 0);
}

void backward(int speed)                       // to run both the motors backward
{
  analogWrite(right_forward, 0);
  analogWrite(left_forward, 0);
  analogWrite(left_backward, speed);
  analogWrite(right_backward, speed);
}

void right_for()                      // to run the right forward at low speed
{                                     // and the left at full speed
  analogWrite(right_forward, 100);
  analogWrite(left_forward, 255);
  analogWrite(left_backward, 0);
  analogWrite(right_backward, 0);
}

void right(int speed)                          // to turn the bot right
{                                     
  analogWrite(right_forward, 0);
  analogWrite(left_forward, speed);
  analogWrite(left_backward, 0);
  analogWrite(right_backward, 0);
}

void left_for()                       // to run the left forward at low speed
{                                     // and the right at full speed
  analogWrite(right_forward, 255);
  analogWrite(left_forward, 100);
  analogWrite(left_backward, 0);
  analogWrite(right_backward, 0);
}

void left (int speed)                          // to turn the bot left
{
  analogWrite(right_forward, speed);
  analogWrite(left_forward, 0);
  analogWrite(left_backward, 0);
  analogWrite(right_backward, 0);
}

void halt()                            // to stop the bot
{
  analogWrite(right_forward, 0);
  analogWrite(left_forward, 0);
  analogWrite(left_backward, 0);
  analogWrite(right_backward, 0);
}

long measure_distance()               // to measure the distance from the ultrasound sensor 
{
  digitalWrite(send, LOW);
  delay(2);
  digitalWrite(send, HIGH);
  delay(5);
  digitalWrite(send, LOW);
  long duration = pulseIn (recieve, HIGH);
  return duration / 29 / 2; 
}

void line_follow()                     // function for the line following bot
{
  if (digitalRead(sensor_1) && digitalRead(sensor_2))
  {
    forward(forward_speed);
  }
  else if (!digitalRead(sensor_1) && digitalRead(sensor_2))
  {
    left(63);
  }
  else if (digitalRead(sensor_1) && !digitalRead(sensor_2))
  {
    right(63);
  }
  else if (!digitalRead(sensor_1) && !digitalRead(sensor_2))
  {
    halt();
  }
}

void ostracle_avoiding()                  // function for the obstacle avoiding bot
{
  Serial.println(measure_distance());
  if (measure_distance() <= 40)
  {
    halt();
    delay(500);
    backward(backward_speed);
    delay(500);
    halt();
    delay(500);
    left(127);
    delay(250);
  }
  else
  {
    forward(127);
  }
}

void setup() 
{
  pinMode(left_forward, OUTPUT);  
  pinMode(left_backward, OUTPUT);  
  pinMode(right_forward, OUTPUT);  
  pinMode(right_backward, OUTPUT);  
  pinMode(sensor_1, INPUT);
  pinMode(sensor_2, INPUT);
  pinMode(recieve, INPUT);
  pinMode(send, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(button))
  {
    line_follow();
  }
  else
  {
    ostracle_avoiding();
  }
}
