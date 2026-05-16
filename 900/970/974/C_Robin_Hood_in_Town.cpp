#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
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
        ll sum = 0;
        for (int i = 1; i <= n; i++) sum += arr[i];
        sum += cur;
        ll avg = sum / (2 * n);
        if (sum % (2 * n)) avg++;
        ll cnt = 0;

        for (int i = 1; i < n; i++) {
            if (arr[i] < avg) {
                cnt++;
            }
        }

        if (cnt > n / 2) return 1;
        return 0;
    }

    ll ret() {
        ll lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo) >> 1;
            if (f(mid)) hi = mid;
            else lo = mid + 1;
        }

        return lo;
    }
};

int main() {
    fastio;

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> arr[i];

        sort(arr + 1, arr + n + 1);
        _bs bs(0, 2e12 + 10);

        ll ret = bs.ret();
        if (ret == 2e12 + 10) cout << -1 << '\n';
        else cout << bs.ret() << "\n";
    }


    return 0;
}
