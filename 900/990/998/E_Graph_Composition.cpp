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
pll a[MAX], b[MAX];
class _uf {
public:
    ll n; vector <ll> p, si;

    _uf(){}
    _uf(ll n) {
        this->n = n;
        p.resize(n + 1, -1); si.resize(n + 1, 1);
    }

    ll find(ll num) {
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (size(a) < size(b)) swap(a, b);
        p[b] = a, si[a] += si[b];
    }

    ll size(ll num){ return si[find(num)]; }
    bool same(ll a, ll b) { return find(a) == find(b); }
};

void run(){
    cin >> n >> m >> k; ll result = 0;
    _uf uf1(n), uf2(n);
    for(int i = 1;i <= m;i++) cin >> a[i].x >> a[i].y;
    for(int i = 1;i <= k;i++){
        cin >> b[i].x >> b[i].y;
        uf1.merge(b[i].x, b[i].y);
    }

    for(int i = 1;i <= m;i++){
        if(uf1.same(a[i].x, a[i].y)) uf2.merge(a[i].x, a[i].y);
        else result++;
    }

    for(int i = 1;i <= k;i++){
        if(uf2.same(b[i].x, b[i].y)) continue;
        uf2.merge(b[i].x, b[i].y); result++;
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
