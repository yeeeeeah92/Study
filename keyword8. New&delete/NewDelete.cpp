#include <iostream>
#include <string.h>
using namespace std;

int main(void)
{
    char* str = new char[20]; // char *str = MakeStrAdr(20);
    strcpy(str, "I am so happy~");
    cout << str << endl;
    delete(str); // free(str);

    return 0;
}