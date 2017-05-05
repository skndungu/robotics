#include<Servo.h>

 Servo base;
 Servo shoulder;
 Servo elbow;
 Servo wrist;
 Servo leftg;
 Servo rightg;

 void setup()
 {
  base.attach(32);
  shoulder.attach(28);
  elbow.attach(40);
  wrist.attach(26);
  leftg.attach(22);
  rightg.attach(24);
  pickBlue();
  delay(100); 
  pickYellow();
  delay(100);
  pickRed();
  delay(100);
 voteRed();
 homePosition();
 voteYellow();
 delay(100);
 homePosition();
  voteBlue();
  delay(100);
  homePosition();
 }

void loop()
{

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





