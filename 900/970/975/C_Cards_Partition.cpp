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
ll arr[MAX], sum, mx;

class _bs { // 0-based index
public:
    ll l, r;
    _bs(ll l, ll r) {
        this->l = l; this->r = r;
    }

    ll f(ll cur) {
        if(sum / cur < mx) return 0;
        return 1;
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
        cin >> n >> m;

        mx = 0; sum = 0;
        for(int i = 1;i <= n;i++) {
            cin >> arr[i];
            sum += arr[i];
            mx = max(mx, arr[i]);
        }
        ll mul = mx * n;
        m = min(m, mul - sum);
        sum += m;

        _bs bs(1, 1e11);
        ll l = sum - m, r = sum;
        for(int i = bs.ret();i >= 1;i--){
            if(l % i > r % i){
                cout << i << "\n";
                break;
            }

            if(l % i <= r % i && r - l >= i){
                cout << i << "\n";
                break;
            }

            if(l % i == 0 || r % i == 0){
                cout << i << "\n";
                break;
            }
        }
    }

    return 0;
}
