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
constexpr ll MAX = 55; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];

bool chk(ll cy, ll cx){
    for(int i = 0;i <= cy;i++){
        if(st[i][cx] == '0') break;
        if(i == cy) return 1;
    }

    for(int i = 0;i <= cx;i++){
        if(st[cy][i] == '0') break;
        if(i == cx) return 1;
    }

    return 0;
}

void run(){
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> st[i];

    ll result = 1;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(st[i][j] == '0') continue;
            if(!chk(i, j)) result = 0;
        }
    }

    cout << (result ? "YES" : "NO") << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
