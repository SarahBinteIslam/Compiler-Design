#include <iostream>
#include <string>

using namespace std;

void print(const string & str) {
    cout << "Arithmetic operators: ";
    for (char c : str) {
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            cout << c << " ";
        }
    }
    cout << endl;
}

int main() {
    string str;
    cout << "Enter an expression: ";
    cin >> str;

    print(str);

    return 0;
}
