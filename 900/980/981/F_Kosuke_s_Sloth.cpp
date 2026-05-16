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
constexpr ll MAX = 1010101;
constexpr ll MOD = 1e9 + 7;

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m; n %= MOD;
        ll pre = 0, nxt = 1, idx = -1;

        for(int i = 2;i <= 401010;i++){
            ll cur = (pre + nxt) % m;
            pre = nxt; nxt = cur;
            if(cur) continue;
            idx = i; break;
        }
        if(m == 1) idx = 1;

        cout << (idx * n) % MOD << "\n";
    }

    return 0;
}
