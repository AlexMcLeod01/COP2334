//File Name: Harold_McLeod_Project_5.cpp
//Author: Harold Alex McLeod
//Email Address: ham4@students.uwf.edu
//Assignment Number: 5
//Description: Capitalizing repeated letters.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//Takes an input string and returns any repeated letters capitalized
string capitalizeRepeats (string Input) {
    string ans = "";
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < Input.length(); i++) {
        char x = Input[i];
        if (Input.find(x, i + 1) != string::npos && letters.find(toupper(x)) != string::npos) {
            if (ans.find(toupper(x)) == string::npos) {
                ans += toupper(x);
            }
        }
    }
    return ans;
}

//Get input
string prompt (string name) {
    string in;
    cout << name << ":";
    cin >> in;
    return in;
}

//Takes filenames, opens files, gets strings, sends to capitalizeRepeats,
//and writes results
void manipStrings(string infile, string outfile) {
    ifstream input;
    input.open(infile);
    ofstream output;
    output.open(outfile);
    string line, tmp;
    if ((bool)input && (bool)output) {
        if(input.is_open() && output.is_open()){
            while(getline(input, line)) {
                tmp = capitalizeRepeats(line);
                if (tmp.length() > 0) {
                    output << tmp << endl;
                }
            }
            cout << "Output written.";
        } else {
            cout << "Cannot open input file. Restart to try again.";
        }
    } else {
        cout << "Input file does not exist. Restart to try again.";
    }
    return;
}

int main( ) {
    string in, out;
    int option;
    in = prompt("Enter input file name");
    out = prompt("Enter output file name");
    manipStrings(in, out);
}
