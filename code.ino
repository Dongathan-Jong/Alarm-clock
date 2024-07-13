/*
Author:        Jonathan Dong

Name:          Alarm Clock

Function:      This code is designed for four 7 seg displays 
               connected via CD4511 chips to display an alarm
               clock, attached to 3 buttons and a buzzer. 
*/

// define pins for right most digit
#define digit11 A5
#define digit12 A4
#define digit13 0
#define digit14 1

// define pins for right middle digit
#define digit21 2
#define digit22 3
#define digit23 4
#define digit24 5

// define pins for left middle digit
#define digit31 6
#define digit32 7
#define digit33 8
#define digit34 9

// define pins for left most digit
#define digit41 10
#define digit42 11
#define digit43 12
#define digit44 13

// define pins for buttons and buzzer
#define leftButton A1
#define middleButton A2
#define rightButton A3
#define buzzer A0

// create and initiate variables for minutes, seconds, and hours
int minutes = 0;
int seconds = 0;
int minutesTens = 0;
int minutesOnes = 0;
int hours = 12;
int hoursTens = 1;
int hoursOnes = 2;

// create and initiate variables for the time of alarm
int alarmMinute = 0;
int alarmMinuteOnes = 0;
int alarmMinuteTens = 0;
int alarmHour = 0;
int alarmHourOnes = 0;
int alarmHourTens = 0;

// create and intiate boolean variables
boolean middleButtonPressed = false;
boolean copyTime = false;

/* 
Function: setup()

Use:      Set up all pins used and starting time
*/

void setup()
{
  // set up pins for right most digit
  pinMode(digit11, OUTPUT);
  pinMode(digit12, OUTPUT);
  pinMode(digit13, OUTPUT);
  pinMode(digit14, OUTPUT);
  
  // set up pins for right middle digit
  pinMode(digit21, OUTPUT);
  pinMode(digit22, OUTPUT);
  pinMode(digit23, OUTPUT);
  pinMode(digit24, OUTPUT);
  
  // set up pins for left middle digit
  pinMode(digit31, OUTPUT);
  pinMode(digit32, OUTPUT);
  pinMode(digit33, OUTPUT);
  pinMode(digit34, OUTPUT);
 
  // set up pins for left most digit
  pinMode(digit41, OUTPUT);
  pinMode(digit42, OUTPUT);
  pinMode(digit43, OUTPUT);
  pinMode(digit44, OUTPUT);
  
  // set up pins for buttons and buzzer
  pinMode(leftButton, INPUT);
  pinMode(middleButton, INPUT);
  pinMode(rightButton, INPUT);
  pinMode(buzzer, OUTPUT);
  
  digitalWrite(digit32,HIGH);
  digitalWrite(digit41,HIGH);
}

/*
Function: loop()

Use:      Main loop of program
*/

void loop()
{
  // check if the clock is in alarm mode
  if(middleButtonPressed == false)
  {
    // check if the button is pressed
    if(digitalRead(middleButton) == 1)
    {
      // set clock to alarm mode and beep to tell user
      middleButtonPressed = true;
      copyTime = true;
      tone(buzzer,440,100);
      delay(5000);
    } 
  }
  
  // check if clock is in alarm mode
  if(middleButtonPressed)
  {
    // check if middle button is held
    if(digitalRead(middleButton) == 1)
    {
      // set clock out of alarm mode and beep to indicate
       middleButtonPressed = false;
       tone(buzzer,440,100);
       delay(5000);
      
    }
  }
 
  // check if clock is in alarm mode
  if(middleButtonPressed)
  {
    // call the alarm mode method
    alarmMode();
  }
 
  // check if the middle button is not pressed
  if(middleButtonPressed == false)
  {
    // increment the minutes if right button is held
    if(digitalRead(rightButton) == 1)
	{
      minutes++;
	  delay(100);
    }
    
    // increment the hours if left button is held
    if(digitalRead(leftButton) == 1)
    {
      hours++;
      delay(100);
    }
  }
  
  // check if the seconds counter hits 60 and reset 
  if(seconds == 60)
  {
    // reset seconds and add a minute
    seconds = 0;
    minutes++;
  }
  
  // check if the minutes counter hits 60 and reset
  if(minutes == 60)
  {
    // reset minutes and add an hour
    minutes = 0;
    hours++;
  }
  
  // check if the hours counter hits 24 and reset
  if(hours == 24)
  {
    // set all hour values to 0
   	hours = 0; 
    hoursOnes = 0;
    hoursTens = 0;
  }
  
  
  // increment up every minute for clock to function
  if(middleButtonPressed == false)
  {
    //CHANGE THIS VALUE TO CHANGE HOW FAST ONE SECOND IS
    //ONE SECOND = 1000
    delay(1000);
  	seconds++;
  }
  
  
  // get the ones and tens values of the minutes
  minutesOnes = minutes % 10;
  minutesTens = minutes / 10;
  
  // get the ones and tens values of the hours
  hoursOnes = hours % 10;
  hoursTens = hours / 10;
  
  // check if clock is not in alarm mode
  if(middleButtonPressed == false)
  {
    // update the time displayed
    updateTime();
  }
  
  // if the time lines up with the alarm time sound the alarm
  if(minutes == alarmMinute && hours == alarmHour && middleButtonPressed == false)
  {
    // wait for user to press the right button
    while(digitalRead(rightButton) == 0)
    {
      // beep until pressed
      tone(buzzer, 440,250);
      delay(500);
      
    }
  }
}

/*
Function: updateTime()

Use:      This method will display the time on the four 
		  7seg displays through the variables minutes and hours.
*/

void updateTime()
{
  // set the digit in the ones place for minutes
  switch(minutesOnes)
  {
    case 0:
    	// display 0
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
  
  // check which number is the tens value for minutes
  // display the number
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
  // check which number is the ones value for hours
  // display the number
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
  
  // check which number is the tens value for hours
  // display the number
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
  
/*
Function: alarmMode()

Use:      The clock will enter this method when the user is 
          setting the alarm time
*/
void alarmMode()
{
  // Copy the current time for the alarm to start
  if(copyTime)
  {
    alarmMinute = minutes;
    alarmHour = hours;
    copyTime = false;
  }
    
  // get the ones and tens values of the minutes
  alarmMinuteOnes = alarmMinute % 10;
  alarmMinuteTens = alarmMinute / 10;
  	
  // get the ones and tens values of the hours
  alarmHourOnes = alarmHour % 10;
  alarmHourTens = alarmHour / 10;
     
  // add minutes to the alarm when the right button is pressed
  if(digitalRead(rightButton) == 1)
  {
    alarmMinute++;
    delay(100);
  }
  
  // add hours to the alarm when the left button is pressed
  if(digitalRead(leftButton) == 1)
  {
    alarmHour++;
    delay(100);
  }
  
  // reset the clock when the user sets 24 hours
  if(alarmHour == 24)
  {
    // set hours to 0
   	alarmHour = 0; 
    alarmHourOnes = 0;
    alarmHourTens = 0;
  }
  
  // reset the minutes when the user sets higher than 60 minutes and add an hour
  if(alarmMinute == 60)
  {
    // set hours to 0
   	alarmHour++; 
  }
  
 
  
  // check which number is the ones value for minutes
  // display the number
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
  // check which number is the tens value for minutes
  // display the number
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
  // check which number is the ones value for hours
  // display the number
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
  
  // check which number is the tens value for hours
  // display the number
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
