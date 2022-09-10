#include <iostream>
#include "Point.h"
#include "Rectangle.h"
using namespace std;

int main(void)
{
    Point pos1;
    if(!pos1.InitMembers(-2, 4))
    {
        cout << "Init Failed. " << endl;
    }

    if(!pos1.InitMembers(2, 4))
    {
        cout << "Init Failed. " << endl;
    }

    Point pos2;
    if(!pos2.InitMembers(5, 9))
    {
        cout << "Init Failed. " << endl;
    }
    
    Rectangle rec;
    if(!rec.Initmembers(pos2, pos1))
    {
        cout << "Rec Init Failed. " << endl;
    }

    if(!rec.Initmembers(pos1, pos2))
    {
        cout << "Rec Init Failed. " << endl;
    }

    rec.ShowRecInfo();
    return 0;
}