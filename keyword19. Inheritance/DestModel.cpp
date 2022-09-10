#include <iostream>
#include <cstring>
using namespace std;

class Person
{
    private : 
        int age;
        char *name;
    public : 
        Person(int myage, const char* myname) : age(myage)
        {
            name = new char[strlen(myname)+1];
            strcpy(name, myname);
        }
        void WhatYourName() const
        {
            cout << "My name is " << name << endl;
        }
        void HowOldAreYou() const
        {
            cout << "I'm " << age << " years old" << endl;
        }
        ~Person()
        {
            cout << "Delete name" << endl;
            delete[] name;
        }
};

class UnivStudent : public Person
{
    private : 
        char *major;
    public : 
        UnivStudent(const char* myname, int myage, const char* mymajor) : Person(myage, myname)
        {
            major = new char[strlen(mymajor)+1];
            strcpy(major, mymajor);
        }
        void WhoAreYou()
        {
            WhatYourName();
            HowOldAreYou();
            cout << "My major is " << major << endl << endl;
        }
        ~UnivStudent()
        {
            cout << "Delete major" << endl;
            delete[] major;
        }
};

int main()
{
    UnivStudent ustd1("Lee", 22, "Computer Eng");
    ustd1.WhoAreYou();

    UnivStudent ustd2("Yoon", 23, "Electronic Eng");
    ustd2.WhoAreYou();

    return 0;
}