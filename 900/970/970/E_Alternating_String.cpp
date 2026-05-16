#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll pre[MAX][26], suf[MAX][26];

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> s;

        for(int i = 0;i < 26;i++){
            pre[0][i] = pre[1][i] = 0;
            if(n >= 2) suf[n - 2][i] = 0;
            suf[n - 1][i] = 0;
            suf[n][i] = suf[n + 1][i] = 0;
        }

        pre[0][s[0] - 'a'] = 1;
        suf[n - 1][s[n - 1] - 'a'] = 1;
        if(n >= 2) pre[1][s[1] - 'a'] = 1;
        if(n >= 2) suf[n - 2][s[n - 2] - 'a'] = 1;

        for(int i = 2;i < n;i++){
            for(int j = 0;j < 26;j++){
                pre[i][j] = pre[i - 2][j];
                if(j == s[i] - 'a') pre[i][j]++;
            }
        }

        for(int i = n - 3;i >= 0;i--){
            for(int j = 0;j < 26;j++){
                suf[i][j] = suf[i + 2][j];
                if(j == s[i] - 'a') suf[i][j]++;
            }
        }

        ll mx = 0;
        if(n % 2){
            for(int i = 0;i < n;i++){
                ll even = 0, odd = 0;
                for(int j = 0;j < 26;j++){
                    ll cur = suf[i + 2][j];
                    if(i >= 1) cur += pre[i - 1][j];
                    even = max(cur, even);

                    cur = suf[i + 1][j];
                    if(i >= 2) cur += pre[i - 2][j];
                    odd = max(odd, cur);
                }

                mx = max(even + odd, mx);
            }
        }
        else {
            ll even = 0, odd = 0;
            for(int j = 0;j < 26;j++) {
                even = max(even, pre[n - 1][j]);
                if(n != 1) odd = max(odd, pre[n - 2][j]);
            }
            mx = max(even + odd, mx);
        }
        ll result = n - mx;

        cout << result << "\n";
    }


    return 0;
}
