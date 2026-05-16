#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX][4], sum[MAX][4];
set <ll> num[4];
ll dp[MAX][4], flag;
map <ll, ll> track[4];

void solve(ll a, ll b, ll c) {
    pll ret[4];
    for (int i = 1; i <= 3; i++) ret[i] = { INF, INF };

    ret[a] = { 1, dp[1][a] };
    if (dp[1][a] > n) return;
    ll cur = dp[1][a];
    ret[b] = { cur + 1, dp[cur + 1][b] };
    if (dp[cur + 1][b] > n) return;
    cur = dp[cur + 1][b];
    ret[c] = { cur + 1, dp[cur + 1][c] };

    ll f = 1;
    for (int i = 1; i <= 3; i++) {
        if (ret[i].first >= INF || ret[i].second >= INF) f = 0;
        if (ret[i].first > n || ret[i].second > n) f = 0;
        if (ret[i].first <= 0 || ret[i].second <= 0) f = 0;
    }

    if (f) {
        flag = 1;
        for (int i = 1; i <= 3; i++) cout << ret[i].first << " " << ret[i].second << " ";
        cout << "\n";
    }
}

int main() {
    fastio;
    cin >> t;

    while (t--) {
        cin >> n;

        long double tot = 0;
        flag = 0;

        for (int i = 1; i <= 3; i++) {
            track[i].clear();
            num[i].clear();
            for (int j = 1; j <= n; j++) {
                cin >> arr[j][i];
                sum[j][i] = sum[j - 1][i] + arr[j][i];
                num[i].insert(sum[j][i]);
                track[i][sum[j][i]] = j;
            }
        }
        for (int i = 1; i <= n; i++) tot += arr[i][1];

        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= n; j++) {
                ll pl = ceil(tot / 3);
                ll nxt = pl + sum[j - 1][i];
                auto it = num[i].lower_bound(nxt);
                if (it == num[i].end()) dp[j][i] = INF;
                else dp[j][i] = track[i][*it];
                num[i].erase(sum[j][i]);
            }
        }

        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                for (int k = 1; k <= 3; k++) {
                    if (i == j || j == k || i == k) continue;
                    if (flag) break;
                    solve(i, j, k);
                }
            }
        }

        if (!flag) cout << -1 << "\n";
    }

    return 0;
}
