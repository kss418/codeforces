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
constexpr ll MAX = 2010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX];
vector <ll> result;

bool chk(){
    for(int i = 1;i <= n;i++){
        for(int j = 2;j <= m;j++){
            if(a[i][j] - a[i][j - 1] != n) return 0;
        }
    }
    return 1;
}

void run(){
    cin >> n >> m; result.clear();
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) cin >> a[i][j];
        sort(a[i] + 1, a[i] + m + 1);
        result.push_back(i);
    }

    sort(all(result), [](ll l, ll r){
        return a[l][1] < a[r][1];
    });

    if(!chk()){ cout << -1 << "\n"; return; }
    for(auto& i : result) cout << i << " ";
    cout << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
