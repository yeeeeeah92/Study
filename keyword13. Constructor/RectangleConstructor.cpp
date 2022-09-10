#include <iostream>
#include "Point2.h"
#include "Rectangle2.h"

int main(void)
{
    //Rectangle rec(1, 1, 5, 5);
    Rectangle * rec = new Rectangle(1, 1, 5, 5);
    rec->ShowRecInfo();

    free(rec);
    return 0;
}