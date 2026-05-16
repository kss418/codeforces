#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX], num[MAX], result[MAX];
bool v[MAX];
vector <ll> grp[MAX];


void dfs(ll cur, ll cnt) {
    if (v[cur]) return;
    v[cur] = 1; grp[cnt].push_back(cur);
    num[cur] = cnt;

    dfs(arr[cur], cnt);
}

int main() {
    fastio;

    cin >> t;
    while (t--) {
        cin >> n;
        memset(v, 0, sizeof(v));
        memset(result, 0, sizeof(result));

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            grp[i].clear();
        }
        cin >> s;

        ll cnt = 1;
        for (int i = 1; i <= n; i++) {
            if (v[i]) continue;
            dfs(i, cnt); cnt++;
        }

        for (int i = 1; i < cnt; i++) {
            for (auto& j : grp[i]) {
                if (s[j - 1] == '1') continue;
                result[i]++;
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << result[num[i]] << " ";
        }
        cout << "\n";
    }


    return 0;
}
