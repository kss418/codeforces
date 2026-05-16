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
ll a[MAX], cnt[MAX];

void init(){
    for(int i = 1;i <= n;i++) a[i] = cnt[i] = 0;
}

bool chk(){
    for(int i = 1;i <= n;i++){
        if(cnt[a[i]]) return 0;
        if(!a[i]) return 0;
        cnt[a[i]]++;
    }

    return 1;
}

void run(){
    cin >> n; init();
    for(int i = 1;i <= n;i++) a[i] = (2 * i - 2) % n + 1;
    if(!chk()) cout << -1 << "\n";
    else{
        for(int i = 1;i <= n;i++) cout << a[i] << " ";
        cout << "\n";
    }
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
