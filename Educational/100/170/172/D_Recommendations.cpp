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
class node{
public:
    ll l, r, idx;
    bool operator <(node& ot){
        if(l != ot.l) return l < ot.l;
        return r > ot.r;
    }
};
node a[MAX];
map <pll, ll> v;
map <ll, ll> num;

template <typename T = ll> // query type
class _mnseg { // 구간 예외 처리하기
public:
    ll n;
    class node{
    public:
        ll v;
        node() : node(INF){}
        node(ll v) {
            this->v = v;
        }

        node operator + (node ot){ // update
            ll now = min(v, ot.v);
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

    _mnseg(){}
    _mnseg(ll n) {
        this->n = n;
        arr.resize(n + 1); seg.resize(4 * n + 1);
    }

    T query(ll st, ll en) { return query(st, en, 0, n); }
    node query(ll st, ll en, ll l, ll r, ll node = 1) {
        if (en < l || st > r) return _mnseg::node();
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
}; _mnseg en(2 * MAX);

template <typename T = ll> // query type
class _mxseg { // 구간 예외 처리하기
public:
    ll n;
    class node{
    public:
        ll v;
        node() : node(-INF){}
        node(ll v) {
            this->v = v;
        }

        node operator + (node ot){ // update
            ll now = max(v, ot.v);
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

    _mxseg(){}
    _mxseg(ll n) {
        this->n = n;
        arr.resize(n + 1); seg.resize(4 * n + 1);
    }

    T query(ll st, ll en) { return query(st, en, 0, n); }
    node query(ll st, ll en, ll l, ll r, ll node = 1) {
        if (en < l || st > r) return _mxseg::node();
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
}; _mxseg st(2 * MAX);

ll cnt, result[MAX], org[2 * MAX]; vector <ll> use;
void init(ll idx){
    v.clear(); num.clear();
    use.clear(); cnt = 0;
    for(int i = 0;i <= 2 * idx;i++) st.update(i, 0);
    for(int i = 0;i <= 2 * idx;i++) en.update(i, INF);
}

void comp(){
    sort(all(use));
    for(auto& i : use){
        if(num.count(i)) continue;
        num[i] = ++cnt;
        org[cnt] = i;
    }

    for(int i = 1;i <= n;i++){
        a[i].l = num[a[i].l];
        a[i].r = num[a[i].r];
        v[{a[i].l, a[i].r}]++;
    }
}

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n; init(n);
        for(int i = 1;i <= n;i++){
            cin >> a[i].l >> a[i].r;
            use.push_back(a[i].l);
            use.push_back(a[i].r);
            a[i].idx = i;
        }
        comp(); sort(a + 1, a + n + 1);

        for(int i = 1;i <= n;i++){
            auto [l, r, idx] = a[i];
            if(v[{l, r}] >= 2) result[idx] = 0;
            else{
                ll q1 = st.query(r, 2 * n);
                ll q2 = en.query(r, 2 * n);
                if(!q1 || q2 == INF) result[idx] = 0;
                else result[idx] = org[q2] - org[r] + org[l] - org[q1];
            }
            st.update(r, l); en.update(r, r);
        }

        for(int i = 1;i <= n;i++) cout << result[i] << "\n";
    }


    return 0;
}
