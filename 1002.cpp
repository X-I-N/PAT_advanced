//
// Created by 17738 on 2020/1/30.
//
#include <iostream>

using namespace std;

int main() {
    float total[1001] = {0.0,};
    int cnt = 0;
    int a, p;
    cin >> a;
    for (int i = 0; i < a; i++) {
        int b;
        float c;
        cin >> b >> c;
        total[b] += c;
    }
    cin >> p;
    for (int i = 0; i < p; i++) {
        int q;
        float r;
        cin >> q >> r;
        total[q] += r;
    }

    for (float i : total) {
        if (i != 0) cnt++;
    }
    cout << cnt;
    for (int i = 1000; i >= 0; i--) {
        if (total[i] != 0.0) printf(" %d %.1f", i, total[i]);

    }
    return 0;
}