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
ll a[MAX];

pll pos(ll num, ll cnt){
    pll ret = {0, 0};
    if(!cnt) return ret;

    ll mul = 1ll << (2 * cnt - 2);
    ll div = num / mul, mod = num % mul;
    ll mv = 1ll << (cnt - 1);

    pll nxt = pos(mod, cnt - 1);
    if(div == 1) ret.x += mv, ret.y += mv;
    else if(div == 2) ret.x += mv;
    else if(div == 3) ret.y += mv;

    ret.x += nxt.x; ret.y += nxt.y;
    return ret;
}

ll num(ll cy, ll cx){
    ll ret = 0;
    for(int i = n - 1;i >= 0;i--){
        ll now = 1ll << i;
        if(cy >= now && cx >= now) ret += now * now;
        else if(cy >= now) ret += 2 * now * now;
        else if(cx >= now) ret += 3 * now * now;
        cy %= now; cx %= now;
    }

    return ret + 1;
}

void run(){
    cin >> n >> m;
    while(m--){
        cin >> s;
        if(s == "->"){
            ll y, x; cin >> y >> x;
            cout << num(y - 1, x - 1) << "\n";
        }
        else{
            ll num; cin >> num;
            pll now = pos(num - 1, n);
            cout << now.x + 1 << " " << now.y + 1 << "\n";
        }
    }
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
