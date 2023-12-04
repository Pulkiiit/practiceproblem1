
// count blankspaces and lines

#include <iostream>
using namespace std;

int main(){
    string str;
    cout<<"Enter the paragraph. Write $ at the end of the line"<<endl;
    getline(cin, str);

    int blanks = 0;
    int lines = 1;

    for(int i=0;i<str.size();i++){
        if(str[i] == ' '){
            blanks++;
        }
        else if(str[i] == '$'){
            lines++;
        }
    }
    cout<<"No of blank spaces = "<<blanks<<endl;
    cout<<"No of lines = "<<lines<<endl;
}
