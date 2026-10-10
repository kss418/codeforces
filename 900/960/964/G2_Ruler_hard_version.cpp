#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long; using u64 = uint64_t;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;

class _ts { // integer
public:
    template <class F>
    static ll max(ll l, ll r, const F& f) {
        while (r - l > 3) {
            ll st = (2 * l + r) / 3, en = (l + 2 * r) / 3;
            if(f(st) < f(en)) l = st;
            else r = en;
        }

        ll result = MINF;
        for(ll cur = l; cur <= r;cur++) result = std::max(result, f(cur));
        return result;
    }

    template <class F>
    static ll min(ll l, ll r, const F& f) {
        while (r - l > 3) {
            ll st = (2 * l + r) / 3, en = (l + 2 * r) / 3;
            if(f(st) > f(en)) l = st;
            else r = en;
        }

        ll result = INF;
        for(ll cur = l; cur <= r;cur++) result = std::min(result, f(cur));
        return result;
    }
};

void run(){
    int lo = 1, hi = 1000;
    while(lo < hi){
        int l = (2 * lo + hi) / 3, r = (lo + 2 * hi) / 3;
        cout << "? " << l << " " << r << endl;
        int v; cin >> v;

        if(v == l * r) lo = r + 1;
        else if(v == l * (r + 1)) lo = l + 1, hi = r;
        else hi = l;
    }

    cout << "! " << lo << endl;
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}