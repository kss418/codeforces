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
ll a[MAX], num[2];

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = n - 1;i >= 1;i--){
        if(a[i] != a[i + 1]) continue;

        ll cnt = 0, diff = INF;
        vector <ll> v;
        for(int j = 1;j <= n;j++){
            if(j == i || j == i + 1) continue;
            v.push_back(a[j]);
        }

        for(int i = 0;i < v.size() - 1;i++){
            if(v[i + 1] - v[i] >= diff) continue;
            diff = v[i + 1] - v[i];
            num[1] = v[i + 1]; num[0] = v[i];
        }

        if(a[i] + a[i + 1] <= diff) break;
        cout << a[i] << " " << a[i + 1] << " ";
        cout << num[0] << " " << num[1] << "\n";
        return;
    }

    cout << -1 << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
