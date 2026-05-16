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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], suf[MAX], pre[MAX];

ll cal(){
    ll ai = 0, bi = 0, ret = 0;
    while(ai + bi < n){
        if(a[ai] > b[bi]) ret++, ai++;
        else bi++;
    }

    return ret;
}

template <typename T = ll>
class _bs { // 0-based index
public:
    T l, r;
    _bs(T l, T r) {
        this->l = l; this->r = r;
    }

    bool f(T cur) {
        return cal() >= cur;
    }

    T ret() {
        T lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (lo + hi + 1) / (T)2;
            swap(a[pre[mid - 1]], a[suf[mid]]);
            if (f(mid)) lo = mid;
            else hi = mid - 1;
            swap(a[pre[mid - 1]], a[suf[mid]]);
        }

        return lo;
    }
};

void run(){
    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) cin >> b[i];

    pre[0] = 0;
    for(int i = 1;i < n;i++){
        pre[i] = pre[i - 1];
        if(a[i] < a[pre[i - 1]]) pre[i] = i;
    }

    suf[n - 1] = n - 1;
    for(int i = n - 2;i >= 0;i--){
        suf[i] = suf[i + 1];
        if(a[i] > a[suf[i + 1]]) suf[i] = i;
    }

    _bs <ll> bs(0, n - 1);
    cout << max(cal(), bs.ret()) << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
