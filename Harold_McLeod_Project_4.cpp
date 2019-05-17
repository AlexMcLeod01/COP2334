//File Name: Harold_McLeod_Project_4.cpp
//Author: Harold Alex McLeod
//Email Address: ham4@students.uwf.edu
//Assignment Number: 4
//Description: Salary average calculator from input file

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

string prompt () {
    string in;
    cout << "Enter SALARY file name, or 0 to exit:";
    cin >> in;
    return in;
}

double Average(double salary[], int length) {
    double sum = 0;
    for (int i = 0; i < length; i++) {
        sum += salary[i];
    }
    return (sum / length);
}

void bubbleSortArray(double arr[], int length) {
    int i, j;
    bool swap;
    double temp;
    for (i = 0; i < length - 1; i++) {
        swap = false;
        for (j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap = true;
            }
        }
        if (!swap) {
            break;
        }
    }
}

double* salaries(string filename) {
    double* results = new double[3];
    ifstream file;
    string line;
    file.open(filename);
    if(file.is_open()) {
        getline(file, line);
        int num = stoi(line);
        if (num > 20) {
            num = 20;
        }
        double* Salaries = new double[num];
        int i = 0;
        while (getline(file, line) && i < 20) {
            Salaries[i] = stod(line);
            i++;
        }
        bubbleSortArray(Salaries, num);
        results[0] = Average(Salaries, num);
        results[1] = Salaries[num-1];
        results[2] = Salaries[0];
        return results;
    } else if (filename.compare("0") != 0) {
        cout << "Unable to open file.\n";
    }
    return results;
}

int main( ) {
    string in = "";
    cout << fixed;
    cout << setprecision(2);
    while (in.compare("0") != 0)
    {
        in = prompt();
        if (in.compare("0") == 0) {
            break;
        }
        double* results = salaries(in);
        cout << "\nThe average SALARY is " << results[0] << "\n\n";
        cout << "The highest SALARY is " << results[1] << "\n\n";
        cout << "The lowest SALARY is " << results[2] << "\n\n";
    }
}