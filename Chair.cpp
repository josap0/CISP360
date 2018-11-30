#include "Chair.h"
#include <iostream>
using namespace std;

Chair::Chair()
{
    price = 0;
    purchased = 0;
}

void Chair::setPrice(double p)
{
    price = p;
}
void Chair::setPurchase(bool p){
    purchased = p;
}
