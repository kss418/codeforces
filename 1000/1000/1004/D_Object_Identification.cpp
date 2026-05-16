#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
ll a[MAX], q1, q2, cnt[MAX];

void q(ll st, ll en){
    cout << "? " << st << " " << en << endl;
}

void ret(char c){
    cout << "! " << c << endl;
}

void init(){
    for(int i = 1;i <= n;i++) cnt[i] = 0;
}

void run(){
    cin >> n; ll mx = 1, mn = 1; init();
    for(int i = 1;i <= n;i++) cin >> a[i], cnt[a[i]] = 1;
    if(accumulate(cnt + 1, cnt + n + 1, 0ll) == n){
        for(int i = 1;i <= n;i++){
            if(a[i] == 1) mn = i;
            if(a[i] == n) mx = i;
        }

        q(mn, mx); cin >> q1;
        q(mx, mn); cin >> q2;
        if(q1 != n - 1){ ret(q1 < n - 1 ? 'A' : 'B'); return; }
        else{ ret(q2 == n - 1 ? 'B' : 'A'); return; }
    }
    else{
        for(int i = 1;i <= n;i++){
            if(cnt[i]) continue;
            q(i, i == n ? 1 : i + 1); cin >> q1;
            ret(q1 ? 'B' : 'A'); return;
        }
    }
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
