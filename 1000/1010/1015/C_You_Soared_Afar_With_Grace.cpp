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
ll a[MAX], b[MAX];
ll pa[MAX], pb[MAX];
vector <pll> result;

void sw(ll ai, ll bi){
    result.push_back({ai, bi});
    swap(pa[a[ai]], pa[a[bi]]);
    swap(a[ai], a[bi]);

    swap(pb[b[ai]], pb[b[bi]]);
    swap(b[ai], b[bi]);
}

void run(){
    cin >> n; result.clear();
    for(int i = 1;i <= n;i++) cin >> a[i], pa[a[i]] = i;
    for(int i = 1;i <= n;i++) cin >> b[i], pb[b[i]] = i;

    ll cnt = 0;
    for(int i = 1;i <= n;i++){
        if(a[i] == b[i]) cnt++;
        if(pb[a[i]] == pa[b[i]]) continue;
        cout << -1 << "\n"; return;
    }
    if(cnt != n % 2){ cout << -1 << "\n"; return; }

    if(n % 2) for(int i = 1;i <= n;i++){
        if(a[i] != b[i]) continue;
        if(i == (n + 1) / 2) continue;
        sw(i, (n + 1) / 2); break;
    }

    for(int i = (n + 1) / 2 + 1;i <= n;i++){
        if(a[i] == b[n - i + 1]) continue;
        sw(pb[a[i]], n - i + 1);
    }

    cout << result.size() << "\n";
    for(auto& [x, y] : result) cout << x << " " << y << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
