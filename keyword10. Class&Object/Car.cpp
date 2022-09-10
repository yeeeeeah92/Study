#include <iostream>
#include <cstring>
#include "Car.h"
using namespace std;

void Car::InitMembers(char* ID, int fuel)
{
    strcpy(gamerID, ID);
    fuelGuage = fuel;
    curSpeed = 0;
}

void Car::ShowCarState()
{
    cout << " ID : " << gamerID << endl;
    cout << " fuel : " << fuelGuage << endl;
    cout << " speed : " << curSpeed << endl;
}

void Car::Accel()
{
    if(fuelGuage <= 0)
    {
        return ;
    }
    else
    {
        fuelGuage -= CAR_CONST::FUEL_STEP;
    }

    if((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD)
    {
        curSpeed = CAR_CONST::MAX_SPD;
        return ;
    } 

    curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break()
{
    if(curSpeed < CAR_CONST::BRK_STEP)
    {
        curSpeed = 0;
        return ;
    }

    curSpeed -= CAR_CONST::BRK_STEP;
}
