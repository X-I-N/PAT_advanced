#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m;
    cin >> m;
    vector<int> v(m);

    int sum = -1;
    int left_index = 0, right_index = 0;
    int temp = 0, temp_index = 0;

    for (int i = 0; i < m; i++) {
        cin >> v[i];
        temp += v[i];
        if (temp < 0) {
            temp = 0;
            temp_index = i + 1;
        } else if (temp > sum) {
            sum = temp;
            left_index = temp_index;
            right_index = i;
        }
    }

    if(sum < 0){
        sum = 0;
        right_index = m - 1;
    }
    cout << sum << " " << v[left_index] << " " << v[right_index];
}

