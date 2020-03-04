#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int total = 0;
    vector<int> v(n+1);
    v[0] = 0;
    for(int i=1;i<n+1;i++){
        cin >> v[i];
        if(v[i] > v[i-1]){
            total += (v[i] - v[i-1]) * 6;
        }else if(v[i] < v[i-1]){
            total += (v[i-1] - v[i]) * 4;
        }
        total += 5;
    }

    cout << total;
}

