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
        Point operator+(const Point &ref)   // 이 함수가 정의되어 있지 않아도 정상적으로 출력이 되는 이유? *- 해도 왜 다 덧셈 결과로 나오지?
        {
            Point pos(xpos+ref.xpos, ypos+ref.ypos);
            return pos;
        }
};

int main()
{
    Point pos1(3, 4);
    Point pos2(10, 20);
    Point pos3 = pos1 + pos2;

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();

    return 0;
}