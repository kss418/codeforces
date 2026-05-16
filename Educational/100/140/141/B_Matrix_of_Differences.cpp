#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
ll n, m, k, t; string s;

const int MAX = 2501;

int diff;
int arr[52][52];
bool v[MAX];

void bfs(int x, int y, int cur) {
    if (x >= n || y >= n || x < 0 || y < 0) {
        return;
    }

    if (arr[y][x] || cur <= 0 || cur > n * n) {
        return;
    }

    if (v[cur] || diff == 1) {
        return;
    }

    arr[y][x] = cur;
    v[cur] = 1;
    diff--;

    bfs(x - 1, y, cur - diff);
    bfs(x - 1, y, cur + diff);
    bfs(x + 1, y, cur - diff);
    bfs(x + 1, y, cur + diff);
    bfs(x, y - 1, cur - diff);
    bfs(x, y - 1, cur + diff);
    bfs(x, y + 1, cur - diff);
    bfs(x, y + 1, cur + diff);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> n;
        fill(&arr[0][0], &arr[n + 1][n + 1], 0);
        fill(v, v + 2501, 0);
        diff = n * n;
        bfs(0, 0, n * n);
        int last = 0;
        for (int i = 1; i <= n * n; i++) {
            if (!v[i]) {
                last = i;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!arr[i][j]) {
                    arr[i][j] = last;
                }
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
    }


    return 0;
}
