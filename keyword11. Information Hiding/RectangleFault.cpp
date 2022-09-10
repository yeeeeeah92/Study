#include <iostream>
using namespace std;

class Point
{
    public : 
        int x;
        int y;
};

class Rectangle
{
    public : 
        Point upLeft;
        Point lowRight;

    public : 
        void ShowRecInfo()
        {
            cout << "[" << upLeft.x << ", " << upLeft.y << "]" << endl;
            cout << "[" << lowRight.x << ", " << lowRight.y << "]" << endl;
        }
};

int main()
{
    // 멤버변수가 public인 경우 구조체 변수 초기화와 유사한 방식으로 초기화가 가능하다.
    Point pos1 = {-2, 4};
    Point pos2 = {5, 9};
    Rectangle rec = {pos2, pos1};

    rec.ShowRecInfo();
    return 0;
}