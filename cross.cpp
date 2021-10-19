/*
Author: Casey Roosma
Course: CSCI-136
Instructor: Yasmeen Hassan
Assignment: Lab 4C

creates a cross of astericks the size of user
 inputted size
*/

#include <iostream>
using namespace std;

int main() {
    int size; //create an int variable for size of cross
    cout << "Input size: " << endl; //prompt user for input
    cin >> size; //store input as size variable
    
    //for loop to iterate through colums and rows by size
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(i==j || (i+j)==(size - 1)){
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << "\n";
    }
}
