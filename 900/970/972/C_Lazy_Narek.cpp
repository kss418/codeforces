#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010;
constexpr ll MOD = 998244353;
string st[MAX];
string narek = "narek";
ll dp[5], tmp[5];

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0;i < n;i++) cin >> st[i];

        fill(dp, dp + 5, -INF);
        fill(tmp, tmp + 5, -INF);
        dp[0] = 0;

        for(int i = 0;i < n;i++){
            for(int j = 0;j < 5;j++) tmp[j] = dp[j];

            for(int j = 0;j < 5;j++){
                if(dp[j] == -INF) continue;
                ll cnt = 0, nxt = j;

                for(int k = 0;k < m;k++){
                    ll idx = narek.find(st[i][k]);
                    if(idx == -1) continue;

                    if(nxt == idx){
                        nxt++; nxt %= 5; cnt++;
                    }
                    else cnt--;
                }

                tmp[nxt] = max(tmp[nxt], dp[j] + cnt);
            }

            for(int j = 0;j < 5;j++) dp[j] = tmp[j];
        }

        ll result = 0;
        for(int i = 0;i < 5;i++) result = max(result, dp[i] - 2 * i);

        cout << result << "\n";
    }


    return 0;
}
