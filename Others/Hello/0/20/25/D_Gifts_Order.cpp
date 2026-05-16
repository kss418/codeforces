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
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

template <typename T = ll> // query type
class _seg { // 구간 예외 처리하기
public:
    ll n;
    class node{
    public:
        pll mx, mn; ll ret;
        node() : node({-INF, -INF}, {INF, INF}, 0){}
        node(ll a, ll b) : node({b, a}, {a, b}, 0){};
        node(pll mx, pll mn, ll ret) {
            this->mx = mx;
            this->mn = mn;
            this->ret = ret;
        }

        node operator + (node ot){ // update
            pll now1 = {max(mx.x, ot.mx.x), max(mx.y, ot.mx.y)}; 
            pll now2 = {min(mn.x, ot.mn.x), min(mn.y, ot.mn.y)}; 
            ll now3 = max({ot.ret, ret, mx.x - ot.mn.y, ot.mx.y - mn.x});

            return node(now1, now2, now3);
        }

        node operator += (T ot){ // add
            this->mx += ot; this->mn += ot;
            return node(mx, mn);
        }

        operator T(){ // update -> query
            return ret;
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

    node update(ll idx, node val) { return update(idx, val, 0, n); }
    node update(ll idx, node val, ll l, ll r, ll node = 1) {
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
};

void run(){
    cin >> n >> m; _seg seg(n);
    for(int i = 1;i <= n;i++) cin >> a[i], seg.update(i, _seg<ll>::node(a[i] - i, a[i] + i));
    cout << seg.query(1, n) << "\n";

    for(int i = 1;i <= m;i++){
        ll idx, val; cin >> idx >> val;
        seg.update(idx, _seg<ll>::node(val - idx, val + idx));
        cout << seg.query(1, n) << "\n";
    }
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}
