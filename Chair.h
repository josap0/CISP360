#include<iostream>
using namespace std;

#ifndef CHAIR_H
#define CHAIR_H

class Chair{
    private:
    bool purchased;
    double price;
    
    public:
    Chair();
    
    void setPurchase(bool);
    void setPrice(double);
    
    double getPrice(){
        return price;
    }
    
    bool getPurchased(){
        return purchased;
    }  
};
#endif
