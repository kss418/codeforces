#include <bits/stdc++.h>
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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
char result[MAX];
deque <ll> q;

template <typename T = ll>
class _bs { // 0-based index
public:
    T l, r;
    _bs(T l, T r) {
        this->l = l; this->r = r;
    }

    bool f(T cur) {
        cout << "? " << cur << " ";
        for(int i = 1;i <= cur;i++) cout << i << " ";
        cout << endl;

        ll q; cin >> q;
        return q >= 1;
    }

    T ret() {
        T lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo) / (T)2;
            if (f(mid)) hi = mid;
            else lo = mid + 1;
        }

        return lo;
    }
};

void run(){
    cin >> n; _bs <ll> bs(1, n + 1);
    ll ret = bs.ret();
    if(ret == n + 1){
        ll lo = 2, hi = n;
        while(hi > lo){
            ll mid = (hi + lo) / 2;
            cout << "? 2 " << mid << " " << 1 << endl;
            ll q; cin >> q;
            if(q) hi = mid;
            else lo = mid + 1;
        }

        cout << "! ";
        for(int i = 1;i < lo;i++) cout << ")";
        for(int i = lo;i <= n;i++) cout << "(";
        cout << endl; return;
    }

    result[ret] = ')';
    result[ret - 1] = '(';

    for(int i = 1;i <= n;i++){
        if(i == ret - 1 || i == ret) continue;
        q.push_back(i);
    }

    while(!q.empty()){
        if(q.size() == 1){
            ll fi = q.front(); q.pop_front();
            cout << "? 2 " << fi << " " << ret << endl;
            ll qr; cin >> qr;

            if(qr == 1) result[fi] = '(';
            else result[fi] = ')';
        }
        else{
            ll fi = q.front(); q.pop_front();
            ll se = q.front(); q.pop_front();

            cout << "? 6 " << fi << " " << ret << " " << se << " ";
            cout << ret << " " << ret - 1 << " " << ret << endl;
            ll qr; cin >> qr;

            if(qr == 6) result[fi] = '(', result[se] = '(';
            else if(qr == 2) result[fi] = '(', result[se] = ')';
            else if(qr == 3) result[fi] = ')', result[se] = '(';
            else result[fi] = ')', result[se] = ')';
        }
    }

    cout << "! ";
    for(int i = 1;i <= n;i++) cout << result[i];
    cout << endl;
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
