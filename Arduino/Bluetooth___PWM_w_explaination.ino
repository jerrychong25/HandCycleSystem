char val;				// Value recieved via bluetooth
int direc1 = 4;			// Pin 4 - Direction of Motor 1
#define pwm1 5			// Pin 5 - Motor 1 Speed
int direc2 = 8;			// Pin 8 - Direction of Motor 2
#define pwm2 9			// Pin 9 - Motor 2 Speed
#define motor3 10		// Pin 10 - Motor 3 Speed 
int led = 12;			// Pin 12 - System LED 

void setup() {
  pinMode(led, OUTPUT);  
  pinMode(pwm1, OUTPUT);
  pinMode(direc1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(direc2, OUTPUT);
  pinMode(motor3, OUTPUT);
  Serial.begin(9600);       
}

void loop() {
  
  if( Serial.available() )
  {
    val = Serial.read();
    System_Run(val);
  }
  
  delay(1);                    
}

void System_Run(int variable)
{
  if (variable == '0' )						// Turn off system
  {
    digitalWrite(led, LOW);
    analogWrite (pwm1, 0);
    digitalWrite(direc1, LOW);
    analogWrite (pwm2, 0);
    digitalWrite(direc2, LOW);
    analogWrite (motor3, 0);
    Serial.print("SYSTEM OFF");
  }
  
  else if( variable == 'A' )				// Clockwise with highest motor 1 speed 
  {
    digitalWrite(led, HIGH);
    Serial.print ("SYSTEM ON");
    digitalWrite(direc1, 0);
    analogWrite(pwm1, 127);
    Serial.print ("CLOCKWISE HIGHEST MOTOR 1 SPEED");
    delay(1);
  } 

  else if( variable == 'B' )				// Clockwise with middle motor 1 speed
  {
    digitalWrite(led, HIGH);
    Serial.print ("SYSTEM ON");
    digitalWrite(direc1, 0);
    analogWrite(pwm1, 64);
    Serial.print ("CLOCKWISE MIDDLE MOTOR 1 SPEED");
    delay(1);
  } 

  else if( variable == 'C' )				// Clockwise with lowest motor 1 speed
  {
    digitalWrite(led, HIGH);
    Serial.print ("SYSTEM ON");
    digitalWrite(direc1, 0);
    analogWrite(pwm1, 33);
    Serial.print ("CLOCKWISE LOWEST MOTOR 1 SPEED");    
    delay(1);
  } 

  else if( variable == 'D' )				// Anti-clockwise with highest motor 1 speed 
  {
    digitalWrite(led, HIGH);
    Serial.print ("SYSTEM ON");
    digitalWrite(direc1, 1);
    analogWrite(pwm1, 127);
    Serial.print ("ANTI-CLOCKWISE HIGHEST MOTOR 1 SPEED");
    delay(1);
  } 

  else if( variable == 'E' )				// Anti-clockwise with middle motor 1 speed
  {
    digitalWrite(led, HIGH);
    Serial.print ("SYSTEM ON");
    digitalWrite(direc1, 1);
    analogWrite(pwm1, 64);
    Serial.print ("ANTI-CLOCKWISE MIDDLE MOTOR 1 SPEED");
    delay(1);
  } 

  else if( variable == 'F' )				// Anti-clockwise with lowest motor 1 speed
  {
    digitalWrite(led, HIGH);
    Serial.print ("SYSTEM ON");
    digitalWrite(direc1, 1);
    analogWrite(pwm1, 33);
    Serial.print ("ANTI-CLOCKWISE LOWEST MOTOR 1 SPEED");
    delay(1);
  } 

  else if( variable == 'G' )				// Clockwise with highest motor 2 speed 
  {
    digitalWrite(led, HIGH);
    Serial.print ("SYSTEM ON");
    digitalWrite(direc2, 0);
    analogWrite(pwm2, 127);
    Serial.print ("CLOCKWISE HIGHEST MOTOR 2 SPEED");
    delay(1);
  } 

  else if( variable == 'H' )				// Clockwise with middle motor 2 speed
  {
    digitalWrite(led, HIGH);
    Serial.print ("SYSTEM ON");
    digitalWrite(direc2, 0);
    analogWrite(pwm2, 64);
    Serial.print ("CLOCKWISE MIDDLE MOTOR 2 SPEED");
    delay(1);
  } 

  else if( variable == 'I' )				// Clockwise with lowest motor 2 speed
  {
    digitalWrite(led, HIGH);
    Serial.print ("SYSTEM ON");
    digitalWrite(direc2, 0);
    analogWrite(pwm2, 33);
    Serial.print ("CLOCKWISE LOWEST MOTOR 2 SPEED");    
    delay(1);
  } 

  else if( variable == 'J' )				// Anti-clockwise with highest motor 2 speed 
  {
    digitalWrite(led, HIGH);
    Serial.print ("SYSTEM ON");
    digitalWrite(direc2, 1);
    analogWrite(pwm2, 127);
    Serial.print ("ANTI-CLOCKWISE HIGHEST MOTOR 2 SPEED");
    delay(1);
  } 

  else if( variable == 'K' )				// Anti-clockwise with middle motor 2 speed
  {
    digitalWrite(led, HIGH);
    Serial.print ("SYSTEM ON");
    digitalWrite(direc2, 1);
    analogWrite(pwm2, 64);
    Serial.print ("ANTI-CLOCKWISE MIDDLE MOTOR 2 SPEED");
    delay(1);
  } 

  else if( variable == 'L' )				// Anti-clockwise with lowest motor 2 speed
  {
    digitalWrite(led, HIGH);
    Serial.print ("SYSTEM ON");
    digitalWrite(direc2, 1);
    analogWrite(pwm2, 33);
    Serial.print ("ANTI-CLOCKWISE LOWEST MOTOR 2 SPEED");
    delay(1);
  } 

  else if( variable == 'M' )				// Highest motor 3 speed
  {
    digitalWrite(led, HIGH);
    Serial.print ("SYSTEM ON");
    analogWrite(motor3, 90);
    Serial.print ("HIGHEST MOTOR 3 SPEED");
    delay(1);
  } 
}
