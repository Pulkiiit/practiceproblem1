
// String is constant or not

#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

int main(){
    int i, flag = 0;
    char a[10];
    cout<<"Enter the string: "<<endl;
    cin>>a;

    for(i = 0;i<strlen(a);i++){
        if(a[0] == '-'){
            continue;
        }
        else if(isdigit(a[i])){
            flag = 1;
        }
        else{
            flag = 0;
            break;
        }
    }
    if(flag){
        cout<<"Constant"<<endl;
    }
    else{
        cout<<"Variable"<<endl;
    }
}