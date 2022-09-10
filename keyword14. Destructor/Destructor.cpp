#include <iostream>
#include <cstring>
using namespace std;

class Person
{
    private : 
        char * name;
        int age;
    public : 
        Person(char* myname, int myage)
        {
            int len = strlen(myname + 1);
            name = new char[len];
            strcpy(name, myname);
            age = myage;
        }
        void ShowPersonInfo() const
        {
            cout << " name : " << name << endl;
            cout << " age : " << age << endl;
        }
        ~Person()
        {
            delete []name;
            cout << "called destructor" << endl;
            cout << "name : " << name << endl;
        }
};

int main(void)
{
#if 0
    char* name1 = new char[strlen("Lee dongwoo")];
    char* name2 = new char[strlen("Jang donggun")];
    strcpy(name1, "Lee Dongwoo");
    strcpy(name2, "Jang Dong-gun");
    Person man1(name1, 29);
    Person man2(name2, 41);
#else
    Person man1((char*)("Lee dongwoo"), 29);
    Person man2((char*)("Jang Dong-gun"), 41);
#endif

    man1.ShowPersonInfo();
    man2.ShowPersonInfo();

    return 0;
}