//Program to demonstrate call-by-reference parameters.
#include <iostream>

using namespace std;

//Reads two integers from the keyboard.
void get_numbers(int &input1, int &input2);

//Interchanges the values of variable1 and variable2.
void swap_values(int &variable1, int &variable2);

//Shows the values of variable1 and variable2, in that order.
void show_results(int output1, int output2);

int main() {
    int first_num, second_num;

    get_numbers(first_num, second_num);
    swap_values(first_num, second_num);
    show_results(first_num, second_num);
    return 0;
}

void get_numbers(int &input1, int &input2) {
    cout << "Enter two integers: ";
    cin >> input1
        >> input2;
}
void swap_values(int &variable1, int &variable2) {
    int temp;

    temp = variable1;
    variable1 = variable2;
    variable2 = temp;
}

void show_results(int output1, int output2) {
    cout << "In reverse order the numbers are: "
         << output1 << " " << output2 << endl;
}
