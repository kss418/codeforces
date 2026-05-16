#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], diff[MAX];

class _gcd {
public:
    _gcd() {}

    tll init(ll a, ll b) {
        if (!b) return { a, 1, 0 };
        auto [g, x, y] = init(b, a % b);
        return { g, y, x - a / b * y };
    }

    ll ret(ll a, ll b) {
        return get<0>(init(a, b));
    }

    ll inv(ll a, ll mod) {
        auto [g, x, y] = init(a, mod);
        if (!a || g != 1) return -1;
        return (x < 0 ? x + mod : x);
    }
}; _gcd g;

template <typename T = ll> // query type
class _seg { // 구간 예외 처리하기
public:
    ll n;
    class node{
    public:
        ll v;
        node() : node(0){}
        node(ll v) {
            this->v = v;
        }

        node operator + (node ot){ // update
            ll now = g.ret(v, ot.v);
            return node(now);
        }

        node operator += (T ot){ // add
            v += ot;
            return node(v);
        }

        operator T(){ // update -> query
            return v;
        }
    };
    vector <node> seg, arr;

    _seg(){}
    _seg(ll n) {
        this->n = n;
        arr.resize(n + 1); seg.resize(4 * n + 1);
    }

    T query(ll st, ll en) { return query(st, en, 0, n); }
    node query(ll st, ll en, ll l, ll r, ll node = 1) {
        if (en < l || st > r) return _seg::node();
        if (st <= l && en >= r) return seg[node];
        ll mid = (l + r) >> 1;
        return query(st, en, l, mid, node * 2) + query(st, en, mid + 1, r, node * 2 + 1);
    }

    node update(ll idx, ll val) { return update(idx, val, 0, n); }
    node update(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return seg[node];
        if (l == r) return seg[node] = val;
        ll mid = (l + r) >> 1;

        seg[node] = update(idx, val, l, mid, node * 2) + update(idx, val, mid + 1, r, node * 2 + 1);
        return seg[node];
    }

    void add(ll idx, ll val) { add(idx, val, 0, n); }
    void add(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return;
        seg[node] += val;
        if (l == r) return;
        ll mid = (l + r) >> 1;

        add(idx, val, l, mid, node * 2);
        add(idx, val, mid + 1, r, node * 2 + 1);
    }
}; _seg seg(MAX);


void init(ll idx){
    for(int i = 1;i <= idx;i++) seg.update(i, 0);
}

int main() {
    fastio;

    cin >> t; _gcd gcd;
    while(t--){
        cin >> n >> m; init(n);
        for(int i = 1;i <= n;i++) cin >> a[i];
        for(int i = 1;i <= n;i++) seg.update(i, abs(a[i] - a[i - 1]));

        while(m--){
            ll l, r; cin >> l >> r;
            if(l == r) cout << 0 << " ";
            else cout << seg.query(l + 1, r) << " ";
        }
        cout << "\n";
    }


    return 0;
}
