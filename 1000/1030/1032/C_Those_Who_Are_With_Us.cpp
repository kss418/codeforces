#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long; using u64 = uint64_t;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <vector <int>> a;
ll cy[MAX], cx[MAX];

void run(){
    cin >> n >> m; 
    a.assign(n + 1, vector<int>(m + 1, 0));

    ll mx = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> a[i][j];
            mx = max<ll>(mx, a[i][j]);
        }
    }

    ll all = 0;
    for(int i = 1;i <= n;i++) cy[i] = 0;    
    for(int j = 1;j <= m;j++) cx[j] = 0;

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(a[i][j] != mx) continue;
            cy[i]++; cx[j]++; all++;
        }
    }

    bool fmx = 0, fmn = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            ll cmx = cy[i] + cx[j] - (a[i][j] == mx);
            fmx |= (cmx == all);
        }
    }

    cout << mx - fmx << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}