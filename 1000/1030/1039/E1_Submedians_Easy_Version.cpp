#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
constexpr ll MID = 300505;
ll a[MAX], st, en, pre[MAX], mn[2 * MAX];

template <typename T = ll>
class _bs { // 0-based index
public:
    T l, r;
    _bs(T l, T r) {
        this->l = l; this->r = r;
    }

    bool f(T cur) {
        ll ret = 0, cl = 0, cr = 0;
        for(int i = -n;i <= n;i++) mn[i + MID] = INF;
        mn[MID] = 0;

        for(int i = 1;i <= n;i++){
            pre[i] = pre[i - 1] + (a[i] >= cur ? 1 : -1);
            mn[pre[i] + MID] = min<ll>(mn[pre[i] + MID], i);
        }

        for(int i = -n + 1;i <= n;i++) mn[i + MID] = min(mn[i + MID], mn[i + MID - 1]);
        for(int i = 1;i <= n;i++){
            if(ret >= i - mn[pre[i] + MID]) continue;
            ret = i - mn[pre[i] + MID];
            cr = i; cl = mn[pre[i] + MID] + 1;
        }

        if(ret >= m) st = cl, en = cr;
        return ret >= m;
    }

    T ret() {
        T lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo + 1) / (T)2;
            if (f(mid)) lo = mid;
            else hi = mid - 1;
        }

        return lo;
    }
};

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    _bs <ll> bs(0, n + 1);

    cout << bs.ret() << " " << st << " " << en << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
