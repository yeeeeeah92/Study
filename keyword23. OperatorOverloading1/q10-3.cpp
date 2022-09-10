#include <iostream>
using namespace std;

class Point
{
    private : 
        int xpos, ypos;
    public : 
        Point(int x = 0, int y = 0) : xpos(x), ypos(y)
        { }
        void ShowPosition() const
        {
            cout << "(" << xpos << ", " << ypos << ")" << endl;
        }
        friend ostream& operator<<(ostream&, Point&);
        friend istream& operator>>(istream&, Point&);
};

ostream& operator<<(ostream& cout, Point& pos)
{
    cout << "(" << pos.xpos << ", " << pos.ypos << ")" << endl;
    return cout;
}
istream& operator>>(istream& cin, Point& pos)
{
    cin >> pos.xpos >> pos.ypos;
    return cin;
}

int main()
{
    Point pos1;
    cout << "x, y: ";
    cin >> pos1;
    cout << pos1;

    Point pos2;
    cout << "x, y: ";
    cin >> pos2;
    cout << pos2;
    return 0;
}