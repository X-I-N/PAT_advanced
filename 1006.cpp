#include <iostream>
#include <string>

using namespace std;

int main() {
    string unlock_id, lock_id;
    int lock_time = 0;
    int unlock_time = 24 * 60 * 60;

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string id;
        cin >> id;
        int h1, m1, s1, h2, m2, s2;
        scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
        int time_in = h1 * 60 * 60 + m1 * 60 + s1;
        int time_out = h2 * 60 * 60 + m2 * 60 + s2;
        if (time_in < unlock_time) {
            unlock_time = time_in;
            unlock_id = id;
        }
        if (time_out > lock_time) {
            lock_time = time_out;
            lock_id = id;
        }
    }

    cout << unlock_id << " " << lock_id;
}

