#include <cstdio> //much faster than cin/cout
#include <algorithm>

using namespace std;
int a[1001][1001];
bool visit[1001];
int n;

void dfs(int idx) {
    visit[idx] = true;
    for (int i = 1; i <= n; i++) {
        if (!visit[i] && a[idx][i] == 1) {
            dfs(i);
        }
    }
}

int main() {
    int m, k, x, y;
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        a[x][y] = a[y][x] = 1;
    }

    for (int i = 0; i < k; i++) {
        fill(visit, visit + 1001, false);
        scanf("%d", &x);
        visit[x] = true;
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (!visit[j]) {
                dfs(j);
                cnt++;
            }
        }
        printf("%d\n", cnt - 1);
    }


}

