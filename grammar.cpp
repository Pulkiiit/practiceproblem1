//string belongs to grammar or not
#include <iostream>
using namespace std;

int main() {
    string str;
	cout << "\nThe grammar is as follows:\nS -> aS\nS -> Sb\nS -> ab\n";
	cout << "Enter a string: ";
	cin >> str;
	if(str[0] != 'a' || str[str.size() - 1] != 'b'){
	    cout << "Not accepted";
		return 0;                                    
	}
	int n = 1;
    while(str[n] == 'a') n++;
	if(str[n] != 'b'){
	    cout << "Not accepted";
		return 0;	
	}
	n++;
	while(str[n] == 'b') n++;
	if(n != str.size()){
	    cout << "Not accepted";
		return 0;
	}
	cout << "Accepted";
	return 0;
}