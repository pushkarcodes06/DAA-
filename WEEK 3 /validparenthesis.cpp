#include <bits/stdc++.h>
using namespace std;
 
bool isValid(string s) {
    stack<char> st;
 
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;   // closing with nothing open
 
            char top = st.top();
            st.pop();
 
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;                // mismatched pair
            }
        }
    }
    return st.empty();   // true only if everything was matched
}
 
int main() {
    string s;
    cout << "Enter a string of brackets: ";
    cin >> s;
 
    cout << "Is valid: " << (isValid(s) ? "true" : "false") << endl;
 
    return 0;
}
