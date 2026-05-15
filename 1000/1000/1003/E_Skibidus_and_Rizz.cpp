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
string result;
ll cnt, mx;
void rp(ll num){
    cnt += (num ? 1 : -1); mx = max(mx, abs(cnt));
    result.push_back(num + '0');
    (num ? m : n)--;
}

void run(){
    cin >> n >> m >> k; result.clear();
    cnt = 0, mx = 0;

    while(m || n){
        if(m && n){
            if(result.empty()) rp(m > n ? 1 : 0);
            else if(mx < k) rp(result.back() - '0');
            else rp((result.back() - '0') ^ 1);
        }
        else if(n) rp(0);
        else rp(1);
    }

    cout << (mx == k ? result : "-1") << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}
