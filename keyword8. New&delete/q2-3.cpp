#include <iostream>
using namespace std;
typedef struct __point
{
    int xpos;
    int ypos;
}point;

point& pointAdder(const point &p1, const point &p2)
{
    point * pr = new point;
    pr->xpos = p1.xpos + p2.xpos;
    pr->ypos = p1.ypos + p2.ypos;

    return *pr;
}

int main(void)
{
    point * p1 = new point;
    point * p2 = new point;

    p1->xpos = 10;
    p1->ypos = 11;

    p2->xpos = 20;
    p2->ypos = 21;

    point& result = pointAdder(*p1, *p2);

    cout << "p1(" << p1->xpos << ", " << p1->ypos << ")" << endl;
    cout << "p2(" << p2->xpos << ", " << p2->ypos << ")" << endl;
    cout << "result(" << result.xpos << ", " << result.ypos << ")" << endl;
    
    delete p1;
    delete p2;
    delete &result;

    return 0;
}