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
constexpr ll MAX = 21; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], cnt[MAX];

bool chk(){
    if(cnt[0] < 3) return 0;
    if(cnt[1] < 1) return 0;
    if(cnt[2] < 2) return 0;
    if(cnt[3] < 1) return 0;
    if(cnt[5] < 1) return 0;
    return 1;
}

void run(){
    cin >> n; memset(cnt, 0, sizeof(cnt));
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++){
        cnt[a[i]]++;
        if(!chk()) continue;
        cout << i << "\n"; return;
    }

    cout << 0 << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
