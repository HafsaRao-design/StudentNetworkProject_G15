//logic by ammar 
//code by hafsa for 1 and 2 hop
//code by ammar for 3 hop
//pushed by shehroz
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
void findHops(string arr[], int studentcount, int totalcount) {
    string studentName;
    cout << "Enter the name of the student: ";
    getline(cin,studentName) ;
    string onehop[studentcount];    // Store 1-hop friends
    string twohop[studentcount];   // Store 2-hop friends
    string threehop[studentcount]; // Store 3-hop friends
    int onehopcount = 0, twohopCount = 0, threehopcount = 0;

    //finding 1 hop friends
    for (int i = 0; i < studentcount; i++) {
        if (arr[i] == studentName) {
            for (int j = i + studentcount; j < totalcount; j += studentcount) {
                onehop[onehopcount++] = arr[j];
            }
            break;
        }
    }
    

   // finding 2-hop friends 
    for (int i = 0; i < onehopcount; i++) {//this loop is to check every first hop member
        string friendName = onehop[i];
        for (int j = 0; j < studentcount; j++) {//this loop check if 1 hop friend is in the student or not
            if (arr[j] == friendName) {
                for (int k = j + studentcount; k < totalcount; k += studentcount) {//this loop checks for his frinds
                    // now Checking if the 2-hop friend is  already in 1-hop or not
                    bool alreadyExists = false;
                    for (int l = 0; l < onehopcount; l++) {//check if friend is already in 1 hop or not 
                        if (onehop[l] == arr[k]) {
                            alreadyExists = true;
                            break;
                        }
                    }
                    for (int l = 0; l < twohopCount; l++) {//check if friend already added in 2 hop or not
                        if (twohop[l] == arr[k]) {
                            alreadyExists = true;
                            break;
                        }
                    }
                    if (alreadyExists==false && arr[k] != studentName) { //if not than add it in 2 hop
                        twohop[twohopCount++] = arr[k];
                    }
                }
                break;
            }
        }
    }

    // Finding 3-hop friends 
    for (int i = 0; i < twohopCount; i++) {//this loop is to check every 2 hop member
        string friendName = twohop[i];
        for (int j = 0; j < studentcount; j++) {//this loop check if 2 hop friend is in the students or not
            if (arr[j] == friendName) {
                for (int k = j + studentcount; k < totalcount; k += studentcount) {//this loop checks for his frinds
                    // Check if the 3-hop friend is not already in 1-hop, 2-hop, or 3-hop
                    bool alreadyExists = false;
                    for (int l = 0; l < onehopcount; l++) {//check if friend is already in 1 hop or not 
                        if (onehop[l] == arr[k]) {
                            alreadyExists = true;
                            break;
                        }
                    }
                    for (int l = 0; l < twohopCount; l++) {//check if friend isalready added in 2 hop or not
                        if (twohop[l] == arr[k]) {
                            alreadyExists = true;
                            break;
                        }
                    }
                    for (int l = 0; l < threehopcount; l++) {//check if friend already added in 3 hop  or not
                        if (threehop[l] == arr[k]) {
                            alreadyExists = true;
                            break;
                        }
                    }
                    if (!alreadyExists && arr[k] != studentName) {//if not than add it in 3 hop
                        threehop[threehopcount++] = arr[k];
                    }
                }
                break;
            }
        }
    }

   //now output of 1,2 and 3 hop
    cout << "1-hop friends: "<<endl;
    if (onehopcount == 0)
        cout << "None";
    else
        for (int i = 0; i < onehopcount; i++)
            cout << onehop[i] << endl;
    cout << endl;

    cout << "2-hop friends: "<<endl;
    if (twohopCount == 0)
        cout << "None";
    else
        for (int i = 0; i < twohopCount; i++)
            cout << twohop[i] << endl;
    cout << endl;

    cout << "3-hop friends: "<<endl;
    if (threehopcount == 0)
        cout << "None";
    else
        for (int i = 0; i < threehopcount; i++)
            cout << threehop[i] << endl;
    cout << endl;
}

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

            // Tokenize the line by comma and store in the array
            while (getline(ss, item, ',') && count < TOTAL_COUNT) {
                arr[count++] = item;
            }
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
        return 1;
    }
    findHops(arr, STUDENT_COUNT, TOTAL_COUNT);

    return 0;
}