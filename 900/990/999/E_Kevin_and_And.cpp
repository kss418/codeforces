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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[11];
ll num[5010], c[5010], mn[5010];

void run(){
    cin >> n >> m >> k;
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < m;i++) cin >> b[i];

    for(int i = 0;i < (1ll << m);i++){
        ll now = (1ll << 30) - 1, cnt = 0;
        for(int j = 0;j < m;j++){
            if(!(i & (1ll << j))) continue;
            now &= b[j]; cnt++;
        }
        num[i] = now; c[i] = cnt;
    }

    vector <ll> arr;
    for(int i = 0;i < n;i++){
        memset(mn, 0x3f, sizeof(mn));
        for(int j = 0;j < (1ll << m);j++){
            mn[c[j]] = min(mn[c[j]], a[i] & num[j]);
        }

        for(int j = 1;j <= m;j++) arr.push_back(mn[j - 1] - mn[j]);
    }

    sort(rall(arr));
    ll result = accumulate(a, a + n, 0ll);
    for(int i = 0;i < k;i++) result -= arr[i];

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
