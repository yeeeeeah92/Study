#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
    enum
    {
        CLERK,
        SENIOR,
        ASSIST,
        MANAGE
    };

    void ShowPosition(int num)
    {
        switch(num)
        {
            case CLERK : 
                cout << "Level : CLERK" << endl;
                break;
            case SENIOR : 
                cout << "Level : SENIOR" << endl;
                break;
            case ASSIST : 
                cout << "Level : ASSIST" << endl;
                break;
            case MANAGE : 
                cout << "Level : MANAGE" << endl;
                break;
        }
    }
};

class NameCard
{
    private :
        char* name;
        char* company;
        char* phone;
        int level;
    public : 
        NameCard(char* manName, char* manCompany, char* manPhone, int manLevel) : level(manLevel)
        {
            name = new char[strlen(manName) + 1];
            company = new char[strlen(manCompany) + 1];
            phone = new char[strlen(manPhone) + 1];

            strcpy(name, manName);
            strcpy(company, manCompany);
            strcpy(phone, manPhone);
        }

        void ShowNameCardInfo()
        {
            cout << "Name : " << name << endl;
            cout << "Company : " << company << endl;
            cout << "Phone : " << phone << endl;
            COMP_POS::ShowPosition(level);
            cout << endl;
        }

        ~NameCard()
        {   // Question. Delete 후에도 값이 출력되는 이유는 그냥 메모리에 남은 쓰레기값?
            delete []name;
            delete []company;
            delete []phone;

            //ShowNameCardInfo();
        }
};

int main(void)
{
    NameCard manClerk((char*)"Lee", (char*)"ABCEng", (char*)"010-1111-2222", COMP_POS::CLERK);
    NameCard manSenior((char*)"Hong", (char*)"OrangeEng", (char*)"010-3333-4444", COMP_POS::SENIOR);
    NameCard manAssist((char*)"Kim", (char*)"SoGoodComp", (char*)"010-5555-6666", COMP_POS::ASSIST);

    manClerk.ShowNameCardInfo();
    manSenior.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();

    return 0;
}