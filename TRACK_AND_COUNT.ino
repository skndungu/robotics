const int In1 = 5; 
const int In2 = 4;  
const int In3 = 7; 
const int In4 = 6; 
const int En1 = 3;
const int En2 = 8;
int count =0 ;

const int midPinF = A0;
const int midPinB = A1;
const int sensorPin1 = A8;
const int sensorPin2 = A9;
const int sensorPin3 = A10;
const int sensorPin4 = A11;
const int sensorPin5 = A12;
 
int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;
int sensorValue4 = 0;
int sensorValue5 = 0;
int midValF = 0;

void setup()
{
	Serial.begin(9600);
	pinMode(In1,OUTPUT);
	pinMode(In2,OUTPUT);
	pinMode(In3,OUTPUT);
	pinMode(In4,OUTPUT);
}

void loop ()
{
	sensorValue1 = analogRead(sensorPin1);
	sensorValue2 = analogRead(sensorPin2);
	sensorValue3 = analogRead(sensorPin3);
	sensorValue4 = analogRead(sensorPin4);
	sensorValue5 = analogRead(sensorPin5);
  midValF = analogRead(midPinF);

//	Serial.println(sensorValue1);
//	Serial.println(sensorValue2);
//	Serial.println(sensorValue3);
//	Serial.println(sensorValue4);
//	Serial.println(sensorValue5);
	//Serial.println("");
	//delay(1000);
 if(sensorValue3 < 400)
	{
	forward(155);
	}
else 
{
 
  takeReading ();  
}

      if(sensorValue1 < 400)
	{
	  lreverse(150); 
          rforward(155); 	
	}
else 
{
 takeReading ();
}
if(sensorValue2 <400)
{
  	rforward(220);
	lforward(60);
}
else
{
  takeReading();
}

 if (sensorValue4 < 400)
{
	rforward(60);
	lforward(220); 
}

else
{
  takeReading();
}
if(sensorValue5 < 400)
	{
	  lforward(155);     
          rreverse(155);	
	}
else 
{
  takeReading();
}
if ( sensorValue2 > 400 && sensorValue3 < 400  && sensorValue4 > 400)
{ 
	forward(155);

}
else
{
  takeReading();
}

if (sensorValue2 < 400 && sensorValue3 < 400  && sensorValue4 < 400)
{ 
	forward(155);
}
else
{
  takeReading();
}
if (sensorValue1 < 400 && sensorValue2 < 400  && sensorValue3 < 400 && sensorValue4 < 400  && sensorValue5 < 400)
{ 
	forward(155);
}
else
{
  takeReading();
}

if(midValF < 400)
{
  do
    {
      midValF = analogRead(midPinF);
    }

    while (midValF < 400 );

    do
    {
      midValF = analogRead(midPinF);
    }
    while (midValF > 400);
    count++;
 Serial.println(count);
 //delay(400);
 
    if (count == 4)
   {  
      foward(0);
      reverse(155);
      delay(120);
      foward(0);
      turnRight(175);
   }

    if (count == 16)

    {
      foward(0);
      reverse(155);
      delay(120);
      foward(0);
      turnRight(175);
      
    }
  if (count == 17)
      {
       foward(40);
     }
     if (count == 18)
     {
       foward(10); 
     }
    if (count == 19)

    {
     foward(0);
    delay(100);
    }
    if (count == 20)
    { 
      foward(0);
      reverse(155);
      delay(120);
      foward(0);
      turnLeft(175); 
    }
    if (count ==21)

    {
      foward(10); 
    }
     if (count ==22)

    {
      foward(10);
    }
      if (count ==23)

    {
      foward(0);
    
      foward(0); 
    }
    if (count == 24)
    {
      reverse(155);
      delay(90);
      foward(0);
      foward(50);
      
    }
    if (count == 25)

    {
      foward(0);
      reverse(155);
      delay(90);
      foward(0);
      foward(15);
    }
        if (count == 26)

    {
      foward(0);
      reverse(155);
      delay(90);
      foward(0);
      turnLeft(190); 
    }
  if (count == 31)
 {
    foward(0);
    delay(100);
 }
  if (count == 33)
   {
     foward(0);
     turnLeft(175); 
   }
   if (count == 39)
   {
     foward(0);
     reverse(155);
     delay(90);
     turnRight(175); 
   }
   if (count == 40)
   {
     foward(0);
     turnLeft(175);
   }
    if (count > 41)
    {
       foward(175);
    }
   if (count == 51)
   {
   delay(200);
   foward(0);
   reverse(155);
   delay(90);
   foward(0);
   delay(300);
   }
   if(count==55)
   {
     foward(0);
   }
    if(count==56)
   {
     foward(0);
   }
   
  if (count == 57) 
   {
     foward(0);
     reverse(155);
     delay(90);
     turnRight(175);
   }
   if (count == 65)
  {
     foward(0);
     reverse(155);
     delay(90);
     turnRight(175);
  }
    if (count == 72)
  {
    
   foward(0);
   turnRight(175);
   delay(100);
   foward(0);
}
}
}
void rforward(int rspeed)
{
            digitalWrite(In3,HIGH);
	    digitalWrite(In4,LOW);
            analogWrite(En1,rspeed);

}
void lforward(int Lspeed)
{
	    digitalWrite(In1,HIGH);
	    digitalWrite(In2,LOW);
            analogWrite(En2,Lspeed);

}
void forward (int fspeed)
{
    digitalWrite(In1,HIGH);
    digitalWrite(In2,LOW);
    digitalWrite(In3,HIGH);
    digitalWrite(In4,LOW);
    analogWrite(En1,fspeed);
    analogWrite(En2,fspeed);
}

void rreverse(int rrspeed)
{
	    digitalWrite(In3,LOW);
	    digitalWrite(In4,HIGH);
            analogWrite(En1,rrspeed);
           
}

void lreverse (int lreverse)
{
	 digitalWrite(In1,LOW);
         digitalWrite(In2,HIGH);
         analogWrite(En2,lreverse);
}

void Reverse (int rreverses)
{

	    digitalWrite(In1,LOW);
	    digitalWrite(In2,HIGH);
            digitalWrite(In3,LOW);
            digitalWrite(In4,HIGH);
            analogWrite(En1,rreverses);
            analogWrite(En2,rreverses);
            	
}
void takeReading ()
{
  	sensorValue1 = analogRead(sensorPin1);
	sensorValue2 = analogRead(sensorPin2);
	sensorValue3 = analogRead(sensorPin3);
	sensorValue4 = analogRead(sensorPin4);
	sensorValue5 = analogRead(sensorPin5);
}
void offsetRight(int turnSpeed)
{ 
  rreverse(155);
  lforward(155);
//  rightReverse(turnSpeed);
//  leftFoward(turnSpeed);
}
void offsetLeft(int turnSpeed)
{ 
  rightFoward(turnSpeed);
  leftReverse(turnSpeed);
}

void turnLeft(int turnSpeed)
{
  do 
  {
    sensorValue2 = (analogRead(sensorPin2) > 400) ? 1 : 0;
    sensorValue3 = (analogRead(sensorPin3) > 400) ? 1 : 0;
    sensorValue4 = (analogRead(sensorPin4) > 400) ? 1 : 0;
    offsetLeft(turnSpeed);
  }
  while (!(sensorValue4 && sensorValue3 && sensorValue2));
  foward(0);
  delay(500);
  
  do 
  {
    sensorValue2 = (analogRead(sensorPin2) > 400) ? 1 : 0;
    sensorValue3 = (analogRead(sensorPin3) > 400) ? 1 : 0;
    sensorValue4 = (analogRead(sensorPin4) > 400) ? 1 : 0;
    offsetLeft(turnSpeed);
  }
  while (!((sensorValue3==0) && (sensorValue4 || sensorValue2)));
  foward(0);
  delay(500);
}
void turnRight(int turnSpeed)
{

  do 
  {
    sensorValue2 = (analogRead(sensorPin2) > 400) ? 1 : 0;
    sensorValue3 = (analogRead(sensorPin3) > 400) ? 1 : 0;
    sensorValue4 = (analogRead(sensorPin4) > 400) ? 1 : 0;
    offsetRight(turnSpeed);
  }
  while (!(sensorValue4 && sensorValue3 && sensorValue2));
  foward(0);
  delay(100);
  
  do 
  { 
    sensorValue2 = (analogRead(sensorPin2) > 400) ? 1 : 0;
    sensorValue3 = (analogRead(sensorPin3) > 400) ? 1 : 0;
    sensorValue4 = (analogRead(sensorPin4) > 400) ? 1 : 0;
    offsetRight(turnSpeed);
  }
  while (!((sensorValue3==0) && (sensorValue4 || sensorValue2)));
  foward(0);
  delay(500);
}


void rightFoward(int rightSpeed)
{ 
   digitalWrite(In1, HIGH);//Clockwise motion of the right wheels
   digitalWrite(In2, LOW);//Turn off anti-clockwise motion of the right side motors
   analogWrite(En2, rightSpeed);//RIGHT SIDE SPEED
}
void rightReverse(int rightSpeed)
{ 
   digitalWrite(In1, LOW);//Clockwise motion of the right wheels
   digitalWrite(In2, HIGH);// anti-clockwise motion of the right side motors
   analogWrite(En2, rightSpeed);//LEFT SIDE SPEED
}
void leftFoward(int leftSpeed)
{ 
   digitalWrite(In3, HIGH);//Clockwise motion of the right wheels
   digitalWrite(In4, LOW);//Turn off anti-clockwise motion of the right side motors
   analogWrite(En1, leftSpeed);//LEFT SIDE SPEED
}
void leftReverse(int leftSpeed)
{ 
   digitalWrite(In3, LOW);//Clockwise motion of the left wheels
   digitalWrite(In4, HIGH);//anti-clockwise motion of the left side motors
   analogWrite(En1, leftSpeed) ;//LEFT SIDE SPEED
}
void foward(int speedMove)
{
  rightFoward(speedMove);
  leftFoward(speedMove);
}
void reverse(int speedMove)
{ 
  rightReverse(speedMove);
  leftReverse(speedMove);
}


