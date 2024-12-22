//Logic By Ammar
//Code By Shehroz
//Code Pushed By Hafsa
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
using namespace std;
int main() {
    int const TOTAL_COUNT = 240;
    int const STUDENT_COUNT = 40;
    string arr[TOTAL_COUNT];

    int count = 0;
    ifstream file("friends_dataset.csv");
    if (file.is_open()) {
        string line;
        while (getline(file, line) && count < TOTAL_COUNT) {
           stringstream ss(line);
            string item;

            while (getline(ss, item, ',') && count < TOTAL_COUNT) {
                arr[count++] = item;
            }
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
        return 1;
    }

    
    cout << "Multiplicity Graph (Weighted Strength Between Students):" << endl;
    for (int i = 0; i < STUDENT_COUNT; i++) {// this loop is for first student
        for (int j = i + 1; j < STUDENT_COUNT; j++) {//this loop is for second student
           int weight = 0;
           for(int k=i+STUDENT_COUNT;k<TOTAL_COUNT;k+=STUDENT_COUNT){//this loop goes to first student friends
              for(int l=j+STUDENT_COUNT;l<TOTAL_COUNT;l+=STUDENT_COUNT){//this loop goes to second student friends
                if (arr[k] == arr[l] && !arr[k].empty()) {//this check for common friend
                                 weight++;
              }
           }
            
        }
        if (weight > 0) {//check if there is common friend 
                cout << arr[i] << " - " << arr[j] << " [Weight: " << weight << "]" << endl;
            }
    }
    }
    return 0;
}