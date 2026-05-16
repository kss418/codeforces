#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;
int n;
ll arr[200001][3];
ll dp[200001][3];
ll result = 1e12;
priority_queue <pair <ll, int>> dist1, dist2, dist3, dist4;


void bfs(int x, int y, ll time) {
    time = max(time, arr[x][y] + 1);
    dp[x][y] = time;

    if (y == 1) {
        while (!dist1.empty() && dist1.top().second <= x) {
            dist1.pop();
        }

        if (!dist1.empty()) {
            time = max(time + n - x, dist1.top().first);
        }
        else {
            time = time + n - x;
        }



        if (dp[x][y ^ 3]) {
            while (!dist2.empty() && dist2.top().second <= x) {
                dist2.pop();
            }

            if (!dist2.empty()) {
                time = max(time + n - x, dist2.top().first - x);
            }
            else {
                time = time + n - x;
            }
        }
        else {
            while (!dist2.empty() && dist2.top().second < x) {
                dist2.pop();
            }

            if (!dist2.empty()) {
                time = max(time + n - x + 1, dist2.top().first - x + 1);
            }
            else {
                time = time + n - x + 1;
            }
        }
    }
    else {
        while (!dist4.empty() && dist4.top().second <= x) {
            dist4.pop();
        }

        if (!dist4.empty()) {
            time = max(time + n - x, dist4.top().first);
        }
        else {
            time = time + n - x;
        }



        if (dp[x][y ^ 3]) {
            while (!dist3.empty() && dist3.top().second <= x) {
                dist3.pop();
            }

            if (!dist3.empty()) {
                time = max(time + n - x, dist3.top().first - x);
            }
            else {
                time = time + n - x;
            }
        }
        else {
            while (!dist3.empty() && dist3.top().second < x) {
                dist3.pop();
            }

            if (!dist3.empty()) {
                time = max(time + n - x + 1, dist3.top().first - x + 1);
            }
            else {
                time = time + n - x + 1;
            }
        }
    }


    result = min(time, result);
}




int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);


    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        fill(&dp[0][0], &dp[n][3], 0);
        while (!dist1.empty()) {
            dist1.pop();
        }
        while (!dist2.empty()) {
            dist2.pop();
        }
        while (!dist3.empty()) {
            dist3.pop();
        }
        while (!dist4.empty()) {
            dist4.pop();
        }

        result = 1e12;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i][1];
            dist1.push({ arr[i][1] + n - i + 1,i });
            dist3.push({ arr[i][1] + i,i });
        }

        for (int i = 1; i <= n; i++) {
            cin >> arr[i][2];
            dist2.push({ arr[i][2] + i,i });
            dist4.push({ arr[i][2] + n - i + 1,i });
        }

        dp[0][1] = -1;
        arr[1][1] = -1;
        for (int i = 1; i <= n; i++) {
            if (i % 2) {
                bfs(i, 1, dp[i - 1][1] + 1);

                bfs(i, 2, dp[i][1] + 1);
            }
            else {
                bfs(i, 2, dp[i - 1][2] + 1);

                bfs(i, 1, dp[i][2] + 1);
            }
        }



        cout << result << "\n";
    }

    return 0;
}
