#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int numCasos;
    string str1, str2;
    unordered_map<char, int> word1, word2;
    cin >> numCasos; cin.ignore();
    while (numCasos--) {
        getline(cin, str1);
        getline(cin, str2);

        str1.erase(remove_if(str1.begin(), str1.end(), [](char c){return isspace(c);}), str1.end());
        str2.erase(remove_if(str2.begin(), str2.end(), [](char c){return isspace(c);}), str2.end());
        transform(str1.begin(), str1.end(), str1.begin(), [&word1](char& c){c = tolower(c); ++word1[c]; return c;});
        transform(str2.begin(), str2.end(), str2.begin(), [&word2](char& c){c = tolower(c); ++word2[c]; return c;});


        bool isAnagram = word1 == word2; 
        isAnagram ? cout << "SI\n" : cout << "NO\n";
        word1.clear(); word2.clear();
    }
}