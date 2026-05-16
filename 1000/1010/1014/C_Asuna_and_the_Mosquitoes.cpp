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
ll a[MAX];

void run(){
    cin >> n; vector <ll> num[2];
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1, a + n + 1, greater<ll>());

    for(int i = 1;i <= n;i++){
        num[a[i] % 2].push_back(a[i]);
    }

    ll result = 0, cnt = num[0].size();
    if(!num[1].empty()) result += num[1][0];
    for(int i = 1;i < num[1].size();i++){
        result += num[1][i] - 1;
    }

    for(auto& i : num[0]) result += i;
    if(num[0].empty() || num[1].empty()) cout << a[1] << "\n";
    else cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
