/* Copyright (c) 2016 Jerry Chong @ Universiti Tunku Abdul Rahman (UTAR), Malaysia
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE. 
*/

char val;				    // Value recieved via bluetooth
int direc1 = 4;			// Pin 4 - Direction of Motor 1
#define pwm1 5			// Pin 5 - Motor 1 Speed
int direc2 = 8;			// Pin 8 - Direction of Motor 2
#define pwm2 9			// Pin 9 - Motor 2 Speed
#define motor3 10		// Pin 10 - Motor 3 Speed 
int led = 12;			  // Pin 12 - System LED 

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
  if( Serial.available() ) {
    val = Serial.read();
    System_Run(val);
  }
  
  delay(1);                    
}

void System_Run(int variable) {
  if ( variable == '0' )	{					
    // Turn off system
    digitalWrite(led, LOW);
    analogWrite (pwm1, 0);
    digitalWrite(direc1, LOW);
    analogWrite (pwm2, 0);
    digitalWrite(direc2, LOW);
    analogWrite (motor3, 0);
    Serial.print("SYSTEM OFF");
  } else if( variable == 'A' ) {
    // Motor 1 - Clockwise with highest speed 
    digitalWrite(led, HIGH);
    Serial.print ("SYSTEM ON");
    digitalWrite(direc1, 0);
    analogWrite(pwm1, 127);
    Serial.print ("MOTOR 1 - CLOCKWISE HIGHEST SPEED");
    delay(1);
  } else if( variable == 'B' ) {
    // Motor 1 - Clockwise with medium speed
    digitalWrite(led, HIGH);
    Serial.print ("SYSTEM ON");
    digitalWrite(direc1, 0);
    analogWrite(pwm1, 64);
    Serial.print ("MOTOR 1 - CLOCKWISE MEDIUM SPEED");
    delay(1);
  } else if( variable == 'C' ) { 
    // Motor 1 - Clockwise with lowest speed
    digitalWrite(led, HIGH);
    Serial.print ("SYSTEM ON");
    digitalWrite(direc1, 0);
    analogWrite(pwm1, 33);
    Serial.print ("MOTOR 1 - CLOCKWISE LOWEST SPEED");    
    delay(1);
  } else if( variable == 'D' ) {
    // Motor 1 - Anti-clockwise with highest speed
    digitalWrite(led, HIGH);
    Serial.print ("SYSTEM ON");
    digitalWrite(direc1, 1);
    analogWrite(pwm1, 127);
    Serial.print ("MOTOR 1 - ANTI-CLOCKWISE HIGHEST SPEED");
    delay(1);
  } else if( variable == 'E' ) {
    // Motor 1 - Anti-clockwise with medium speed
    digitalWrite(led, HIGH);
    Serial.print ("SYSTEM ON");
    digitalWrite(direc1, 1);
    analogWrite(pwm1, 64);
    Serial.print ("MOTOR 1 - ANTI-CLOCKWISE MEDIUM SPEED");
    delay(1);
  } else if( variable == 'F' ) {
    // Motor 1 - Anti-clockwise with lowest speed
    digitalWrite(led, HIGH);
    Serial.print ("SYSTEM ON");
    digitalWrite(direc1, 1);
    analogWrite(pwm1, 33);
    Serial.print ("MOTOR 1 - ANTI-CLOCKWISE LOWEST SPEED");
    delay(1);
  } else if( variable == 'G' ) {
    // Motor 2 - Clockwise with highest speed 
    digitalWrite(led, HIGH);
    Serial.print ("SYSTEM ON");
    digitalWrite(direc2, 0);
    analogWrite(pwm2, 127);
    Serial.print ("MOTOR 2 - CLOCKWISE HIGHEST SPEED");
    delay(1);
  } else if( variable == 'H' ) {
    // Motor 2 - Clockwise with medium speed
    digitalWrite(led, HIGH);
    Serial.print ("SYSTEM ON");
    digitalWrite(direc2, 0);
    analogWrite(pwm2, 64);
    Serial.print ("MOTOR 2 - CLOCKWISE MEDIUM SPEED");
    delay(1);
  } else if( variable == 'I' ) {
    // Motor 2 - Clockwise with lowest speed
    digitalWrite(led, HIGH);
    Serial.print ("SYSTEM ON");
    digitalWrite(direc2, 0);
    analogWrite(pwm2, 33);
    Serial.print ("MOTOR 2 - CLOCKWISE LOWEST SPEED");
    delay(1);
  } else if( variable == 'J' ) {
    // Motor 2 - Anti-clockwise with highest speed 
    digitalWrite(led, HIGH);
    Serial.print ("SYSTEM ON");
    digitalWrite(direc2, 1);
    analogWrite(pwm2, 127);
    Serial.print ("MOTOR 2 - ANTI-CLOCKWISE HIGHEST SPEED");
    delay(1);
  } else if( variable == 'K' ) {
    // Motor 2 - Anti-clockwise with medium speed
    digitalWrite(led, HIGH);
    Serial.print ("SYSTEM ON");
    digitalWrite(direc2, 1);
    analogWrite(pwm2, 64);
    Serial.print ("MOTOR 2 - ANTI-CLOCKWISE MEDIUM SPEED");
    delay(1);
  } else if( variable == 'L' ) {
    // Motor 2 - Anti-clockwise with lowest speed
    digitalWrite(led, HIGH);
    Serial.print ("SYSTEM ON");
    digitalWrite(direc2, 1);
    analogWrite(pwm2, 33);
    Serial.print ("MOTOR 2 - ANTI-CLOCKWISE LOWEST SPEED");
    delay(1);
  } else if( variable == 'M' ) {
    // Motor 3 - Highest speed
    digitalWrite(led, HIGH);
    Serial.print ("SYSTEM ON");
    analogWrite(motor3, 90);
    Serial.print ("MOTOR 3 - HIGHEST SPEED");
    delay(1);
  } 
}
