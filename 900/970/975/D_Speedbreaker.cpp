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
ll a[MAX]; pll arr[MAX];

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++) {
            cin >> a[i]; arr[i] = {INF, -INF};
        }

        for(int i = 1;i <= n;i++){
            pll& cur = arr[a[i]];
            cur.x = min<ll>(cur.x, i);
            cur.y = max<ll>(cur.y, i);
        }

        ll l = 1, r = n, flag = 1;
        ll ml = INF, mr = -INF;
        for(int i = 1;i <= n;i++){
            if(arr[i].y == -INF) continue;
            ml = min(ml, arr[i].x); mr = max(mr, arr[i].y);
            if(mr - ml + 1 > i) flag = 0;
            l = max(l, arr[i].y - i + 1);
            r = min(r, arr[i].x + i - 1);
        }

        if(!flag || r - l + 1 <= 0) cout << 0 << "\n";
        else cout << r - l + 1 << "\n";
    }


    return 0;
}
