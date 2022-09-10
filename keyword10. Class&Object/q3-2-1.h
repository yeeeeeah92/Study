#include <iostream>
using namespace std;

namespace CAL_CONST
{
    enum
    {
        ADD = 0,
        DIV,
        MIN,
        MUL,
        NUM_OF_OPER
    };
}

class Calculator
{
    private : 
        int operCnt[CAL_CONST::NUM_OF_OPER];
    public : 
        void Init();
        float Add(float a, float b);
        float Div(float a, float b);
        float Min(float a, float b);
        float Mul(float a, float b);
        void ShowOpCount();
};

void Calculator::Init()
{
    for(int i = 0; i < CAL_CONST::NUM_OF_OPER; i++)
    {
        operCnt[i] = 0;
    }
}

float Calculator::Add(float a, float b)
{
    operCnt[CAL_CONST::ADD]++;
    return a+b;
}

float Calculator::Div(float a, float b)
{
    operCnt[CAL_CONST::DIV]++;
    return a/b;
}

float Calculator::Min(float a, float b)
{
    operCnt[CAL_CONST::MIN]++;
    return a-b;
}

float Calculator::Mul(float a, float b)
{
    operCnt[CAL_CONST::MUL]++;
    return a*b;
}

void Calculator::ShowOpCount()
{
    cout << "ADD : " << operCnt[CAL_CONST::ADD] << endl;
    cout << "DIV : " << operCnt[CAL_CONST::DIV] << endl;
    cout << "MIN : " << operCnt[CAL_CONST::MIN] << endl;
    cout << "MUL : " << operCnt[CAL_CONST::MUL] << endl;
}