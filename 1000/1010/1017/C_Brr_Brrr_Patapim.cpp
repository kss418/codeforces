#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX];
bool cnt[2 * MAX];

void run(){
    cin >> n; memset(cnt, 0, sizeof(cnt));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> a[i][j];
            cnt[a[i][j]] = 1;
        }
    }

    ll fi = -1;
    for(int i = 1;i <= 2 * n;i++) if(!cnt[i]) fi = i;

    cout << fi << " ";
    for(int i = 1;i <= n;i++) cout << a[i][1] << " ";
    for(int i = 2;i <= n;i++) cout << a[n][i] << " ";
    cout << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}