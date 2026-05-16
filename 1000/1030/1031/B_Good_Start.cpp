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

void run(){
    ll a, b; cin >> n >> m >> a >> b;
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    ll dx = abs(x2 - x1), dy = abs(y2 - y1);

    if(!dx && dy % b) cout << "No\n";
    else if(!dy && dx % a) cout << "No\n";
    else if(dx % a && dy % b) cout << "No\n";
    else cout << "Yes\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
