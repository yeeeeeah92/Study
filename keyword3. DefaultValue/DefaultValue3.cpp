#include <iostream>
using namespace std;

int BoxVolume(int length, int width = 1, int height = 2)
{
    return length * width * height;
}

int main()
{
    cout << "[3, 3, 3] : " << BoxVolume (3, 3, 3) << endl;
    cout << "[5, 5, D] : " << BoxVolume (5, 5) << endl;
    cout << "[7, D, D] : " << BoxVolume (7) << endl;
    // cout << "[D, D, D] : " << BoxVolume() << endl;   // Build Error

    return 0;
}