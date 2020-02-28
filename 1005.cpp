#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int total=0;
    for(char c : s){
        total += (c - '0');
    }
    string t = to_string(total);
    string num[10] = {"zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    cout << num[t[0] - '0'];
    for (int i=1;i<t.length();i++){
        cout << " " << num[t[i] - '0'];
    }
}

