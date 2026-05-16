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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll arr[MAX];

class _bs { // 0-based index
public:
    ll l, r;
    _bs(ll l, ll r) {
        this->l = l; this->r = r;
    }

    ll f(ll cur) {
        ll sq = sqrt(cur);
        if(sq * sq > cur) sq--;

        ll cnt = cur - sq;
        if(cnt < n) return 1;
        return 0;
    }

    ll ret() {
        ll lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo + 1) >> 1;
            if (f(mid)) lo = mid;
            else hi = mid - 1;
        }

        return lo;
    }
};

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n;
        _bs bs(1, 2e18);
        cout << bs.ret() + 1 << "\n";
    }


    return 0;
}
