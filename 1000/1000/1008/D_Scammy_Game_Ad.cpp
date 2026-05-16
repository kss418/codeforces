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
constexpr ll MAX = 33; // SET MAX SIZE
constexpr ll MOD = 998244353;
char c[2][MAX];
ll cnt[3], a[2][MAX];

void run(){
    cin >> n; cnt[0] = cnt[1] = 1; cnt[2] = 0;
    c[0][n + 1] = c[1][n + 1] = 'x';
    a[0][n + 1] = a[1][n + 1] = 1;

    for(int i = 1;i <= n;i++){
        for(int j = 0;j < 2;j++) cin >> c[j][i] >> a[j][i];
    }

    for(int i = 1;i <= n;i++){
        for(int j = 0;j < 2;j++){
            if(c[j][i] == '+') cnt[2] += a[j][i];
            else cnt[2] += cnt[j] * (a[j][i] - 1);
        }

        if(c[0][i + 1] == '+' && c[1][i + 1] == '+') continue;
        else if(c[1][i + 1] == '+') cnt[0] += cnt[2];
        else if(c[0][i + 1] == '+') cnt[1] += cnt[2];
        else{
            if(a[0][i + 1] > a[1][i + 1]) cnt[0] += cnt[2];
            else if(a[1][i + 1] > a[0][i + 1]) cnt[1] += cnt[2];
            else { cnt[2] *= a[0][i + 1]; continue; }
        }
        cnt[2] = 0;
    }

    cout << cnt[0] + cnt[1] + cnt[2] << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
