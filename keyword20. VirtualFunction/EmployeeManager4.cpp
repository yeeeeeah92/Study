#include <iostream>
#include <cstring>
using namespace std;

class Employee  // abstract class
{
    private : 
        char name[100];
    public : 
        Employee(const char* name)
        {
            strcpy(this->name, name);
        }
        void ShowYourName() const
        {
            cout << "name : " << name << endl;
        }
        virtual int GetPay() const = 0; // pure virtual function
        virtual void ShowSalaryInfo() const = 0;    // pure virtual function
};

class PermanentWorker : public Employee
{
    private : 
        int salary;
    public : 
        PermanentWorker(const char* name, int money) : Employee(name), salary(money)
        { }
        virtual int GetPay() const { return salary; }
        virtual void ShowSalaryInfo() const
        {
            ShowYourName();
            cout << "salary : " << GetPay() << endl << endl;
        }
};

class TemporaryWorker : public Employee
{
    private : 
        int workTime;
        int payPerHour;
    public : 
        TemporaryWorker(const char* name, int pay) : Employee(name), workTime(0), payPerHour(pay)
        { }
        void AddWorkTime(int time)
        {
            workTime += time;
        }
        virtual int GetPay() const { return workTime*payPerHour; }
        virtual void ShowSalaryInfo() const
        {
            ShowYourName();
            cout << "salary : " << GetPay() << endl << endl;
        }
};

class SalesWorker : public PermanentWorker
{
    private : 
        int salesResult;
        double bonusRatio;
    public : 
        SalesWorker(const char* name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
        { }
        void AddSalesResult(int value)
        {
            salesResult += value;
        }
        virtual int GetPay() const  // function overriding
        { 
            return PermanentWorker::GetPay() + (int)(salesResult*bonusRatio); 
        }
        virtual void ShowSalaryInfo() const
        {
            ShowYourName();
            cout << "salary : " << GetPay() << endl << endl;
        }
};

class EmployeeHandler
{
    private : 
        Employee* empList[50];
        int empNum;
    public : 
        EmployeeHandler() : empNum(0) 
        { }
        void AddEmployer(Employee* emp)
        {
            empList[empNum++] = emp;
        }
        void ShowAllSalaryInfo() const
        {
            for(int i = 0; i < empNum; i++)
                empList[i]->ShowSalaryInfo();
        }
        void ShowTotalSalary() const
        {
            int sum = 0;
            for(int i = 0; i < empNum; i++)
                sum += empList[i]->GetPay();
            cout << "Total Salary : " << sum << endl;
        }
        ~EmployeeHandler()
        {
            for(int i = 0; i < empNum; i++)
                delete empList[i];
        }
};

int main()
{
    EmployeeHandler handler;

    handler.AddEmployer(new PermanentWorker("KIM", 1000));
    handler.AddEmployer(new PermanentWorker("LEE", 1500));

    TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
    alba->AddWorkTime(5);
    handler.AddEmployer(alba);

    SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
    seller->AddSalesResult(7000);
    handler.AddEmployer(seller);

    handler.ShowAllSalaryInfo();
    handler.ShowTotalSalary();

    return 0;
}