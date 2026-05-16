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
ll x[MAX], y[MAX];

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n; ll sx, sy, ex, ey;
        for(int i = 1;i <= n;i++) cin >> x[i] >> y[i];
        cin >> sx >> sy >> ex >> ey;

        ll dx = ex - sx, dy = ey - sy;
        ll st = dx * dx + dy * dy;

        ll flag = 1;
        for(int i = 1;i <= n;i++){
            ll dx = x[i] - ex, dy = y[i] - ey;
            ll cur = dx * dx + dy * dy;
            if(cur <= st) { flag = 0; break; } 
        }

        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

