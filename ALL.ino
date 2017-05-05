#include<Servo.h>
 Servo base;
 Servo shoulder;
 Servo elbow;
 Servo wrist;
 Servo leftg;
 Servo rightg;

const int sensorPin1 = A8;
const int sensorPin2 = A9;
const int sensorPin3 = A10;
const int sensorPin4 = A11;
const int sensorPin5 = A12;
const int midPinF = A14;
//const int midPinB = A1;

const int In1 = 5; 
const int In2 = 4;  
const int In3 = 7; 
const int In4 = 6; 
const int En1 = 3;
const int En2 = 8;
int count =0 ;

int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;
int sensorValue4 = 0;
int sensorValue5 = 0;
int midValF = 0;

void setup() 
{
  pinMode(In1, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(En1, OUTPUT);
  pinMode(En2, OUTPUT);
  Serial.begin(9600);
  base.attach(32);
  shoulder.attach(28);
  elbow.attach(40);
  wrist.attach(26);
  leftg.attach(22);
  rightg.attach(24);
  startingHome();
  //delay(100);
}


void loop ()
{
	sensorValue1 = analogRead(sensorPin1);
	sensorValue2 = analogRead(sensorPin2);
	sensorValue3 = analogRead(sensorPin3);
	sensorValue4 = analogRead(sensorPin4);
	sensorValue5 = analogRead(sensorPin5);
  midValF = analogRead(midPinF);

	Serial.println(sensorValue1);
	Serial.println(sensorValue2);
	Serial.println(sensorValue3);
	Serial.println(sensorValue4);
	Serial.println(sensorValue5);
	Serial.println("");
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
	lforward(80);
}
else
{
  takeReading();
}

 if (sensorValue4 < 400)
{
	rforward(80);
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
  //Serial.println(count);
 //delay(400);
 
    if (count == 4)
   {  
      foward(0);
      reverse(155);
      delay(120);
      foward(0);
      turnRight(200);
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
  leftFoward(turnSpeed);
  rightReverse(turnSpeed);
}

void turnLeft(int turnSpeed)
{
  do 
  {
    
    sensorValue3 = (analogRead(sensorPin3) > 400) ? 1 : 0;
    
    offsetLeft(turnSpeed);
    delay(500);
  }
  while (!(sensorValue4 && sensorValue3 && sensorValue2));
  foward(0);
  delay(500);
  
  do 
  {
    
    sensorValue3 = (analogRead(sensorPin3) > 400) ? 1 : 0;
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
  
    sensorValue3 = (analogRead(sensorPin3) > 400) ? 1 : 0;
  
    offsetRight(turnSpeed);
    delay(400);
  }
  while (!(sensorValue4 && sensorValue3 && sensorValue2));
  foward(0);
  delay(100);
  
  do 
  { 
  
    sensorValue3 = (analogRead(sensorPin3) > 400) ? 1 : 0;
   
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
   analogWrite(En1, leftSpeed);//LEFT SIDE SPEED
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


void pickRed()
{
  homePosition();
  delay(10);
  getRed();
  delay(10);
  opengrip();
  delay(10);
  approach();
  delay(10);
  closegrip();
  delay(10);
  Return();
  delay(10);
  returnRed();
  delay(10);

  }
void pickYellow()
{
  homePosition();
  delay(100);
  getYellow();
  delay(100);
  opengrip();
  delay(100);
  approach();
 delay(100);
 closegrip();
 delay(100);
 Return();
 delay(100);
 returnYellow();
 delay(100);
 opengrip();
 }
void pickBlue()
{
  homePosition();
  delay(100);
  getBlue();
  delay(100);
  opengrip();
 delay(100);
  approach();
 delay(100);
 closegrip();
 delay(100);
  Return();
  delay(100);
  returnBlue();
  delay(100);
  opengrip();
  }
void homePosition()
{
  base.write(125); 
  shoulder.write(20);
  elbow.write(60);
  wrist.write(60);
  rightg.write(5);
  leftg.write(130);
  closegrip();
}

void approach()
{
  int angle_count, shoulder_move, elbow_move, wrist_move, base_move;
  for(angle_count=0; angle_count<=100; angle_count++)
  {
    shoulder_move = map(angle_count, 0, 100, 30, 83);
    elbow_move = map(angle_count, 0, 100, 55,70);
    wrist_move = map(angle_count, 0, 100, 30, 110);

    shoulder.write(shoulder_move);
    wrist.write(wrist_move);
    elbow.write(elbow_move);
    
    delay(10);
  }
}

void Return()
{

  int angle_count, shoulder_move, elbow_move, wrist_move, base_move;
  for(angle_count=0; angle_count<=100; angle_count++)
  {
    shoulder_move = map(angle_count, 0, 100, 83, 20);
    elbow_move = map(angle_count, 0, 100, 70, 80);
    wrist_move = map(angle_count, 0, 100, 110, 60);

    
    elbow.write(elbow_move);
    wrist.write(wrist_move);
    shoulder.write(shoulder_move);
    delay(10);
}
}


void closegrip()
{
  int grip_angle, grip_left, grip_right;
  for (grip_angle=0; grip_angle<=10; grip_angle++)
  {
    grip_left=map(grip_angle, 0, 10, 130, 178); //176
    grip_right=map(grip_angle, 0, 10, 5, 27); //24

    leftg.write(grip_left);
    rightg.write(grip_right);
    delay(15);
  }
}

void opengrip()
{
   int  grip_angle, grip_left, grip_right;
  for (grip_angle=0; grip_angle<=10; grip_angle++)
  {
    grip_left=map(grip_angle, 0, 10, 175, 130);
    grip_right=map(grip_angle, 0, 10, 20, 5);

    leftg.write(grip_left);
    rightg.write(grip_right);
    delay(15);
}}
void getBlue()
{ 
int baseAngle, angleCount;
for(angleCount = 0; angleCount <=100; angleCount++)
{
  baseAngle = map(angleCount, 0, 100, 125, 44);
  
  base.write(baseAngle); 
  delay(10);
  } 
}

void returnBlue()
{ 
int baseAngle, angleCount;
for(angleCount = 0; angleCount <=100; angleCount++){
  baseAngle = map(angleCount, 0, 100, 44, 119);
  base.write(baseAngle); 
  delay(10);
  } 
}

void getYellow()
{  
int baseAngle, angleCount;
for(angleCount = 0; angleCount <=100; angleCount++)
{
  baseAngle = map(angleCount, 0, 100, 125, 44);
  base.write(baseAngle); 
  delay(10);
  } 
}

void returnYellow()
{
  
int baseAngle, angleCount;
for(angleCount = 0; angleCount <=100; angleCount++)
{
  baseAngle = map(angleCount, 0, 100, 44, 104);
  base.write(baseAngle); 
  delay(10);
  } 
}

void getRed()
{
  
int baseAngle, angleCount;
for(angleCount = 0; angleCount <=100; angleCount++)
{
  
  baseAngle = map(angleCount, 0, 100, 125, 44);
  base.write(baseAngle); 
  delay(10);
  } 
}

void returnRed()
{ 
int baseAngle, angleCount;
int elbowAngle;
for(angleCount = 0; angleCount <=100; angleCount++)
{
  baseAngle = map(angleCount, 0, 100, 46, 125); 
  elbowAngle = map(angleCount, 0, 100, 60, 60);
  base.write(baseAngle); 
  delay(10);
  elbow.write(elbowAngle);
  } 
}

void goRedBallot()
{
  
int baseAngle, angleCount;
for(angleCount = 0; angleCount <=100; angleCount++)
{
  
  baseAngle = map(angleCount, 0, 100, 80, 137);
  base.write(baseAngle); 
  delay(10);
  } 
}
void goYellowBallot()
{
  
int baseAngle, angleCount;
for(angleCount = 0; angleCount <=100; angleCount++)
{
  baseAngle = map(angleCount, 0, 100, 165, 150);
  base.write(baseAngle); 
  delay(10);
  } 
 
}

void goBlueBallot()
{
  
int baseAngle, angleCount;
for(angleCount = 0; angleCount <=100; angleCount++){
  
  baseAngle = map(angleCount, 0, 100, 80, 150);
  base.write(baseAngle); 
  delay(10);
  } 
 
}

void pickVote()
{
  int angle_count, shoulder_move, elbow_move, wrist_move, base_move;
  
  for(angle_count=0; angle_count<=100; angle_count++)
  {
    shoulder_move = map(angle_count, 0, 100, 90, 100);
    elbow_move = map(angle_count, 0, 100, 60, 40);
    wrist_move = map(angle_count, 0, 100, 60, 40);

    shoulder.write(shoulder_move);
    elbow.write(elbow_move);
    wrist.write(wrist_move);
    delay(10);
  }

  closegrip();
}


void approachBallotBox()
{
  int angle_count, shoulder_move, elbow_move, wrist_move, base_move;
  for(angle_count=0; angle_count<=100; angle_count++)
  {
    shoulder_move = map(angle_count, 0, 100, 20, 55);
    elbow_move = map(angle_count, 0, 100, 60, 60);
    wrist_move = map(angle_count, 0, 100, 60, 120);
    base_move = map(angle_count, 0, 100, 137, 150);
    shoulder.write(shoulder_move);
    elbow.write(elbow_move);
    wrist.write(wrist_move);
    base.write(base_move);
    delay(10);
  }
}

void ReturnFromBallotBox()
{
  int angle_count, shoulder_move, elbow_move, wrist_move, base_move;
  for(angle_count=0; angle_count<=100; angle_count++)
  {
    shoulder_move = map(angle_count, 0, 100, 130, 100);
    elbow_move = map(angle_count, 0, 100, 50, 60);
    wrist_move = map(angle_count, 0, 100, 90, 50);

    shoulder.write(shoulder_move);
    elbow.write(elbow_move);
    wrist.write(wrist_move);
    delay(10);
}

  
}

void voteRed()
{
  approachBallotBox();
  delay(500);
  opengrip();
  delay(500); 
}

void voteYellow()
{
  returnYellow();
  delay(500);
  funguagripYellow();
  delay(500);
  base.write(122);
  chukuaYellow();
  closegrip();
  delay(500);
 closegrip();
  delay(500);
  elbow.write(50);
  delay(500);
  wekaYellow();
  delay(500);
  opengrip();
  delay(500);
}

void voteBlue()
{
opengrip();
delay(500);
chukuaBlue();
delay(500);
closegrip();
delay(500);
elbow.write(70);
delay(500);
wekaBlue();
delay(500);
opengrip();
delay(500);
}

void chukuaYellow ()
{
  int baseAngle,angle_count,elbow_move,wrist_move;
for(angle_count = 0; angle_count <=100; angle_count++)
{
  //baseAngle = map(angleCount, 0, 100, 70, 119);
   elbow_move = map(angle_count, 0, 100, 60,96 );
   wrist_move = map(angle_count, 0, 100, 60,42);
   
   wrist.write(wrist_move);
   elbow.write(elbow_move);
  
  delay(10);
  } 
  closegrip();
}

void wekaYellow ()
{
  int baseAngle,angle_count,elbow_move,wrist_move,shoulder_move;
for(angle_count = 0; angle_count <=100; angle_count++)
{
   baseAngle = map(angle_count, 0, 100, 137,125 );
   elbow_move = map(angle_count, 0, 100, 60,42 );
   wrist_move = map(angle_count, 0, 100, 60,115);
   shoulder_move = map(angle_count, 0, 100, 20,59);
   
   wrist.write(wrist_move);
   elbow.write(elbow_move);
   shoulder.write(shoulder_move);
   base.write(baseAngle);
  
  delay(10);
}
}
void funguagripYellow()
{
 
  int  grip_angle, grip_left, grip_right;
  for (grip_angle=0; grip_angle<=10; grip_angle++)
  {
    grip_left=map(grip_angle, 0, 10, 175, 170);
    grip_right=map(grip_angle, 0, 10, 20, 1);

    leftg.write(grip_left);
    rightg.write(grip_right);
    delay(15);
} 
}
void chukuaBlue()
{
    int baseAngle,angle_count,elbow_move,wrist_move;
for(angle_count = 0; angle_count <=100; angle_count++)
{
  baseAngle = map(angle_count, 0, 100, 125, 129);
   elbow_move = map(angle_count, 0, 100, 60,99);
   wrist_move = map(angle_count, 0, 100, 60,49);
   
   wrist.write(wrist_move);
   elbow.write(elbow_move);
   base.write(baseAngle);
  
  delay(10);
  } 
  closegrip();
}

void wekaBlue()
{
  int baseAngle,angle_count,elbow_move,wrist_move,shoulder_move;
for(angle_count = 0; angle_count <=100; angle_count++)
{
   baseAngle = map(angle_count, 0, 100, 137,107);
   elbow_move = map(angle_count, 0, 100, 60,65);
   wrist_move = map(angle_count, 0, 100, 60,160);
   shoulder_move = map(angle_count, 0, 100, 20,70);
   
   wrist.write(wrist_move);
   elbow.write(elbow_move);
   shoulder.write(shoulder_move);
   base.write(baseAngle);
  
  delay(10);
} 
}

void startingHome()
{
   base.write(125); 
  shoulder.write(10);
  elbow.write(145);
  wrist.write(177);
  rightg.write(5);
  leftg.write(130);
  closegrip();
}






