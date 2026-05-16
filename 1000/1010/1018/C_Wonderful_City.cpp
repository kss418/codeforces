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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll h[MAX][MAX], co[2][MAX];
ll dp1[MAX][2], dp2[MAX][2];

ll solve1(ll cur, ll cnt){
    ll& ret = dp1[cur][cnt];
    if(ret != -1) return ret; ret = INF;
    if(!cur) return ret = 0;

    bool zero = 0, pos = 0, neg = 0;
    for(int i = 1;i <= n;i++){
        if(h[i][cur] - h[i][cur - 1] == 0) zero = 1;
        if(h[i][cur] - h[i][cur - 1] == 1) pos = 1;
        if(h[i][cur] - h[i][cur - 1] == -1) neg = 1;
    }

    if(cnt){
        if(!zero) ret = min(ret, solve1(cur - 1, 1) + co[1][cur]);
        if(!neg) ret = min(ret, solve1(cur - 1, 0) + co[1][cur]);
    }
    else{
        if(!zero) ret = min(ret, solve1(cur - 1, 0));
        if(!pos) ret = min(ret, solve1(cur - 1, 1));
    }

    return ret;
}

ll solve2(ll cur, ll cnt){
    ll& ret = dp2[cur][cnt];
    if(ret != -1) return ret; ret = INF;
    if(!cur) return ret = 0;

    bool zero = 0, pos = 0, neg = 0;
    for(int i = 1;i <= n;i++){
        if(h[cur][i] - h[cur - 1][i] == 0) zero = 1;
        if(h[cur][i] - h[cur - 1][i] == 1) pos = 1;
        if(h[cur][i] - h[cur - 1][i] == -1) neg = 1;
    }

    if(cnt){
        if(!zero) ret = min(ret, solve2(cur - 1, 1) + co[0][cur]);
        if(!neg) ret = min(ret, solve2(cur - 1, 0) + co[0][cur]);
    }
    else{
        if(!zero) ret = min(ret, solve2(cur - 1, 0));
        if(!pos) ret = min(ret, solve2(cur - 1, 1));
    }

    return ret;
}

void run(){
    cin >> n; memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) cin >> h[i][j];
    }

    for(int i = 0;i <= 1;i++){
        for(int j = 1;j <= n;j++) cin >> co[i][j];
    }

    ll result = min(solve1(n, 0), solve1(n, 1)) + min(solve2(n, 0), solve2(n, 1));
    cout << (result >= INF ? -1 : result) << "\n";
}

int main() {
    fastio; cin >> t;
    for(int i = 0;i < MAX;i++) h[i][0] = h[0][i] = MINF;
    while(t--) run();

    return 0;
}
