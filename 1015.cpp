#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    int t = int(sqrt(n));
    for (int i = 2; i <= t; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n = 0, d = 0;
    do {
        cin >> n;
        if (n < 0) break;
        cin >> d;

        if (!is_prime(n)) {
            cout << "No" << endl;
            continue;
        }
        int len = 0, a[100];
        do {
            a[len++] = n % d;
            n /= d;
        } while (n != 0);
        int r = 0;
        for (int i = 0; i < len; i++) {
            r += int(pow(d, i)) * a[len - 1 - i];
        }
        cout << (is_prime(r) ? "Yes" : "No") << endl;
    } while (true);

    return 0;
}
