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

void reverse (int rreverses)
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
