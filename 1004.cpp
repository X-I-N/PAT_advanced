#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v[100];
int result[100]={0,};
int max_depth = -1;

void dfs(int index, int depth);
int main() {
    int n, m;
    cin >> n >>m;
    int node, a;
    for(int i=0;i<m;i++){
        cin >> node >> a;
        for(int j=0;j<a;j++){
            int c;
            cin >> c;
            v[node].push_back(c);
        }
    }
    dfs(1,0);
    cout << result[0];
    for(int i=1;i<=max_depth;i++){
        cout << " " << result[i];
    }

}

void dfs(int index, int depth){
    if(v[index].empty()){
        result[depth]++;
        max_depth = max(max_depth, depth);
        return;
    }

    for(int i : v[index]){
        dfs(i, depth+1);
    }
}