#include <bits/stdc++.h>
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
ll a[MAX], cnt[3];

void run(){
    cin >> n >> m; cnt[0] = cnt[1] = cnt[2] = 0;
    ll result = 0, sum = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i]; sum += a[i];
        cnt[a[i]]++;
    }

    if(m % 2 != cnt[1] % 2) result += 2;
    result += sum;

    if(m >= result) cout << -1 << "\n";
    else{
        for(int i = 1;i <= cnt[1];i++) cout << 1 << " ";
        for(int i = 1;i <= cnt[2];i++) cout << 2 << " ";
        for(int i = 1;i <= cnt[0];i++) cout << 0 << " ";
        cout << "\n";
    }
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
