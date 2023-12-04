
// lexical analyzer in C/C++ (to recognize the keywords, identifiers, operators["op"], constants)

#include <bits/stdc++.h>
using namespace std;

bool isOperator(string s, int& index, map<string, set<string>> &operators){
  vector<string> operatorsVector = {"<=", ">=", "==", "!=", "++", "--", ">", "<", "=", "+", "-", "*", "/", "^"};

  for (string str : operatorsVector){
    if (index + str.length() - 1 < s.length()){
      if (s.substr(index, str.length()) == str){
        operators["op"].insert(s.substr(index, str.length()));
        index += str.length();
        return true;
      }
    }
  }

  return false;
}

bool isKeywords(string s, int& index, map<string, set<string>> &keywords){
  vector<string> keywordsOperators = {"if", "else", "while", "float", "float", "char", "int", "for"};

  for (string str: keywordsOperators){
    if (index + str.length() - 1 < s.length()){
      if (s.substr(index, str.length()) == str && (index + str.length() >= s.length() || (index + str.length() < s.length() && !isalnum(s[index + str.length()])))){
        keywords["key"].insert(s.substr(index, str.length()));
        index += str.length();
        return true;
      }
    }
  }

  return false;
}

bool isConstant(string s, int& index, map<string, set<string>>& constants){
  int currentIndex = index;
  while (index < s.length()){
    if ((s[index] >= '0' && s[index] <= '9') || s[index] == '.'){
      index++;
    } else {
      if (currentIndex != index){
        constants["con"].insert(s.substr(currentIndex, index - currentIndex));
        return true;
      }
      return false;
    }
  }

  if (currentIndex != index){
    constants["con"].insert(s.substr(currentIndex, index - currentIndex));
    return true;
  }
  return false;
}

bool isPunctuation(string s, int& index, map<string, set<string>>& punctuations){
  if (s[index] == ',' || s[index] == ';'){
    string str = "";
    str += s[index];
    index += 1;
    punctuations["punc"].insert(str);
    return true;
  }
  return false;
}

int main()
{
  cout << "Enter the number of lines: ";
  int t = 0;
  cin >> t;
  t++;
  map<string, set<string>> mp;
  while (t != 0){
    string str;
    getline(cin, str);
    for (int i = 0; i < str.length(); ){
      int curr = i;
      if (!isOperator(str, i, mp) && !isPunctuation(str, i, mp) && !isConstant(str, i, mp) && !isKeywords(str, i, mp)){
        int temp = 0;
        while (i < str.length() && isalnum(str[i])){
          ++temp;
          ++i;
        }

        if (temp > 0){
          mp["id"].insert(str.substr(curr, temp));
        }
      }
      if (curr == i){
        ++i;
      }
    }
    t--;
  }

  for (auto it : mp){
    string str = "";
    if (it.first == "con") str = "Constants";
    if (it.first == "id") str = "Identifiers";
    if (it.first == "key") str = "Keywords";
    if (it.first == "op") str = "Operators";
    if (it.first == "punc") str = "Punctuations";
    cout<<endl;
    cout << str << " : ";
    for (auto it2: it.second){
      cout << it2 << ' ';
    }
  }
  return 0;
}