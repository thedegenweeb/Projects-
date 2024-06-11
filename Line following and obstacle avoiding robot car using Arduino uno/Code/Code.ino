#define csL 11 //pin of left line sensor
#define csR 12 //pin of right line sensor
int mode = A2; //pin of mode changing button
int in1 = 3; //motor 1 terminal 1
int in2 = 5; //motor 1 terminal 2
int in3 = 6; //motor 2 terminal 1
int in4 = 9; //motor 2 terminal 2
long distance; //initializing variable to store distance of ultrasonic sensor from obstacle
int pingPin = 7; //trigpin of ultrasonic sensor
int echoPin = 8; //echopin of ultrasonic sensor
int state; //variable to store value of current state of button
long measure(){ //function to measure distance between obstacle and ultrasonic sensor
digitalWrite(pingPin, LOW); //trigpin has no power i.e. no signal is send
delayMicroseconds(2); //2 microsecond delay
digitalWrite(pingPin, HIGH);//trigpin has full power i.e. a signal is send delayMicroseconds(5); //5 microsecond delay
digitalWrite(pingPin, LOW); //trigpin has no power i.e. no signal is send
long duration = pulseIn(echoPin, HIGH);//function to measure the length of pulse on echopin and store in variable
return duration / 29 / 2; // return value in centimeters
} 
void motor_fwd(int fwd_speed){ //function to move car forward
 analogWrite(in1 ,fwd_speed); //move motor 1 in forward
 analogWrite(in2 ,0); 
 analogWrite(in3 ,fwd_speed); //move motor 2 in forward
 analogWrite(in4 ,0); 
 // delay(500);
} 
void motor_back(int back_speed){ //function to move car backward 
 analogWrite(in2 ,back_speed); //move motor 1 in backward
 analogWrite(in1 ,0); 
 analogWrite(in4 ,back_speed); //move motor 2 in backward
 analogWrite(in3 ,0); 
// delay(500);
} 
void turn_right(int right_speed){ //function to turn car right
 analogWrite(in1 ,right_speed); //move motor 1 in forward
 analogWrite(in2 ,0); 
 analogWrite(in4 ,right_speed); //move motor 2 in backward
 analogWrite(in3 ,0); 
 // delay(300); 
} 
void turn_left(int left_speed){ //function to turn car left
 analogWrite(in2 ,left_speed); //move motor 1 in backward
 analogWrite(in1 ,0); 
 analogWrite(in3 ,left_speed); //move motor 2 in forward
 analogWrite(in4 ,0); 
 // delay(300); 
} 
void stop(){ //function to stop the car
 analogWrite(in2 ,0); //stop motor 1
 analogWrite(in1 ,0); 
 analogWrite(in3 ,0); //stop motor 2
 analogWrite(in4 ,0); 
 // delay(500); 
} 
void obstacle_avoiding(int speed){ //function for obstacle avoiding mode
 distance = measure(); //calling function to find the distance between car and obstacle
 Serial.println(distance); //printing the distance
 if ( distance <= 30 ){ //if distance is less than 30
 stop(); //stop the car
 delay (2000); //delay of 2 sec
 motor_back(speed); //move the car back
 delay(1000); //delay for 1 sec
 stop(); //stop the car
 delay(500); //delay for 0.5 sec
 turn_left(speed); //turn the car left
 delay(1000); //delay for 1 sec
 } 
 else{ //if distance is greater than 30
 motor_fwd(speed); //move the car forward
 } 
} 
void line_follow(int speed){ //function for line following mode
 if (!digitalRead(csL) && !digitalRead(csR)){ //if both sensor detect colour other tha black
 motor_fwd(speed); //move the car forward
 } 
 else if (!digitalRead(csL) && digitalRead(csR)){ //if right sensor detects black colour 
 turn_right(speed); //turn the car right
 } 
 else if (digitalRead(csL) && !digitalRead(csR)){ //if left sensor detects black colour
 turn_left(speed); //turn the car left
 } 
 else if (digitalRead(csL) && digitalRead(csR)){ //if both sensors detect black colour
 stop(); //stop the car
 } 
} 
void setup() { //function to set pins and Arduino setting
 pinMode(pingPin, OUTPUT); //set pingpin to output  pinMode(csL, INPUT); //set csL pin to input
 pinMode(csR, INPUT); //set csR pin to input
 pinMode(mode, INPUT); //set mode pin to input
 Serial.begin(9600); //serial.begin to write analog functions
} 
void loop() { //loop to follow 
 Serial.println(analogRead(mode)); //printing button state
 // delay(1000);
 state = analogRead(mode); //storing value of mode in state
 if (state > 1000){ //if state is greater than 1000 i.e. button is ON
 obstacle_avoiding(127); //Makes the car obstacle avoiding
 Serial.println("1"); //print 1
 } 
 else{ //if state is less than 1000 i.e. button is OFF
 line_follow(127); //Makes the car line following
 Serial.println("0"); //print 0
 } 
}