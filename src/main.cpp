#include <Arduino.h>
#include <AccelStepper.h>
#include "pin.h"

//--
int countCoin = 0;
int msCountDown = 0;
int sCountDown = 0;
enum CATCH_STATE_TYPEDEF
{
  IDLE = 0,
  MOVEING = 1,
  CATCHING = 2

} stateCatcher;

enum KEY_TYPEDEF
{

  MOVE = 1,
  CATCH = 2

} key;

void Callback_Coin()
{
  countCoin++;
}

void home()
{
  //move  x-  xsetspeed -

  while (1)
  {
    /*
if  position >100
break;
if  timecount >1000
break;
*/
    if (digitalRead(pinXlimit))
    {

      break;
    }
  }

  //move  y-  xsetspeed -

  while (1)
  {
    /*
if  position >100
break;
if  timecount >1000
break;
*/
    if (digitalRead(pinYlimit))
    {

      break;
    }
  }
  //move  Z-  xsetspeed -

  while (1)
  {
    /*
if  position >100
break;
if  timecount >1000
break;
*/
    if (digitalRead(pinZlimit))
    {

      break;
    }
  }
  //  XYZ set0
}

void stepperRunCtr()
{

  /*

if cureX>Xmax
if(Xspeed>0)
Xspeed=0;
 
if(digitalRead(pinXlimit)
if(Xspeed<0)
Xspeed=0;

if cureY>Ymax
if(Yspeed>0)
Yspeed=0;
 
if(digitalRead(pinYlimit)
if(Yspeed<0)
Yspeed=0;


if cureZ>Zmax
if(Zspeed>0)
Zspeed=0;
 
if(digitalRead(pinZlimit)
if(Zspeed<0)
Zspeed=0;
*/
}

void setup()
{
  // put your setup code here, to run once:

  attachInterrupt(pinCoin, Callback_Coin, RISING);
  stateCatcher = IDLE;
}

void loop()
{
  //

  // timer CountDown

  if (sCountDown > 0)
  {

    if (msCountDown > 0)
    {
      msCountDown--;
    }
    else
    {
      msCountDown = 100;
      sCountDown--;
    }
  }
  if (sCountDown == 1)
  {
    stateCatcher = CATCHING;
    sCountDown = 0;
  }
  // timer CountDown end
  switch (stateCatcher)
  {
  case IDLE:
    if (key == MOVE)
    {
      if (countCoin > 0)
      {
        countCoin--;
        stateCatcher = MOVEING;
        //start timer
        sCountDown = 20;
      }
      else
      {
        //  please insert coin
      }
    }
    break;
  case MOVEING:
    if (key == MOVE)
    {
      // set speed
    }
    else
    {
      //  stop
    }

    if (key == CATCHING)
    {
      stateCatcher = CATCHING;
      sCountDown = 0;
      //stop timer
    }

    break;
  case CATCHING:

    if (key == CATCHING)
    {
      // move down
      // catch
      //move up
      // random open
      //move orign
      stateCatcher = IDLE;
    }

    break;
  default:
    break;
  }
}