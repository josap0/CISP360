#include<iostream>
#include<iomanip>
#include<stdio.h>
#include "Chair.h" // includes the header for Chair Class
#include "Chair.cpp" // includes the chair class
using namespace std;

const int ROWSIZE = 15;
const int COLSIZE = 30;
const string nope = "That is an invalid selection, please try again\n\n"; // error message for validation

void DsplChrt(Chair[][COLSIZE]); //Display seating chart; takes an array of Chair objects
void PurchaseMenu(Chair[][COLSIZE]); //Menu for purchasing chairs; takes an array of Chair objects

int main(){

    Chair chairs[ROWSIZE][COLSIZE]; //Fills an array with Chair objects
    PurchaseMenu(chairs); //Sends Chair object array to subprogram
    system("Pause");   
    return 0;
}

void DsplChrt(Chair chairs[][COLSIZE])
{
    cout << setw(60) << "\nSeats\n         "; 
    for(int i = 1; i < COLSIZE +1; i++) //This loop is mostly formatting
    {
        if(i < 10)
            cout << " "; //Adds extra space for single digit numbers
        cout << i << " ";
    }
    cout << endl;
    for(int i = 0; i < ROWSIZE ; i++) //Outer loop populates rows
    {
        cout << "Row " << i+1;
        i + 1 >= 10 ? cout << "    " : cout << "     "; //Formatting
        for(int j = 0; j < COLSIZE; j++) //Inner loop populates columns
            chairs[i][j].getPurchased() == 0 ? cout << char(254) << "  " : cout << "X  "; // Displays symbol based on chair availablity
        cout << endl;
    }
    cout << endl << endl;
}

void PurchaseMenu(Chair chairs[][COLSIZE])
{
    int _row = 0, //Row and column of chair purchased
        _col = 0,
        txSold = 0; //Number of chairs sold
    char repeat = 'y', //For Do While Loop
         valid = 'n'; //For input validation
    double cost = 0;
    
    cout << "=====================================================" << '\n'
         << "Welcome to the theater!\n\n";
    
    DsplChrt(chairs); //Displays seating chart showing seat availablity
     
    do //Loops seat selection process
    {
        while(valid == 'n')
        {
        cout << "Row: "; //Choose a row to purchase from
        cin >> _row;
        if(!cin || _row >ROWSIZE || _row < 0) //Input validation
        {
            cin.clear(); //Clear input
            cin.ignore();
            cout << nope; //Return error message
        }
        else
            valid = 'y';
        }
        valid = 'n';
        fflush(stdin);
        while(valid == 'n')
        {
        cout << "Column: ";
        cin >> _col;
        if(!cin || _col >= COLSIZE || _col < 0)
        {
            cin.clear();
            cin.ignore();
            cout << nope;
        }
        else
            valid = 'y';
        }
        valid = 'n';
        fflush(stdin);
        if(!chairs[_row - 1][_col - 1].getPurchased()) //Checks if seat is available
        {
            chairs[_row - 1][_col - 1].setPurchase(true); //Makes chair unavailable
            cost += chairs[_row - 1][_col - 1].getPrice(); //Adds chair price to total
            ++txSold; //Increments number of seats sold
        }
        else
             cout << "I'm sorry, that seat is unavailable" << endl; //Error message
        cout << "Purchase another ticket? (Y/N): "; //Repeat?
        cin >> repeat;
        if(!cin) //Input validation
        {
            cin.clear();
            cin.ignore();
        }
        fflush(stdin);
    }while(tolower(repeat) == 'y'); //Check if user wants to repeat
    cout << "\nTickets purchased: " << txSold << '\n'
              << "Total cost: $" << cost << endl;
              
    DsplChrt(chairs); //Display updated seating chart
         
}
