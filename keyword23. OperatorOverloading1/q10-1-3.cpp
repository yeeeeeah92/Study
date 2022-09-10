#include <iostream>
using namespace std;

class Point
{
    private : 
        int xpos, ypos;
    public : 
        Point(int x=0, int y=0) : xpos(x), ypos(y)
        { }
        void ShowPosition() const
        {
            cout << "(" << xpos << ", " << ypos << ")" << endl;
        }
        friend Point operator+(const Point &pos1, const Point &pos2);
        friend Point operator-(const Point &pos1, const Point &pos2);
        friend Point operator+=(Point &pos1, const Point &pos2);
        friend Point operator-=(Point &pos1, const Point &pos2);
        friend bool operator==(const Point &pos1, const Point &pos2);
        friend bool operator!=(const Point &pos1, const Point &pos2);
};

Point operator+(const Point &pos1, const Point &pos2)
{
    Point pos(pos1.xpos+pos2.xpos, pos1.ypos+pos2.ypos);
    return pos;
}

Point operator-(const Point &pos1, const Point &pos2)
{
    Point pos(pos1.xpos-pos2.xpos, pos1.ypos-pos2.ypos);
    return pos;
}

Point operator+=(Point &pos1, const Point &pos2)
{
    pos1.xpos = pos1.xpos + pos2.xpos;
    pos1.ypos = pos1.ypos + pos2.ypos;
    return pos1;
}

Point operator-=(Point &pos1, const Point &pos2)
{
    pos1.xpos = pos1.xpos - pos2.xpos;
    pos1.ypos = pos1.ypos - pos2.ypos;
    return pos1;
}

bool operator==(const Point &pos1, const Point &pos2)
{
    return (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos);
}

bool operator!=(const Point &pos1, const Point &pos2)
{
    return ((pos1.xpos != pos2.xpos) || (pos1.ypos != pos2.ypos));
}

int main()
{
    Point pos1(3, 4);
    Point pos2(10, 20);
    Point pos3=pos1;
    Point pos4=pos1+pos2;

    if(pos1==pos3)
    {
        cout << "pos1 == pos3" << endl;
    }
    else
    {
        cout << "pos1 != pos3" << endl;
    }

    if(pos1==pos4)
    {
        cout << "pos1 == pos4" << endl;
    }
    else
    {
        cout << "pos1 != pos4" << endl;
    }

    return 0;
}