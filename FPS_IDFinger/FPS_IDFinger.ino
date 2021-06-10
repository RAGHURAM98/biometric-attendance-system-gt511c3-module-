/* 
	FPS_Enroll.ino - Library example for controlling the GT-511C3 Finger Print Scanner (FPS)
	Created by Josh Hawley, July 23rd 2013
	Licensed for non-commercial use, must include this license message
	basically, Feel free to hack away at it, but just give me credit for my work =)
	TLDR; Wil Wheaton's Law

	This sketch will attempt to identify a previously enrolled fingerprint.
*/

#include "FPS_GT511C3.h"
#include "SoftwareSerial.h"
#include<LiquidCrystal.h>

LiquidCrystal lcd(7,2,11,10,9,8);

// Hardware setup - FPS connected to:
//	  digital pin 4(arduino rx, fps tx)
//	  digital pin 5(arduino tx - 560ohm resistor fps tx - 1000ohm resistor - ground)
//		this brings the 5v tx line down to about 3.2v so we dont fry our fps

FPS_GT511C3 fps(4, 5);

void setup()
{
	Serial.begin(9600);
	delay(100);
	fps.Open();
	fps.SetLED(true);
}

void loop()
{
  lcd.clear();
  lcd.begin(0,0);
  int flag=0;
	// Identify fingerprint test
	if (fps.IsPressFinger())
	{
    fps.CaptureFinger(false);
    int id = fps.Identify1_N();
    if(id==0)
    {
      flag=1;
      lcd.print("session start");
      delay(50);
     Serial.println("session start");
    }
    else
    {
      flag=0;
    }
    while(flag==1)
    {
      mode();
      data();
      delay(100);
      fps.CaptureFinger(false);
    int s = fps.Identify1_N();
    if(s==0)
    {
      Serial.println("Session End");
      break;
    }
    }
		
	}
	else
	{
    lcd.println("TEAM-8 PDP");
    delay(1000);
		//Serial.println("TEAM-8 PDP");
	}
	delay(100);
}

void mode()
{
  fps.CaptureFinger(false);
    int id = fps.Identify1_N();
    if (id <200)
    {
      lcd.print("Verified ID:");
      lcd.println(id);
      delay(50);
      //Serial.print("Verified ID:");
      Serial.println(id);

    }
    else
    {
      lcd.print("Place Finger");
      //Serial.println("Place Finger");
    }
  
}

void data()
{
  
    fps.CaptureFinger(false);
    int id = fps.Identify1_N();
    lcd.begin(0,0);
    if(id==17)
    {
      lcd.print("EDM14B007           BILLA NIKHIL");
      delay(50);
      //Serial.println("EDM14B007");
    }
    if(id==8)
    {
      lcd.print("EDM14B007_2          BILLA NIKHIL");
      delay(50);
      //Serial.println("EDM14B007_2");
    }
    if(id==3)
    {
      lcd.print("EDM14B010              RAGHU RAM");
      delay(50);
      //Serial.println("EDM14B010");
    }
    if(id==5)
    {
      lcd.print("Dr.selvajyothi");
      delay(50);
      //Serial.println("Dr.selvajyothi");
    }
    if(id==6)
    {
      lcd.print("Dr.Chandrasekhar");
      delay(50);
      //Serial.println("Dr.Chandrasekhar");
    }
    if(id==7)
    {
      lcd.print("Dr.Swaminathan");
      delay(50);
      //Serial.println("Dr.Swaminathan");
    }
     if(id==1)
    {
      lcd.print("EDM14B019            NARENDAR NAIK");
      delay(50);
      //Serial.println("EDM14B019");
    }
     if(id==10)
    {
      lcd.print("CED14I020               ANVESH");
      delay(50);
      //Serial.println("CED14I020");
    }
     if(id==12)
    {
      lcd.print("EDM14B019_2");
      delay(50);
      //Serial.println("EDM14B019_2");
    }
     if(id==2)
    {
      lcd.print("MDM14B013            CHAITANYA");
      delay(50);
      //Serial.println("MDM14B010");
    }
     if(id==13)
    {
      lcd.print("EDM14B013            G.ADARSA");
      delay(50);
      //Serial.println("EDM14B013");
    }
    
}

