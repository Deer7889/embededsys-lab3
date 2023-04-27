#include "mbed.h"       //mbed library
#include "MMA7660.h"    //accelerometer library

#define PI 3.1415926    //set value for ╥ 

MMA7660 MMA(p28, p27);          //define accelerometer pins
DigitalOut connectionLed(LED1); //define LED1 as connectionLed

float calculateAngle(float x, float y, float z) //define variables and calculateAngle
{                      //start angle calculation loop
    float angle = 0;                    //set angle to 0
    float bott_part=sqrt((y*y)+(z*z));  //calculations under division bar
    angle=atan(x/bott_part);            //trigomoetric function application
    angle=(angle*180)/PI;               //convert angle to dergees for printout
     return angle;                      //terminate function and return value
}                       //end float calculation loop

int main() {            //start main program

    if (MMA.testConnection())   //check accelerometer connected
        connectionLed = 1;      //light LED1 if connected
        
    while(1)                //while loop for lcd print out
    {                       //start print loop     
        printf("angle is %f \r\n", calculateAngle(MMA.x(), MMA.y(), MMA.z())); //print angle to lcd
        wait(1);                //wait to read lcd
    }                       //close print loop