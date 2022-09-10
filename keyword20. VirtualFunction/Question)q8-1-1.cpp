#include <iostream>
#include <cstring>
using namespace std;

namespace RISK_LEVEL
{
    enum
    {
        RISK_A = 30,
        RISK_B = 20,
        RISK_C = 10
    };
}

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
        int GetPay() const { return salary; }
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
        int GetPay() const  // function overriding
        { 
            return PermanentWorker::GetPay() + (int)(salesResult*bonusRatio); 
        }
        void ShowSalaryInfo() const
        {
            ShowYourName();
            cout << "salary : " << GetPay() << endl;    // ForeignSalesWorker 포인터 객체가 이 함수를 호출할 경우 ForeignSalesWorker의 GetPay가 호출되는 현상 질문
        }
};

class ForeignSalesWorker : public SalesWorker
{
    private :
        const int risk; 
    public : 
        ForeignSalesWorker(const char* name, int money, double ratio, int risklevel) : SalesWorker(name, money, ratio), risk(risklevel)
        { }
        int GetPay() const
        {
            return SalesWorker::GetPay()*(1 + ((double)risk/100));
        }
        void ShowSalaryInfo() const
        {
            SalesWorker::ShowSalaryInfo();
            cout << "risk pay : " << SalesWorker::GetPay()*((double)risk/100) << endl;
            cout << "sum : " << GetPay() << endl << endl;
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

    ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
    fseller1->AddSalesResult(7000);
    handler.AddEmployer(fseller1);
/*
    ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
    fseller2->AddSalesResult(7000);
    handler.AddEmployer(fseller2);

    ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
    fseller3->AddSalesResult(7000);
    handler.AddEmployer(fseller3);
*/
    handler.ShowAllSalaryInfo();
    //handler.ShowTotalSalary();

    return 0;
}