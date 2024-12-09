//Logic by Muhammad Ammar
//Code by Shehroz Hameed
//Code Pushed By Hafsa
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
void getname(string arr1[], int TOTAL_COUNT, int STUDENT_COUNT)
{
    // this loop is to run for every student to check for their friendship
    for (int i = 0; i < STUDENT_COUNT; i++)
    {
        // this loop moves to the friends of students
        for (int j = i + STUDENT_COUNT; j < TOTAL_COUNT; j += STUDENT_COUNT)
        {
            // this loop check if the friend of student has also add friends
            for (int k = 0; k < STUDENT_COUNT; k++)
            {
                // if the friend has added his friends
                if (arr1[k] == arr1[j])
                {
                    bool asymmetric = true;
                    // this loop checks if the friend of student has also added the student in his friend list
                    for (int l = k + STUDENT_COUNT; l < TOTAL_COUNT; l += STUDENT_COUNT)
                    {
                        if (arr1[l] == arr1[i])
                        {                       // this condition check if he has added or not
                            asymmetric = false; // if he added him then their relation is not asymmetric
                        }
                        // cout<<arr1[l]<<endl;
                    }
                    if (asymmetric == true)
                    { // check the student is asymetric to how many of his friends
                        cout << arr1[i] << " is asymmetric with " << arr1[k] << endl;
                    }
                }
            }
            
        }
    }
}

int main()
{
    // first initinalize students name than add their friends name
    int const TOTAL_COUNT = 240;
    string arr1[TOTAL_COUNT];
    // total number of students
    int const STUDENT_COUNT = 40;

    int count = 0;
    ifstream file("friends_dataset.csv");
    if (file.is_open())
    {
        string line;

        while (getline(file, line) && count < TOTAL_COUNT)
        {
            stringstream ss(line);
            string item;

            // Tokenize the line by comma and store in the array
            while (getline(ss, item, ',') && count < TOTAL_COUNT)
            {
                arr1[count++] = item;
            }
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
        return 1;
    }
    getname(arr1, TOTAL_COUNT, STUDENT_COUNT);
    return 0;
}