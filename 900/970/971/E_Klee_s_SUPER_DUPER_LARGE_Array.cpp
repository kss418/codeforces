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
ll a[MAX];

ll sum(ll en){
    return en * (en + 1) / 2;
}

class _ts { // 0-based index
public:
    ll l, r;
    _ts(ll l, ll r) {
        this->l = l; this->r = r;
    }

    ll f(ll cur) {
       ll st = sum(cur) - sum(m - 1);
       ll en = sum(n + m - 1) - sum(cur);

       return abs(en - st);
    }

    ll ret() {
        while (r - l > 3) {
            ll st = (2 * l + r) / 3, en = (l + 2 * r) / 3;
            if(f(st) > f(en)) l = st;
            else r = en;
        }

        ll result = INF;
        for(ll cur = l; cur <= r;cur++) result = min(result, f(cur));

        return result;
    }
};


int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m;
        _ts ts(m, n + m - 1);
        cout << ts.ret() << "\n";
    }
    

    return 0;
}
