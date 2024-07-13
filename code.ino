
#define digit11 A5
#define digit12 A4
#define digit13 0
#define digit14 1

#define digit21 2
#define digit22 3
#define digit23 4
#define digit24 5

#define digit31 6
#define digit32 7
#define digit33 8
#define digit34 9

#define digit41 10
#define digit42 11
#define digit43 12
#define digit44 13

#define leftButton A1
#define middleButton A2
#define rightButton A3
#define buzzer A0

int minutes = 12;
int seconds = 30;
int minutesTens = 0;
int minutesOnes = 0;
int hours = 12;
int hoursTens = 1;
int hoursOnes = 2;
int time = 0000;

int alarmMinute = 0;
int alarmMinuteOnes = 0;
int alarmMinuteTens = 0;
int alarmHour = 0;
int alarmHourOnes = 0;
int alarmHourTens = 0;

boolean middleButtonPressed = false;
boolean copyTime = false;

void setup()
{
  pinMode(digit11, OUTPUT);
  pinMode(digit12, OUTPUT);
  pinMode(digit13, OUTPUT);
  pinMode(digit14, OUTPUT);
  
  pinMode(digit21, OUTPUT);
  pinMode(digit22, OUTPUT);
  pinMode(digit23, OUTPUT);
  pinMode(digit24, OUTPUT);
  
  pinMode(digit31, OUTPUT);
  pinMode(digit32, OUTPUT);
  pinMode(digit33, OUTPUT);
  pinMode(digit34, OUTPUT);
 
  pinMode(digit41, OUTPUT);
  pinMode(digit42, OUTPUT);
  pinMode(digit43, OUTPUT);
  pinMode(digit44, OUTPUT);
  
  pinMode(leftButton, INPUT);
  pinMode(middleButton, INPUT);
  pinMode(rightButton, INPUT);
  pinMode(buzzer, OUTPUT);
  
  digitalWrite(digit32,HIGH);
  digitalWrite(digit41,HIGH);
}


void loop()
{
  if(middleButtonPressed == false)
  {
    if(digitalRead(middleButton) == 1)
    {
      middleButtonPressed = true;
      copyTime = true;
      tone(buzzer,440,100);
      delay(5000);
    } 
  }
  
  if(middleButtonPressed)
  {
    if(digitalRead(middleButton) == 1)
    {
       middleButtonPressed = false;
       tone(buzzer,440,100);
       delay(5000);
      
    }
  }
 
  if(middleButtonPressed)
  {
    alarmMode();
  }
 
  if(middleButtonPressed == false)
  {if(digitalRead(leftButton) == 1)
    {
      hours++;
      delay(100);
    }
    if(digitalRead(rightButton) == 1)
	{
      minutes++;
	  delay(100);
    
    
  }

	if(seconds == 60)
  {
    seconds = 0;
    minutes++;
  }
  if(hours == 24)
  {
   	hours = 0; 
    hoursOnes = 0;
    hoursTens = 0;
  }
  if(minutes == 60)
  {
    minutes = 0;
    hours--;
  }
  
  
  minutesOnes = minutes % 10;
  minutesTens = minutes / 10;
  
  if(middleButtonPressed == false)
  {
    delay(1012);
  	seconds++;
  }

    minutesOnes = minutes % 10;
  minutesTens = minutes / 10;
  
  hoursOnes = hours % 10;
  hoursTens = hours / 10;
  
  if(middleButtonPressed == false)
  {
    updateTime();
  }
  
  if(minutes == alarmMinute && hours == alarmHour && middleButtonPressed == false)
  {
    while(digitalRead(rightButton) == 0)
    {
      tone(buzzer, 440,250);
      delay(500);
      
    }
  }
}


void updateTime()
{
  switch(minutesOnes)
  {
    case 0:
    	digitalWrite(digit11,LOW);
    	digitalWrite(digit12,LOW);
    	digitalWrite(digit13,LOW);
    	digitalWrite(digit14,LOW);
    	break;
    case 1:
    	// display 1
    	digitalWrite(digit11,LOW);
    	digitalWrite(digit12,LOW);
    	digitalWrite(digit13,LOW);
    	digitalWrite(digit14,LOW);
     	digitalWrite(digit11,HIGH);
    	break;
    case 2:
    	// display 2
    	digitalWrite(digit11,LOW);
    	digitalWrite(digit12,LOW);
    	digitalWrite(digit13,LOW);
    	digitalWrite(digit14,LOW);
    	digitalWrite(digit12,HIGH);
    	break;
    case 3:
    	// display 3
    	digitalWrite(digit11,LOW);
    	digitalWrite(digit12,LOW);
    	digitalWrite(digit13,LOW);
    	digitalWrite(digit14,LOW);
    	digitalWrite(digit11,HIGH);
    	digitalWrite(digit12,HIGH);
    	break;
    case 4:
    	// display 4
    	digitalWrite(digit11,LOW);
    	digitalWrite(digit12,LOW);
    	digitalWrite(digit13,LOW);
    	digitalWrite(digit14,LOW);
    	digitalWrite(digit13,HIGH);
    	break;
    case 5:
    	// display 5
   	    digitalWrite(digit11,LOW);
    	digitalWrite(digit12,LOW);
    	digitalWrite(digit13,LOW);
    	digitalWrite(digit14,LOW);
    	digitalWrite(digit11,HIGH);
    	digitalWrite(digit13,HIGH);
    	break;
    case 6:
    	// display 6
    	digitalWrite(digit11,LOW);
    	digitalWrite(digit12,LOW);
    	digitalWrite(digit13,LOW);
    	digitalWrite(digit14,LOW);
    	digitalWrite(digit12,HIGH);
    	digitalWrite(digit13,HIGH);
    	break;
    case 7:
    	// display 7
    	digitalWrite(digit11,LOW);
    	digitalWrite(digit12,LOW);
    	digitalWrite(digit13,LOW);
    	digitalWrite(digit14,LOW);
    	digitalWrite(digit11,HIGH);
    	digitalWrite(digit12,HIGH);
    	digitalWrite(digit13,HIGH);
    	break;
    case 8:
    	// display 8
    	digitalWrite(digit11,LOW);
    	digitalWrite(digit12,LOW);
    	digitalWrite(digit13,LOW);
    	digitalWrite(digit14,LOW);
    	digitalWrite(digit14,HIGH);
    	break;
    case 9:
    	// display 9
    	digitalWrite(digit11,LOW);
    	digitalWrite(digit12,LOW);
    	digitalWrite(digit13,LOW);
    	digitalWrite(digit14,LOW);
    	digitalWrite(digit11,HIGH);
    	digitalWrite(digit14,HIGH);
    	break;
  }
  
  switch(minutesTens)
  {
    case 0:
    	// display 0
    	digitalWrite(digit21,LOW);
    	digitalWrite(digit22,LOW);
    	digitalWrite(digit23,LOW);
    	digitalWrite(digit24,LOW);
    	break;
    case 1:
    	// display 1
    	digitalWrite(digit21,LOW);
    	digitalWrite(digit22,LOW);
    	digitalWrite(digit23,LOW);
    	digitalWrite(digit24,LOW);
    	digitalWrite(digit21,HIGH);
    	break;
    case 2:
    	// display 2
    	digitalWrite(digit21,LOW);
    	digitalWrite(digit22,LOW);
    	digitalWrite(digit23,LOW);
    	digitalWrite(digit24,LOW);
    	digitalWrite(digit22,HIGH);
    	break;
    case 3:
    	// display 3
    	digitalWrite(digit21,LOW);
    	digitalWrite(digit22,LOW);
    	digitalWrite(digit23,LOW);
    	digitalWrite(digit24,LOW);
    	digitalWrite(digit21,HIGH);
    	digitalWrite(digit22,HIGH);
    	break;
    case 4:
    	// display 4
    	digitalWrite(digit21,LOW);
    	digitalWrite(digit22,LOW);
    	digitalWrite(digit23,LOW);
    	digitalWrite(digit24,LOW);
    	digitalWrite(digit23,HIGH);
    	break;
    case 5:
    	// display 5
    	digitalWrite(digit21,HIGH);
    	digitalWrite(digit23,HIGH);
    	break;
    case 6:
    	// display 6
    	digitalWrite(digit21,LOW);
    	digitalWrite(digit22,LOW);
    	digitalWrite(digit23,LOW);
    	digitalWrite(digit24,LOW);
    	digitalWrite(digit22,HIGH);
    	digitalWrite(digit23,HIGH);
    	break;
  }
  switch(hoursOnes)
  {
    case 0:
    	// display 0
    	digitalWrite(digit31,LOW);
    	digitalWrite(digit32,LOW);
    	digitalWrite(digit33,LOW);
    	digitalWrite(digit34,LOW);
    	break;
    case 1:
    	// display 1
    	digitalWrite(digit31,LOW);
    	digitalWrite(digit34,LOW);
    	digitalWrite(digit32,LOW);
    	digitalWrite(digit33,LOW);
    	digitalWrite(digit31,HIGH);
    	break;
    case 2:
    	// display 2
    	digitalWrite(digit31,LOW);
    	digitalWrite(digit34,LOW);
    	digitalWrite(digit32,LOW);
    	digitalWrite(digit33,LOW);
    	digitalWrite(digit32,HIGH);
    	break;
    case 3:
    	// display 3
    	digitalWrite(digit31,LOW);
    	digitalWrite(digit34,LOW);
    	digitalWrite(digit32,LOW);
    	digitalWrite(digit33,LOW);
    	digitalWrite(digit31,HIGH);
    	digitalWrite(digit32,HIGH);
    	break;
    case 4:
    	// display 4
    	digitalWrite(digit31,LOW);
    	digitalWrite(digit34,LOW);
    	digitalWrite(digit32,LOW);
    	digitalWrite(digit33,LOW);
    	digitalWrite(digit33,HIGH);
    	break;
    case 5:
    	// display 5
    	digitalWrite(digit31,LOW);
    	digitalWrite(digit34,LOW);
    	digitalWrite(digit32,LOW);
    	digitalWrite(digit33,LOW);
    	digitalWrite(digit31,HIGH);
    	digitalWrite(digit33,HIGH);
    	break;
    case 6:
    	// display 6
    	digitalWrite(digit31,LOW);
    	digitalWrite(digit34,LOW);
    	digitalWrite(digit32,LOW);
    	digitalWrite(digit33,LOW);
    	digitalWrite(digit32,HIGH);
    	digitalWrite(digit33,HIGH);
    	break;
    case 7:
    	// display 7
    	digitalWrite(digit31,LOW);
    	digitalWrite(digit34,LOW);
    	digitalWrite(digit32,LOW);
    	digitalWrite(digit33,LOW);
    	digitalWrite(digit31,HIGH);
    	digitalWrite(digit32,HIGH);
    	digitalWrite(digit33,HIGH);
    	break;
    case 8:
    	// display 8
    	digitalWrite(digit31,LOW);
    	digitalWrite(digit34,LOW);
    	digitalWrite(digit32,LOW);
    	digitalWrite(digit33,LOW);
    	digitalWrite(digit34,HIGH);
    	break;
    case 9:
    	// display 9
    	digitalWrite(digit31,LOW);
    	digitalWrite(digit34,LOW);
    	digitalWrite(digit32,LOW);
    	digitalWrite(digit33,LOW);
    	digitalWrite(digit31,HIGH);
    	digitalWrite(digit34,HIGH);
    	break;
  }
  
  switch(hoursTens)
  {
    case 0:
    	// display 0
    	digitalWrite(digit42,LOW);
    	digitalWrite(digit41,LOW);
    	digitalWrite(digit43,LOW);
    	break;
    case 1:
    	// display 1
    	digitalWrite(digit41,HIGH);
    	break;
    case 2:
    	// display 2
    	digitalWrite(digit41,LOW);
    	digitalWrite(digit42,HIGH);
    	break;
  }
}


void alarmMode()
{
  if(copyTime)
  {
    alarmMinute = minutes;
    alarmHour = hours;
    copyTime = false;
  }
    
  alarmMinuteOnes = alarmMinute % 10;
  alarmMinuteTens = alarmMinute / 10;
  	
  alarmHourOnes = alarmHour % 10;
  alarmHourTens = alarmHour / 10;
     
  if(digitalRead(rightButton) == 1)
  {
    alarmMinute++;
    delay(100);
  }
  
  if(digitalRead(leftButton) == 1)
  {
    alarmHour++;
    delay(100);
  }
  
  if(alarmHour == 24)
  {
    // set hours to 0
   	alarmHour = 0; 
    alarmHourOnes = 0;
    alarmHourTens = 0;
  }
  
  if(alarmMinute == 60)
  {
    // set hours to 0
   	alarmHour++; 
  }
  
 
  
  switch(alarmMinuteOnes)
  {
    case 0:
    	// display 0
    	digitalWrite(digit11,LOW);
    	digitalWrite(digit14,LOW);
    	break;
    case 1:
    	// display 1
    	digitalWrite(digit11,HIGH);
    	break;
    case 2:
    	// display 2
    	digitalWrite(digit11,LOW);
    	digitalWrite(digit12,HIGH);
    	break;
    case 3:
    	// display 3
    	digitalWrite(digit11,HIGH);
    	digitalWrite(digit12,HIGH);
    	break;
    case 4:
    	// display 4
    	digitalWrite(digit11,LOW);
    	digitalWrite(digit12,LOW);
    	digitalWrite(digit13,HIGH);
    	break;
    case 5:
    	// display 5
    	digitalWrite(digit11,HIGH);
    	digitalWrite(digit13,HIGH);
    	break;
    case 6:
    	// display 6
    	digitalWrite(digit12,HIGH);
    	digitalWrite(digit13,HIGH);
    	digitalWrite(digit11,LOW);
    	break;
    case 7:
    	// display 7
    	digitalWrite(digit11,HIGH);
    	digitalWrite(digit12,HIGH);
    	digitalWrite(digit13,HIGH);
    	break;
    case 8:
    	// display 8
    	digitalWrite(digit11,LOW);
    	digitalWrite(digit12,LOW);
    	digitalWrite(digit13,LOW);
    	digitalWrite(digit14,HIGH);
    	break;
    case 9:
    	// display 9
    	digitalWrite(digit11,HIGH);
    	digitalWrite(digit14,HIGH);
    	break;
  }
  switch(alarmMinuteTens)
  {
    case 0:
    	// display 0
    	digitalWrite(digit22,LOW);
    	digitalWrite(digit21,LOW);
    	digitalWrite(digit23,LOW);
    	break;
    case 1:
    	// display 1
    	digitalWrite(digit21,HIGH);
    	break;
    case 2:
    	// display 2
    	digitalWrite(digit21,LOW);
    	digitalWrite(digit22,HIGH);
    	break;
    case 3:
    	// display 3
    	digitalWrite(digit21,HIGH);
    	digitalWrite(digit22,HIGH);
    	break;
    case 4:
    	// display 4
    	digitalWrite(digit21,LOW);
    	digitalWrite(digit22,LOW);
    	digitalWrite(digit23,HIGH);
    	break;
    case 5:
    	// display 5
    	digitalWrite(digit21,HIGH);
    	digitalWrite(digit23,HIGH);
    	break;
    case 6:
    	// display 6
    	digitalWrite(digit22,HIGH);
    	digitalWrite(digit23,HIGH);
    	digitalWrite(digit21,LOW);
    	break;
  }
  switch(alarmHourOnes)
  {
    case 0:
    	// display 0
    	digitalWrite(digit31,LOW);
    	digitalWrite(digit34,LOW);
    	digitalWrite(digit32,LOW);
    	break;
    case 1:
    	// display 1
    	digitalWrite(digit31,HIGH);
    	break;
    case 2:
    	// display 2
    	digitalWrite(digit31,LOW);
    	digitalWrite(digit32,HIGH);
    	break;
    case 3:
    	// display 3
    	digitalWrite(digit31,HIGH);
    	digitalWrite(digit32,HIGH);
    	break;
    case 4:
    	// display 4
    	digitalWrite(digit31,LOW);
    	digitalWrite(digit32,LOW);
    	digitalWrite(digit33,HIGH);
    	break;
    case 5:
    	// display 5
    	digitalWrite(digit31,HIGH);
    	digitalWrite(digit33,HIGH);
    	break;
    case 6:
    	// display 6
    	digitalWrite(digit32,HIGH);
    	digitalWrite(digit33,HIGH);
    	digitalWrite(digit31,LOW);
    	break;
    case 7:
    	// display 7
    	digitalWrite(digit31,HIGH);
    	digitalWrite(digit32,HIGH);
    	digitalWrite(digit33,HIGH);
    	break;
    case 8:
    	// display 8
    	digitalWrite(digit31,LOW);
    	digitalWrite(digit32,LOW);
    	digitalWrite(digit33,LOW);
    	digitalWrite(digit34,HIGH);
    	break;
    case 9:
    	// display 9
    	digitalWrite(digit31,HIGH);
    	digitalWrite(digit34,HIGH);
    	break;
  }
  
  switch(alarmHourTens)
  {
    case 0:
    	// display 0
    	digitalWrite(digit42,LOW);
    	digitalWrite(digit41,LOW);
    	digitalWrite(digit43,LOW);
    	break;
    case 1:
    	// display 1
    	digitalWrite(digit41,HIGH);
    	break;
    case 2:
    	// display 2
    	digitalWrite(digit41,LOW);
    	digitalWrite(digit42,HIGH);
    	break;
  }
}
