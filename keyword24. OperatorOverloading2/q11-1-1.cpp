#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
    private : 
        int bullet;
    public : 
        Gun(int bnum) : bullet(bnum) {}
};

class Police
{
    private : 
        int handcuffs;
        Gun* pistol;
    public : 
        Police(int bnum, int bcuff) : handcuffs(bcuff) 
        {
            if(bnum > 0)
                pistol = new Gun(bnum);
            else
                pistol = NULL;
        }
        Police(const Police& ref)
        {
            handcuffs = ref.handcuffs;
            if(pistol != NULL)
            {
                if(ref.pistol == NULL)
                {
                    pistol = NULL;
                }
                else
                {
                    
                }
            }
        }
        ~Police()
        {
            if(pistol != NULL)
                delete pistol;
        }
};

int main()
{
    Police pman1(5, 3);
    Police pman2 = pman1;
    
    Police pman3(2, 4);
    pman3 = pman1;
    return 0;
}