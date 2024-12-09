//Logic by Muhammad Ammar
//Code by Shehroz Hameed
//Code Pushed By Hafsa
#include<iostream>
#include<fstream>
#include <sstream>
using namespace std;
void popularfriend(string arr1[], int arr2[], int studentCount, int totalCount){
	// first   loop is to store no of friendship and also represent stundents  
	for (int i=0;i<studentCount;i++){
		int count=0;
		//this loop is to check for no of friendship
		for (int j=studentCount;j< totalCount;j++){
			if (arr1[i]==arr1[j]){
				count++;
			}
		}
		arr2[i]=count; 
	}
// this is to check for larger number of friendship and also to find index of student who has most friend
	int index,larger=INT_MIN;
	for(int i=0;i<studentCount;i++){
		if (arr2[i]>larger)
		{
			larger=arr2[i];
			index=i;
		}   
	}
	cout<<"popular student is "<<arr1[index]<<" with "<<larger<<" friend";
}
int main (){
	//first initinalize students name than add their friends name
	int const TOTAL_COUNT=240;
	string arr1[TOTAL_COUNT];
	
	int count = 0;
	ifstream file("friends_dataset.csv");
	if (file.is_open()) {
		string line;
		
		while (getline(file, line) && count < TOTAL_COUNT) {
			stringstream ss(line);
			string item;
			
			// Tokenize the line by comma and store in the array
			while (getline(ss, item, ',') && count < TOTAL_COUNT) {
				arr1[count++] = item;
			}
		}
		file.close();
	} else {
		cout << "Unable to open file" << endl;
		return 1;
	}
	//second array to store no of friendships
	int const STUDENT_COUNT=40;
	int arr2[STUDENT_COUNT];
	//function to form popular friend
	popularfriend(arr1,arr2,STUDENT_COUNT,TOTAL_COUNT);
	return 0;
	
}
