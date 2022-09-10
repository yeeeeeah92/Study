#include <iostream>
#include <cstring>
using namespace std;

class Person
{
    private : 
        char* name;
        int age;
    public : 
        Person(const char* myname, int myage) : age(myage)
        {
            name = new char[strlen(myname) + 1];
            strcpy(name, myname);
        }
        void ShowPersonInfo() const
        {
            cout << "Name : " << name << " " << reinterpret_cast <void*> (name) << endl;
            cout << "Age : " << age << endl;
            cout << "This : " << this << endl;
        }
        ~Person()
        {
            delete[] name;
            cout << "Called Destructor!" << endl;
        }
        Person& operator=(Person& ref)
        {
            delete[] name;
            name = new char[strlen(ref.name) + 1];
            strcpy(name, ref.name);
            age = ref.age;
            return *this;
        }
};

int main()
{
    Person man1("Lee dong woo", 29);
    Person man2("Yoon Ji yul", 22);
    man2 = man1;
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}