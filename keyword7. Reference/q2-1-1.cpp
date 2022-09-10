#include <iostream>
using namespace std;

void Increase(int &input)
{
    input++;
}

void Minus(int &input)
{
    input *= -1;
}

int main(void)
{
    int input;

    cout << "Input : ";
    cin >> input;

    Increase(input);
    cout << "Increase : " << input << endl;
    Minus(input);
    cout << "Minus : " << input << endl;

    return 0;
}