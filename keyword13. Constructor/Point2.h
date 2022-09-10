#ifndef __POINT_H_
#define __POINT_H_

#include <iostream>
using namespace std;

class Point2
{
    private : 
        int xpos;
        int ypos;
    public : 
        Point2(const int &x, const int &y)
        {
            xpos = x;
            ypos = y;
        }
        int getX() const { return xpos; }
        int getY() const { return ypos; }

        bool setX(int x) 
        {
            if(x<0 || x>100)
            {
                cout << "xpos err" << endl;
                return false;
            }
            xpos = x;
            return true;
        }

        bool setY(int y) 
        {
            if(y<0 || y>100)
            {
                cout << "ypos err" << endl;
                return false;
            }
            ypos = y;
            return true;
        }

};

#endif