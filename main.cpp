#include <iostream>

using namespace std;

int main() {
    int k1, k2=0;
    cin >> k1;
    double a[1001] = {0.0,};
    double b[2001] = {0.0,};
    for (int i = 0; i < k1; i++) {
        int index;
        cin >> index;
        cin >> a[index];
    }

    cin >> k2;
    for (int j = 0; j < k2; j++) {
        int index2 = 0;
        double x = 0;
        cin >> index2;
        cin >> x;
        for (int k = 0; k <= 1001; k++) {
            b[k + index2] += x * a[k];
        }
    }

    int cnt = 0;
    for (double f : b) {
        if (f != 0.0) cnt++;
    }
    cout << cnt;
    for (int i = 2000; i >= 0; i--) {
        if (b[i] != 0.0) {
            printf(" %d %.1f", i, b[i]);
        }
    }


}

