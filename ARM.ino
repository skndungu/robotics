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
  
  homePosition();
  delay(100); 
  pickBlue();
  delay(100);
  pickYellow();
   delay(100);
  pickRed();
  delay(100);
 voteRed();
 //shoulder.write(32);
  delay(100);
  homePosition();
 delay(50);
 voteYellow();
 shoulder.write(32);
 delay(100);
 homePosition();
 delay(50);
 voteBlue();
 delay(20);
 shoulder.write(32);
 delay(200);
 homePosition();
 
 }

void loop()
{

}
void pickRed()
{
  //homePosition();
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
  //homePosition();
  delay(20);
  getYellow();
  delay(10);
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
 delay(100);
// straight();
 }
void pickBlue()
{
 // homePosition();
  delay(10);
  getBlue();
  delay(10);
  opengrip();
 delay(100);
  approach();
 delay(10);
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
  base.write(110); 
  shoulder.write(5);
  elbow.write(60);
  wrist.write(60);
  rightg.write(5);
  leftg.write(130);
  closegrip();
}

void approach()
{
  int angle_count, shoulder_move, elbow_move, wrist_move, base_move;
  for(angle_count=0; angle_count<=60; angle_count++)
  {
    shoulder_move = map(angle_count, 0, 40, 5, 35);
    elbow_move = map(angle_count, 0, 40, 60,38);
    wrist_move = map(angle_count, 0, 60, 60, 110);

    shoulder.write(shoulder_move);
    wrist.write(wrist_move);
    elbow.write(elbow_move);
    
    delay(10);
  }
}

void Return()
{

  int angle_count, shoulder_move, elbow_move, wrist_move, base_move;
  for(angle_count=0; angle_count<=60; angle_count++)
  {
    shoulder_move = map(angle_count, 0, 60, 35, 5);
    elbow_move = map(angle_count, 0, 60, 38, 70);
    wrist_move = map(angle_count, 0, 60, 110, 120);

    
    elbow.write(elbow_move);
    wrist.write(wrist_move);
    shoulder.write(shoulder_move);
    delay(10);
}
}

//void straight()
//{
//  elbow.write(60);
// }
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
int baseAngle, angleCount, shoulder_move, elbow_move, wrist_move;
for(angleCount = 0; angleCount <=60; angleCount++)
{
  baseAngle = map(angleCount, 0, 60, 110, 16);
  

    base.write(baseAngle); 
    //delay(10);
  } 
}

void returnBlue()
{ 
int baseAngle, angleCount, shoulder_move, elbow_move, wrist_move;
for(angleCount = 0; angleCount <=60; angleCount++)
{
     shoulder_move = map(angleCount, 0, 60, 5, 30);
    elbow_move = map(angleCount, 0, 60, 30, 70);
    wrist_move = map(angleCount, 0, 60, 110, 57);
     baseAngle = map(angleCount, 0, 60, 16, 134);

    
//    elbow.write(elbow_move);
      wrist.write(wrist_move);
//   shoulder.write(shoulder_move);
//    delay(10);
// 
  base.write(baseAngle); 
  delay(10);
  } 
  
}

void getYellow()
{  
int baseAngle, angleCount;
for(angleCount = 0; angleCount <=60; angleCount++)
{
  
  baseAngle = map(angleCount, 0, 60, 110, 16);
  base.write(baseAngle); 
  delay(10);
  } 
}

void returnYellow()
{
  
int baseAngle, angleCount,  elbowAngle,  wrist_move;
for(angleCount = 0; angleCount <=60; angleCount++)
{
  baseAngle = map(angleCount, 0, 60, 16, 92);
  elbowAngle = map(angleCount, 0, 60, 60,72);
  wrist_move = map(angleCount, 0, 60, 110, 60);

  wrist.write( wrist_move);
  base.write(baseAngle);
  elbow.write(elbowAngle); 
  delay(10);
  } 
}

void getRed()
{
  
int baseAngle, angleCount;
for(angleCount = 0; angleCount <=60; angleCount++)
{
  
  baseAngle = map(angleCount, 0, 60, 110, 16);
  base.write(baseAngle); 
  delay(10);
  } 
}

void returnRed()
{ 
int baseAngle, angleCount;
int elbowAngle;
for(angleCount = 0; angleCount <=60; angleCount++)
{
  baseAngle = map(angleCount, 0, 60, 16, 140); 
  elbowAngle = map(angleCount, 0, 60, 60, 60);
  base.write(baseAngle); 
  delay(10);
  elbow.write(elbowAngle);
  } 
}

void goRedBallot()
{
  
int baseAngle, angleCount;
for(angleCount = 0; angleCount <=60; angleCount++)
{
  
  baseAngle = map(angleCount, 0, 60, 80, 137);
  base.write(baseAngle); 
  delay(10);
  } 
}
void goYellowBallot()
{
  
int baseAngle, angleCount;
for(angleCount = 0; angleCount <=60; angleCount++)
{
  baseAngle = map(angleCount, 0, 60, 165, 150);
  base.write(baseAngle); 
  delay(10);
  } 
 
}

void goBlueBallot()
{
  
int baseAngle, angleCount;
for(angleCount = 0; angleCount <=60; angleCount++){
  
  baseAngle = map(angleCount, 0, 60, 80, 150);
  base.write(baseAngle); 
  delay(10);
  } 
 
}

void pickVote()
{
  int angle_count, shoulder_move, elbow_move, wrist_move, base_move;
  
  for(angle_count=0; angle_count<=60; angle_count++)
  {
    shoulder_move = map(angle_count, 0, 60, 90, 100);
    elbow_move = map(angle_count, 0, 60, 60, 40);
    wrist_move = map(angle_count, 0, 60, 60, 40);

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
  for(angle_count=0; angle_count<=60; angle_count++)
  {
    shoulder_move = map(angle_count, 0, 60, 5,44);
    elbow_move = map(angle_count, 0, 60, 60,55);
    wrist_move = map(angle_count, 0, 60, 60, 127);
    base_move = map(angle_count, 0, 60, 110,131);
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
  for(angle_count=0; angle_count<=60; angle_count++)
  {
    shoulder_move = map(angle_count, 0, 60, 130, 100);
    elbow_move = map(angle_count, 0, 60, 50, 60);
    wrist_move = map(angle_count, 0, 60, 90, 50);

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
  delay(300);
  funguagripYellow();
  delay(300);
  chukuaYellow();
  closegrip();
  delay(300);
  shoulder.write(50);
  wekaYellow();
  delay(300);
  opengrip();
  delay(300);
}

void voteBlue()
{
opengrip();
delay(300);
chukuaBlue();
delay(300);
closegrip();
delay(300);
elbow.write(70);
delay(300);
wekaBlue();
delay(300);
opengrip();
delay(300);
}

void chukuaYellow ()
{
  int baseAngle,angle_count,elbow_move,wrist_move;
for(angle_count = 0; angle_count <=60; angle_count++)
{
  //baseAngle = map(angleCount, 0, 100, 70, 119);
   elbow_move = map(angle_count, 0, 60, 60,83);
   wrist_move = map(angle_count, 0, 60, 60,42);
   
   wrist.write(wrist_move);
   elbow.write(elbow_move);
  
  delay(10);
  } 
  closegrip();
}

void wekaYellow ()
{
  int baseAngle,angle_count,elbow_move,wrist_move,shoulder_move;
for(angle_count = 0; angle_count <=60; angle_count++)
{
   baseAngle = map(angle_count, 0, 60, 92,91 );
   elbow_move = map(angle_count, 0, 60, 83,42 );
   wrist_move = map(angle_count, 0, 60, 42,12);
   shoulder_move = map(angle_count, 0, 60, 5,48);
   
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
for(angle_count = 0; angle_count <=60; angle_count++)
{
  baseAngle = map(angle_count, 0, 60, 110, 144);
   elbow_move = map(angle_count, 0, 60, 60,96);
   wrist_move = map(angle_count, 0, 60, 60,49);
   
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
for(angle_count = 0; angle_count <=60; angle_count++)
{
   baseAngle = map(angle_count, 0, 60, 110,67);
   elbow_move = map(angle_count, 0, 60, 60,55);
   wrist_move = map(angle_count, 0, 60, 60,160);
   shoulder_move = map(angle_count, 0, 60, 5,72);
   
   wrist.write(wrist_move);
   elbow.write(elbow_move);
   shoulder.write(shoulder_move);
   base.write(baseAngle);
  
  delay(10);
} 
}

void startingHome()
{
   base.write(116); 
  shoulder.write(10);
  elbow.write(145);
  wrist.write(177);
  rightg.write(5);
  leftg.write(130);
  closegrip();
}


void returnHomeRed()
{
    int baseAngle,angle_count,elbow_move,wrist_move,shoulder_move,base_move;
for(angle_count = 0; angle_count <=60; angle_count++)
{
    shoulder_move = map(angle_count, 0, 60, 76,25);
    elbow_move = map(angle_count, 0, 60, 55,60);
    wrist_move = map(angle_count, 0, 60, 127, 60);
    base_move = map(angle_count, 0, 60, 115,95);
   
   wrist.write(wrist_move);
   elbow.write(elbow_move);
   shoulder.write(shoulder_move);
   base.write(baseAngle);
  
  delay(10);
}
}

void returnHomeBlue()
{
    int baseAngle,angle_count,elbow_move,wrist_move,shoulder_move,base_move;
for(angle_count = 0; angle_count <=60; angle_count++)
{
    shoulder_move = map(angle_count, 0, 60, 87,37);
    elbow_move = map(angle_count, 0, 60, 55,60);
    wrist_move = map(angle_count, 0, 60, 160, 60);
    base_move = map(angle_count, 0, 60, 52,95);
   
   wrist.write(wrist_move);
   elbow.write(elbow_move);
   shoulder.write(shoulder_move);
   base.write(baseAngle);
  
  delay(10);
}
}

void returnHomeYellow()
{
    int baseAngle,angle_count,elbow_move,wrist_move,shoulder_move,base_move;
for(angle_count = 0; angle_count <=60; angle_count++)
{
    shoulder_move = map(angle_count, 0, 60, 80,37);
    elbow_move = map(angle_count, 0, 60, 42,60);
    wrist_move = map(angle_count, 0, 60, 125, 60);
    base_move = map(angle_count, 0, 60,80,95);
   
   wrist.write(wrist_move);
   elbow.write(elbow_move);
   shoulder.write(shoulder_move);
   base.write(baseAngle);
  
  delay(10);
}
}




