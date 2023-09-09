#include <iostream>
#include <string>
using namespace std;

string processString(const string &s) {
    string result;
    for (char c : s) {
        if (c == '#') {
            if (!result.empty()) {
                result.pop_back(); 
            }
        } else {
            result.push_back(c);
        }
    }
    return result;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    string processedS1 = processString(s1);
    string processedS2 = processString(s2);

    if (processedS1 == processedS2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
