#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
set <ll> num[6], mnum[6];
string st[MAX];
ll d[MAX][6];

ll trn(string st) {
    if (st == "BG") return 0;
    else if (st == "BR") return 1;
    else if (st == "BY") return 2;
    else if (st == "GR") return 3;
    else if (st == "GY") return 4;
    else return 5;
}

int main()
{
    fastio;
    cin >> t;
    while (t--) {
        cin >> n >> m;

        for (int i = 0; i < 6; i++) {
            num[i].clear();
            mnum[i].clear();
        }

        for (int i = 1; i <= n; i++) {
            cin >> st[i];
            num[trn(st[i])].insert(i);
            mnum[trn(st[i])].insert(-i);
        }

        while (m--) {
            ll x, y;
            cin >> x >> y;
            if (x > y) swap(x, y);
            if (x == y) { cout << 0 << "\n"; continue; }

            char xf = st[x][0], xs = st[x][1];
            char ef = st[y][0], es = st[y][1];

            if (xf == ef || xf == es || xs == ef || xs == es) {
                cout << y - x << "\n";
                continue;
            }
            else{
                ll cur = trn(st[x]);

                ll nxt = INF;
                for (int i = 0; i < 6; i++) {
                    if (i == cur || i + cur == 5) continue;
                    if (num[i].upper_bound(x) == num[i].end()) continue;
                    nxt = min(nxt, *num[i].upper_bound(x));
                }

                if (y >= nxt) {
                    cout << y - x << "\n";
                    continue;
                }

                ll pre = 0;
                for (int i = 0; i < 6; i++) {
                    if (i == cur || i + cur == 5) continue;
                    if (mnum[i].upper_bound(-x) == mnum[i].end()) continue;
                    pre = max(pre, -*mnum[i].upper_bound(-x));
                }

                if (nxt == INF && pre == 0) cout << -1 << '\n';
                else if (pre != 0) cout << min(2 * nxt - x - y, x + y - 2 * pre) << '\n';
                else cout << 2 * nxt - x - y << "\n";
            }
        }
    }




    return 0;
}
