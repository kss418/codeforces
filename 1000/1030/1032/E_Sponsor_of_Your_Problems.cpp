#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long; using u64 = uint64_t;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
string l, r;
ll dp[11][10][4];

ll solve(ll cur, ll num, ll f){
    ll& ret = dp[cur][num][f];
    if(ret != -1) return ret;

    ll pl = (num == (l[cur] - '0')) + (num == (r[cur] - '0'));
    if(cur + 1 == l.size()) return ret = pl; ret = INF;

    if(!f){
        for(int i = 0;i <= 9;i++){
            ret = min(ret, solve(cur + 1, i, 0) + pl);
        }
    }
    else if(f == 1){
        ret = min(ret, solve(cur + 1, l[cur + 1] - '0', 1) + pl);
        for(int i = l[cur + 1] - '0' + 1;i <= 9;i++){
            ret = min(ret, solve(cur + 1, i, 0) + pl);
        }
    }
    else if(f == 2){
        ret = min(ret, solve(cur + 1, r[cur + 1] - '0', 2) + pl);
        for(int i = 0;i < r[cur + 1] - '0';i++){
            ret = min(ret, solve(cur + 1, i, 0) + pl);
        }
    }
    else{
        if(l[cur + 1] == r[cur + 1]) ret = min(ret, solve(cur + 1, l[cur + 1] - '0', 3) + pl);
        else{
            ret = min(ret, solve(cur + 1, l[cur + 1] - '0', 1) + pl);
            ret = min(ret, solve(cur + 1, r[cur + 1] - '0', 2) + pl);
            for(int i = l[cur + 1] - '0' + 1;i < r[cur + 1] - '0';i++){
                ret = min(ret, solve(cur + 1, i, 0) + pl);
            }
        }
    }

    return ret;
}

void run(){
    cin >> l >> r; memset(dp, -1, sizeof(dp));
    ll result = INF;

    if(l[0] == r[0]){
        result = min(result, solve(0, l[0] - '0', 3));
    }
    else{
        result = min(result, solve(0, l[0] - '0', 1));
        result = min(result, solve(0, r[0] - '0', 2));
    }

    for(int i = l[0] - '0' + 1;i < r[0] - '0';i++){
        result = min(result, solve(0, i, 0));
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}