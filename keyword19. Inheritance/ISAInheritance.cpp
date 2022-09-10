#include <iostream>
#include <cstring>
using namespace std;

class Computer
{
    private : 
        char owner[50];
    public : 
        Computer(const char* name)
        {
            strcpy(owner, name);
        }
        void Calculate()
        {
            cout << "calculating... " << endl;
        }
};

class NotebookComp : public Computer
{
    private : 
        int Battery;
    public : 
        NotebookComp(const char* name, int initChag) : Computer(name), Battery(initChag)
        { }
        void Charging() { Battery += 5; }
        void UseBattery() { Battery -= 1; }
        void MovingCal()
        {
            if(GetBatteryInfo() < 1)
            {
                cout << "need to charge" << endl;
                return ;
            }
            cout << "moving  ";
            Calculate();
            UseBattery();
        }
        int GetBatteryInfo() { return Battery; }

};

class TabletNotebook : public NotebookComp
{
    private : 
        char regstPenModel[50];
    public : 
        TabletNotebook(const char* name, int initChag, const char* pen) : NotebookComp(name, initChag)
        {
            strcpy(regstPenModel, pen);
        }
        void Write(const char* penInfo)
        {
            if(GetBatteryInfo() < 1)
            {
                cout << "need to charge" << endl;
                return ;
            }
            if(strcmp(regstPenModel, penInfo) != 0)
            {
                cout << "not registed pen" << endl;
                return ;
            }
            cout << "processing" << endl;
            UseBattery();
        }
};

int main()
{
    NotebookComp nc("lee", 5);
    TabletNotebook tn("jung", 5, "ISE-241-242");
    nc.MovingCal();
    tn.Write("ISE-241-242");
    return 0;
}