#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
    private : 
        char* name;
        int age;
    public : 
        MyFriendInfo(const char* myname, int myage) : age(myage)
        {
            name = new char[strlen(myname) + 1];
            strcpy(name, myname);
            cout << "Called MyFriendInfo(" << myname << ", " << myage << ")" << endl;
        }
        void ShowMyFriendInfo()
        {
            cout << "name : " << name << endl;
            cout << "age : " << age << endl;
        }
        ~MyFriendInfo()
        {
            delete[] name;
            cout << "Called ~MyFriendInfo()" << endl;
        }
};

class MyFriendDetailInfo : public MyFriendInfo
{
    private : 
        char *addr;
        char *phone;
    public : 
        MyFriendDetailInfo(const char* myname, int myage, const char* myaddr, const char* myphone) : MyFriendInfo(myname, myage)
        {
            addr = new char[strlen(myaddr) + 1];
            strcpy(addr, myaddr);
            phone = new char[strlen(myphone) + 1];
            strcpy(phone, myphone);
            cout << "Called MyFriendDetailInfo(" << myname << ", " << myage << ", " << myaddr << ", " << myphone << ")" << endl;
        }
        void ShowMyFriendDetailInfo()
        {
            ShowMyFriendInfo();
            cout << "addr : " << addr << endl;
            cout << "phone : " << phone << endl;
        }
        ~MyFriendDetailInfo()
        {
            delete[] addr;
            delete[] phone;
            cout << "Called ~MyFriendDetailInfo()" << endl;
        }
};

int main()
{
    MyFriendDetailInfo fri("Lee", 27, "jungja", "01077109064");
    fri.ShowMyFriendDetailInfo();

    return 0;
}