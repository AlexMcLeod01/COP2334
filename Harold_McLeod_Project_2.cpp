//File Name: Harold_McLeod_Project_2.cpp
//Author: Harold Alex McLeod
//Email Address: ham4@students.uwf.edu
//Assignment Number: 2
//Description: Cost estimator for internet data usage

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double determinePrice (char plan, int data) {
    double price;
    
    //Determine price
    switch (plan) {
        case 'B':
            price = 20.00;
            if (data > 50) {
                price += (.10 * (data - 50));
            }
            break;
        case 'E':
            price = 35.00;
            if (data > 2000) {
                price += (.05 * (data - 2000));
            }
            break;
        case 'U':
            price = 55.00;
            break;
        default:
            cout << "Error, inputs incorrectly sanitized";
            break;
    }
    return price;
}

int main( ) {
    
    //Declare variables
    char planType = 0;
    int dataAmount = -1;
    double price;
    
    //Instructions to user
    cout << "'B' - Basic, 'E' - Enhanced, 'U' - Unlimited\n"
        << "Choose a plan:\n";
    
    //Sanitize input before proceeding
    while (planType != 'B' && planType != 'E' && planType != 'U') {
        if (planType != 0) {
            cout << "Enter only B, E, or U for the plan.\n";
        }
        
        //Input and formatting
        cin >> planType;
        planType = toupper(planType);
    }
    
    //Sanitize input
    while (dataAmount < 0 || dataAmount > 10000) {
        //Instructions to user
        cout << "How many GB were used last month?\n"
            << "Enter a number from 0 to 10000\n";
        cin >> dataAmount;
    }
    
    price = determinePrice(planType, dataAmount);
    
    //Format output to dollars and cents
    cout << fixed;
    cout << setprecision(2);
    
    cout << "The price is: $" << price << "\n";
    
    //Deternmine upgrades
    switch (planType) {
        case 'B':
            if (price > 35.00) {
                cout << "By changing to the Enhanced Plan, you would save $"
                    << (price - determinePrice('E', dataAmount)) << "\n";
                if (price > 55.00) {
                    cout << "By changing to the Unlimited Plan, you would save $"
                        << (price - determinePrice('U', dataAmount)) << "\n";
                }
            } else {
                cout << "You are in the most economical plan for your usage amounts.\n";
            }
            break;
        case 'E':
            if (price > 55.00) {
                cout << "By changing to the Unlimited Plan, you would save $"
                    << (price - determinePrice('U', dataAmount)) << "\n";
            }
            break;
    }
}