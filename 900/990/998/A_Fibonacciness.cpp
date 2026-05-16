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
constexpr ll MAX = 11; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], result;

void cal(){
    ll ret = 0;
    for(int i = 3;i <= 5;i++){
        if(a[i] == a[i - 1] + a[i - 2]) ret++;
    }
    result = max(ret, result);
}

void run(){
    for(int i = 1;i <= 5;i++){
        if(i == 3) continue;
        cin >> a[i];
    }

    result = 0;
    a[3] = a[1] + a[2]; cal();
    a[3] = a[5] - a[4]; cal();
    a[3] = a[4] - a[2]; cal();

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
