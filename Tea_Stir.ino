#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
 
const int SERVO = 3;const int STIR_UP = 160;const int STIR_HIGH = 130;const int STIR_LOW = 90; 
int STIR_SMOOTH = 50;
const int STATUS_LED=5;const int POWER_LED=4;const int BUTTON=6;const int TIME_POT=A5;const int BUZZER=8; 

void setup(){// Set up LED pins

	pinMode(STATUS_LED, OUTPUT);pinMode(POWER_LED, OUTPUT);
  
	digitalWrite(POWER_LED, HIGH);digitalWrite(STATUS_LED, LOW);
  
	myservo.attach(SERVO);myservo.write(STIR_UP); 
  
	pinMode(BUZZER, OUTPUT);digitalWrite(BUZZER, LOW); } 
	
bool isButtonPressed() {return (digitalRead(BUTTON) ? false : true);}
//When the button is pressed, the TIMER_BUTTON pin is connected to ground and thus reads LOW.
//Alternatively, when the button is not pressed the pin is connected to 5v through the resistor and reads HIGH

long getStirringTime() {

//Get analog value from potentiometer (range 0-1023), re-base between 0 and 10 and multiply by 60*1000 to get the //time in milliseconds.

	float time = mapFloat(analogRead(TIME_POT), 0, 1023, 0, 10);
	Serial.println(time); long millisTime = (long)(time*60*1000);return millisTime;}
	
float mapFloat(float x, float in_min, float in_max, float out_min, float out_max) {

//Helper function used to re-map an number from one range to another. We don't use the native 'map' because it //only returns integers. 

	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;}

void moveServo(int startPosition, int stopPosition) {
	int pos;
	
	if (startPosition > stopPosition) {
		for(pos = startPosition; pos >= stopPosition; pos -= 1)     // goes from STIR_HIGH to UP since it's the last position atteigned in stir(){myservo.write(pos);delay(STIR_SMOOTH);}       }               
	else {
		for(pos = startPosition; pos <= stopPosition; pos += 1)     // goes from STIR_HIGH to UP since it's the last position atteigned in stir(){myservo.write(pos);delay(STIR_SMOOTH);}}}                       

void stir() {moveServo(STIR_HIGH, STIR_LOW);moveServo(STIR_LOW, STIR_HIGH);}

void beepBuzzer() {tone(BUZZER, 3136, 1000);delay(2000);tone(BUZZER, 3136, 1000);}

void startStirring(long duration) {
/*
Moves servo from 'high' to stirring position and begin process. We keep track of the time 
that each stirring cycle took and subtract it to the duration passed as argument. 
When duration<0, we move the servo to 'high' position agin so that the tea bag is taken out from the cup. 
Two beeps are played by the buzzer and the status led is shut to indicate end of stirring. 
*/
	unsigned long referenceTime;
	
	moveServo(STIR_UP, STIR_HIGH);digitalWrite(STATUS_LED, HIGH);
	
	while(duration>0) {referenceTime = millis();stir();duration-= millis() - referenceTime;}
	
	moveServo(STIR_HIGH, STIR_UP);beepBuzzer();digitalWrite(STATUS_LED, LOW);}

void loop(){long duration = getStirringTime();if (isButtonPressed()){startStirring(duration);}}
