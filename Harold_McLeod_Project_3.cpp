//File Name: Harold_McLeod_Project_1.cpp
//Author: Harold Alex McLeod
//Email Address: ham4@students.uwf.edu
//Assignment Number: 3
//Description: Interest componding over 3 (or n number of) years

#include <iostream>
#include <iomanip>
//#include <string>
#include <cmath>
using namespace std;

int menu() {
    int choice = 0;
    while (choice < 1 || choice > 5) {
        cout << "Conversion Tool\n\n";
        cout << "1: Calculate volume of a cube in feet given the length of a side in meters\n\n";
        cout << "2: Calculate the volume of a cube in meters given the length of a side in feet\n\n";
        cout << "3: Calculate the volume of a sphere in feet given its diameter in meters\n\n";
        cout << "4: Calculate the volume of a sphere in meters given its diameter in feet\n\n";
        cout << "5: Exit\n\n";
        cout << "Please input a number(1-5)->";
        cin >> choice;
    }
    return choice;
}

double feetToMeters (double feet) {
    return (feet * .3048);
}

double metersToFeet (double meter) {
    return (meter * 3.28084);
}

double radiusFromDiameter (double diameter) {
    return (diameter / 2);
}

double cubeVolume (double side) {
    return pow(side, 3);
}

double sphereVolume (double radius) {
    return ((4 * pow(radius, 3) * 3.14159) / 3);
}

void Test () {
    cout << "Testing\n";
    cout << (abs(4.188786667 - sphereVolume(1.0)) < .1);
    cout << (abs(113.09724 - sphereVolume(3.0)) < .001);
    cout << (abs(1.0 - cubeVolume(1.0)) < .001);
    cout << (abs(27.0 - cubeVolume(3.0)) < .001);
    cout << (abs(1.0 - radiusFromDiameter(2.0)) < .001);
    cout << (abs(15.0 - radiusFromDiameter(30.0)) < .001);
    cout << (abs(1.0 - feetToMeters(3.28084)) < .001);
    cout << (abs(15.0 - feetToMeters(49.2126)) < .001);
    cout << (abs(35.5 - feetToMeters(116.46982)) < .001);
    cout << (abs(1 - metersToFeet(.3048)) < .001);
    cout << (abs(3.28084 - metersToFeet(1.0)) < .001);
    cout << (abs(65.5 - metersToFeet(19.9644)) < .001) << "\n";
}

double feetCubeToMeters () {
    double lengthInFeet;
    cout << "Enter length of a side in feet:";
    cin >> lengthInFeet;
    return cubeVolume(feetToMeters(lengthInFeet));
}

double metersCubeToFeet () {
    double lengthInMeters;
    cout << "Enter length of a side in meters:";
    cin >> lengthInMeters;
    return cubeVolume(metersToFeet(lengthInMeters));
}

double feetSphereToMeters() {
    double diaInFeet;
    cout << "Enter diameter of sphere in feet:";
    cin >> diaInFeet;
    return sphereVolume(radiusFromDiameter(feetToMeters(diaInFeet)));
}

double metersSphereToFeet() {
    double diaInMeters;
    cout << "Enter diameter of sphere in meters:";
    cin >> diaInMeters;
    return sphereVolume(radiusFromDiameter(metersToFeet(diaInMeters)));
}

int main( ) {
    //Test();
    int choice = 0;
    while (choice != 5) {
        choice = menu();
        switch (choice) {
            case 1:
                cout << feetCubeToMeters() << " cubic meters\n\n";
                break;
            case 2:
                cout << metersCubeToFeet() << " cubic feet\n\n";
                break;
            case 3:
                cout << feetSphereToMeters() << " cubic meters\n\n";
                break;
            case 4:
                cout << metersSphereToFeet() << " cubic feet\n\n";
                break;
        }
            
    }
}