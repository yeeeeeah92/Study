#include <iostream>
using namespace std;

class Car
{
    private : 
        int gasolineGuage;
    public : 
        Car(int n) : gasolineGuage(n) {}
        int GetGasGuage()
        {
            return gasolineGuage;
        }
};

class HybridCar : public Car
{
    private : 
        int electricGuage;
    public : 
        HybridCar(int n, int m) : Car(n), electricGuage(m) { }
        int GetElecGuage()
        {
            return electricGuage;
        }
};

class HybridWaterCar : public HybridCar
{
    private : 
        int waterGuage;
    public : 
        HybridWaterCar(int n, int m, int l) : HybridCar(n, m), waterGuage(l) {}
        int ShowCurrentGuage()
        {
            cout << "remain gasoline : " << GetGasGuage() << endl;
            cout << "remain electric : " << GetElecGuage() << endl;
            cout << "remain water : " << waterGuage << endl;
        }
};

int main()
{
    HybridWaterCar hybrid_water_car(10, 20, 30);

    hybrid_water_car.ShowCurrentGuage();
    return 0;
}