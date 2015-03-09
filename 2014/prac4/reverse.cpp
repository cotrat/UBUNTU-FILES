#include <iostream>
#include <string>
#include <vector>
using namespace std;

string reverseStringRecursively(string str){
    if (str.length() == 1) {
        return str;
    }else{
	cout << str << endl;
        return reverseStringRecursively(str.substr(1,str.length())) + str.at(0);
    }
}


