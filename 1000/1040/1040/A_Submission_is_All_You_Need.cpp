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
ll a[MAX];

void run(){
    cin >> n;
    ll result = 0, c0 = 0, c1 = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] == 0) c0++;
        else if(a[i] == 1) c1++;
    }

    ll mn = min(c0, c1); c0 -= mn;
    for(int i = 1;i <= n;i++){
        if(a[i] == 1 && mn) result += 2, mn--;
        else if(!a[i] && c0) result++, c0--;
        else result += a[i];
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
