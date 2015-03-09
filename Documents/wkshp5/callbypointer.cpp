//
//  callbypointer.cpp
//  
//
//  Created by Cheryl Pope on 29/08/13.
//
//
//  Program to demonstrate call-by-pointer parameters.

#include <iostream>

using namespace std;

//Reads two integers from the keyboard.
void get_numbers(int *input1, int *input2);

//Interchanges the values pointed to by variable1 and variable2.
void swap_values(int *variable1, int *variable2);

//Shows the values of variable1 and variable2, in that order.
void show_results(int output1, int output2);

int main() {
    int first_num, second_num;
    
    // *** modify the arguments given below to match the paraemeter types required
    // by the functions
    get_numbers(first_num, second_num);
    swap_values(first_num, second_num);
    show_results(first_num, second_num);
    
    return 0;
}

void get_numbers(int *input1, int *input2) {
    cout << "Enter two integers: ";
    
    // *** correct this line.  The user will enter an int, we need to store the int in the integers pointed to by the input parameters.
    cin >> input1 >> input2;  
}
void swap_values(int *variable1, int *variable2) {
    int temp;  
    
    // **** correct these lines. We need to swap the values pointed to by the variables
    temp = variable1;
    variable1 = variable2;
    variable2 = temp;
}

void show_results(int output1, int output2) {
    cout << "In reverse order the numbers are: "
    << output1 << " " << output2 << endl;
}
