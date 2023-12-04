
//string is a keyword or not

#include <iostream>
#include <string.h>
using namespace std;

int main(){
    char a[32][10] = {"auto","double","int","struct","break","else","long",
      "switch","case","enum","register","typedef","char",
      "extern","return","union","const","float","short",
      "unsigned","continue","for","signed","void","default",
      "goto","sizeof","voltile","do","if","static","while"};
    int n = 100;
    char str[n];
    cout<<"Enter the string: "<<endl;
    cin>>str;
    int i;
    int flag = 0;
    for(i=0;i<32;i++){
        if(strcmp(str,a[i])==0) {
            flag=1;
        }
    }
    if(flag == 1){
        cout<<"Keyword"<<endl;
    }
    else{
        cout<<"String"<<endl;
    }
    return 0;
}
