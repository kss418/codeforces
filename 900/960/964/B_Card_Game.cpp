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
ll a[2], b[2];

int cal(int a, int b){
    if(a > b) return 1;
    else if(a == b) return 0;
    return -1;
}

void run(){
    cin >> a[0] >> a[1] >> b[0] >> b[1];

    ll result = 0;
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++){
            ll cnt = cal(a[i], b[j]);
            cnt += cal(a[i ^ 1], b[j ^ 1]); 
            result += (cnt > 0);
        }
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}