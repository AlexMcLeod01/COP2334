//File Name: Harold_McLeod_Project_1.cpp
//Author: Harold Alex McLeod
//Email Address: ham4@students.uwf.edu
//Assignment Number: 1
//Description: Interest componding over 3 (or n number of) years

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Function to determine club membership
void clubMembership(double balance) {
    //Declare variables
    const int silverClubThreshhold = 1000;
    const int goldClubThreshhold = 5000;
    const int platinumClubThreshhold = 10000;
    string clubType;
    double excess;
    
    //Format output to dollars and cents
    cout << fixed;
    cout << setprecision(2);
    
    if (balance >= silverClubThreshhold) {
        if (balance >= platinumClubThreshhold) {
            clubType = "Platinum Bank Club";
            excess = balance - platinumClubThreshhold;
        } else if (balance >= goldClubThreshhold) {
            clubType = "Gold Bank Club";
            excess = balance - goldClubThreshhold;
        } else {
            clubType = "Silver Bank Club";
            excess = balance - silverClubThreshhold;
        }
        cout << "You are a member of the " << clubType
                << ".\nYou have exceeded the minimum for the " << clubType
                << " by $" << excess << ".";
    } else {
        cout << "";
    }
}

//Function for compounding interest
double compoundInterest(double starting, double rate) {
    //Do some maths multiplying by 1 + percent as a decimal
    //gives the total of starting number plus a that percent
    double interestMultiplier = 1 + (rate / 100);
    return (starting * interestMultiplier);
}

int main( ) {
    
    //Declare variables
    double balance, interestRate;
    int yearsToCompound;
    
    //Receive input from user
    cout << "Welcome to an unrealistic Bank!\n";
    cout << "Enter account balance in whole dollars and press 'Enter'\n$";
    cin >> balance;
    cout << "Enter desired interest rate as a whole percentage point and press 'Enter'\n";
    cin >> interestRate;
    
    //The following lines can be uncommented to turn this into an interest calculator
    /*cout << "Enter years you wish to allow compounding to continue and press 'Enter'\n";
    cin >> yearsToCompound;*/
    yearsToCompound = 3; //Comment this line if uncommenting the above two lines
    
    //Parrot input to ensure it is correct
    cout << "You entered $" << balance << " as your balance,\n";
    cout << "and " << interestRate << "\% as your interest rate\n\n";
    
    //Format output to dollars and cents
    cout << fixed;
    cout << setprecision(2);
    
    int x = 10;
    if(x++ > 10)
    {
        x = 13;
    }
    cout << x;
    
    //For loop to iterate over total number of years compounding
    for (int i = 0; i < yearsToCompound; i++) {
        balance = compoundInterest(balance, interestRate);
        //Output our results
        cout << "\n\nBalance at the end of Year " << i + 1 << ": $" << balance << ". ";
    clubMembership(balance);
    }
}