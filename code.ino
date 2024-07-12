
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
  
}
