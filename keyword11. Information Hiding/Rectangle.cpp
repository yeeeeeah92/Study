#include <iostream>
#include "Rectangle.h"
using namespace std;

bool Rectangle::Initmembers(const Point &ul, const Point &lr)
{
    if(ul.GetX() > lr.GetX() || ul.GetY() > lr.GetY())
    {
        cout << "point error" << endl;
        return false;
    }

    upLeft = ul;
    lowRight = lr;

    return true;
}

void Rectangle::ShowRecInfo() const
{
    cout << "(" << upLeft.GetX() << ", " << upLeft.GetY() << "), (" << lowRight.GetX() << ", " << lowRight.GetY() << ")" << endl;
}