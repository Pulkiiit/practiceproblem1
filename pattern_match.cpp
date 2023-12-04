// regex abb,a* and a*b+
#include <iostream>
using namespace std;

int main(){
    string str;
    cout << "Enter the string: ";
    cin >> str;
    if(str.size() == 3 && str[0] == 'a' && str[1] == 'b' && str[2] == 'b'){
        cout << "The string is accepted under the rule abb";
        return 0;
    }
    int i = 0;
    int rule = 1;
    while(i < str.size()){
        if(str[i] == 'b'){
            rule = 2;
        }else if(rule == 2 && str[i] == 'a'){
            rule = 3;
            break;
        }else if(!(str[i] == 'a' || str[i] == 'b')){
            rule = 3;
            break;
        }
        i++;
    }
    if(rule == 1){
        cout << "The string is accepted under the language a*";
    }else if(rule == 2){
        cout << "The string is accepted under the language a*b+";
    }else{
        cout << "The string is not accepted under the given language";
    }
    return 0;
}
