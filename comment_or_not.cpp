
// Comment or not

#include<iostream>
using namespace std;

int main(){
    string str;
    cout<<"Enter the comment: "<<endl;
    cin>>str;
    int n = str.size();
    if(n == 0 || n == 1){
        cout<<"Not a comment"<<endl;
    }
    else if(str[0] == '/' && str[1] == '/'){
        cout<<"Comment"<<endl;
    }
    else if(str[0] == '/' && str[1] == '*'){
        if(str[n-1] == '/' && str[n-2] == '*'){
            cout<<"Comment"<<endl;
        }
        else{
            cout<<"Not a comment"<<endl;
        }
    }
    else{
        cout<<"Not a comment"<<endl;
    }
}