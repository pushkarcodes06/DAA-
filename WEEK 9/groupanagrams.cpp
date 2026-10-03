#include <bits/stdc++.h>
using namespace std;
 
vector<vector<string>> groupAnagrams(vector<string> &words) {
    unordered_map<string, vector<string>> map;   // sorted string -> group
 
    for (string &word : words) {
        string key = word;
        sort(key.begin(), key.end());   // sorted form is the shared key
        map[key].push_back(word);
    }
 
    vector<vector<string>> result;
    for (auto &pair : map) {
        result.push_back(pair.second);
    }
    return result;
}
 
int main() {
    int n;
    cout << "Enter number of words: ";
    cin >> n;
 
    vector<string> words(n);
    cout << "Enter " << n << " words: ";
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
 
    vector<vector<string>> groups = groupAnagrams(words);
 
    cout << "Anagram groups:\n";
    for (auto &group : groups) {
        cout << "[ ";
        for (string &w : group) cout << w << " ";
        cout << "]\n";
    }
 
    return 0;
}
