#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int64_t get_value(string s, long radix) {
    int64_t v = 0;
    int len = s.length();
    for (int i = len - 1; i >= 0; i--) {
        int ch = s[i];
        ch -= ch < 58 ? '0' : ('a' - 10);
        v += ch * pow(radix, len - 1 - i);
    }

    return v;
}

int main() {
    string n1, n2;
    int64_t tag, radix;

    cin >> n1 >> n2 >> tag >> radix;

    string s1, s2;
    s1 = tag == 1 ? n1 : n2;
    s2 = tag == 1 ? n2 : n1;
    int64_t value;
    value = get_value(s1, radix);

    int max_digit = 0;
    for (char c : s2) {
        c -= c < 58 ? '0' : ('a' - 10);
        max_digit = max(max_digit, int(c));
    }

    if (max_digit > value) {
        cout << "Impossible";
        return 0;
    } else {
        int64_t low = max_digit + 1;
        int64_t high = max(low, value);
        while(low <= high){
            int64_t mid = (high + low)/2;
            int64_t v = get_value(s2, mid);
            if(v < 0 || v > value){
                high = mid - 1;
            } else if(v == value){
                cout << mid;
                return 0;
            }else{
                low = mid + 1;
            }
        }
    }

    cout << "Impossible";
    return 0;
}

