// lexical operator
#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<string, string> mp = {{"++", "Increment"}, {"--", {"Decrement"}},{"+", "Addition"}, {"-", "subtraction"}, {"*", "Multiplication"}, {"/", "Division"}, {"%", "Modulus"}, {"<", "Less than"}, {"<=", "Less than or equal to"}, {">", "Greater than"}, {">=", "Greater than or equal to"}, {"==", "Equality operator"}, {"!=", "Not equal to"}, {"&&", "Logical AND"}, {"||", "Logical OR"}, {"!", "Logical NOT"}, {"&", "Bitwise AND"}, {"|", "Bitwise OR"}, {"<<", "Left shift"}, {"<<", "Right shift"}, {"~", "Bitwise NOT"}, {"^", "Bitwise XOR"}, {"?:", "Conditional operator"}, {"=", "Assignment"}, {"+=", "Add then assign"}, {"-=", "Subtract then assign"}, {"*=", "Multiply then assign"}, {"/=", "Divide then assign"}, {"%=", "Modulus then assign"}};
    string op;
    cout << "Enter the operator: ";
    cin >> op;
    if(mp.find(op) != mp.end()) cout << mp[op];
    else cout << "The given input is not a operator";
    return 0;
}