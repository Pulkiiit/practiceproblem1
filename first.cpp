// first in grammar
#include <bits/stdc++.h>
using namespace std;

unordered_set<char> find_first(const vector<pair<char, string>>& grammar, char symbol, unordered_map<char, unordered_set<char>>& first) {
    unordered_set<char> result;
    for (const auto& production : grammar) {
        if (production.first == symbol) {
            const string& sequence = production.second;
            size_t i = 0;
            bool nullExisted=false;
            if(result.find('^') != result.end()) nullExisted=true;

            while (i < sequence.size()) {
                char current_symbol = sequence[i];

                if (isupper(current_symbol)) {
                    if(current_symbol==symbol)break;
                    result.insert(first[current_symbol].begin(), first[current_symbol].end());
                    // result.cledr()
                    if(first[current_symbol].find('^') == first[current_symbol].end()) {
                        break;
                    }else{
                        if(i!=sequence.size()-1)result.erase('^');
                    }
                } else {
                    result.insert(current_symbol);
                    break;
                }

                ++i;
            }
            if(nullExisted)result.insert('^');
        }
    }

    return result;
}

void calculate_first(const vector<pair<char, string>>& grammar, unordered_map<char, unordered_set<char>>& first) {
    int n=grammar.size();
    for (int i=n-1;i>=0;i--) {
        pair<char, string> production = grammar[i];
        char non_terminal = production.first;
        if (first.find(non_terminal) == first.end()) {
            first[non_terminal] = find_first(grammar, non_terminal, first);
        }
    }
}

void print_first_set(const unordered_map<char, unordered_set<char>>& first) {
    for (const auto& entry : first) {
        char non_terminal = entry.first;
        const unordered_set<char>& symbols = entry.second;

        cout << "First(" << non_terminal << ") = { ";
        for (char symbol : symbols) {
            cout << symbol << " ";
        }
        cout << "}\n";
    }
}

int main() {
    // Example grammar
    vector<pair<char, string>> grammar = {
        // {'S', "AdB"},
        // {'A', "bB"},
        // {'A', "^"},
        // {'B', "C"},
        // {'B', "Cg"},
        // {'C',"d"},
        // {'C',"^"}
        {'S',"aBDh"},
        {'B',"cC"},
        {'C',"bC"},
        {'C',"^"},
        {'D',"EF"},
        {'E',"g"},
        {'E',"^"},
        {'F',"f"},
        {'F',"^"}
    };

    unordered_map<char, unordered_set<char>> first;
    calculate_first(grammar, first);

    print_first_set(first);

    return 0;
}