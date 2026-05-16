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
constexpr ll MAX = 505; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll sum[MAX][MAX];

void init(){
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            if(st[i - 1][j - 1] == 'g') sum[i][j]++;
        }
    }
}

ll cal(ll y1, ll x1, ll y2, ll x2){
    y1 = max(y1, 1ll); x1 = max(x1, 1ll);
    y2 = min(y2, n); x2 = min(x2, m);
    return sum[y2][x2] + sum[y1 - 1][x1 - 1] - sum[y1 - 1][x2] - sum[y2][x1 - 1];
}

void run(){
    cin >> n >> m >> k; ll mn = INF;
    for(int i = 0;i < n;i++) cin >> st[i]; init();
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(st[i - 1][j - 1] != '.') continue;
            ll now = cal(i - k + 1, j - k + 1, i + k - 1, j + k - 1);
            mn = min(mn, now);
        }
    }

    cout << cal(1, 1, n, m) - mn << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
