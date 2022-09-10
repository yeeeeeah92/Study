#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include "Point2.h"

class Rectangle
{
    private : 
        Point2 upLeft;
        Point2 lowRight;
    public : 
        Rectangle(const int &x1, const int &y1, const int &x2, const int &y2):upLeft(x1,y1), lowRight(x2,y2)
        {
            // empty
        }
        void ShowRecInfo() const
        {
            cout << "(" << upLeft.getX() << ", " << upLeft.getY() << "), (" << lowRight.getX() << ", " << lowRight.getY() << ")" << endl;
        }
};

#endif