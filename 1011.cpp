#include <iostream>

using namespace std;

int main() {
    char s[4] = "WTL";
    double ans = 1.0;

    for (int i = 0; i < 3; i++) {
        double maxvalue = 0.0;
        int index = 0;
        for (int j = 0; j < 3; j++) {
            double temp = 0.0;
            cin >> temp;
            if (maxvalue < temp) {
                maxvalue = temp;
                index = j;
            }
        }
        ans *= maxvalue;
        cout << s[index] << " ";
    }

    printf("%0.2f", (ans * 0.65 - 1) * 2);
}

