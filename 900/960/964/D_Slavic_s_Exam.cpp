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
string a, b;

void run(){
    cin >> a >> b;
    int idx = 0;
    for(auto& i : a){
        if(idx == b.size()){
            if(i == '?') i = 'a';
        }
        else if(b[idx] == i) idx++;
        else if(i == '?'){
            i = b[idx];
            idx++;
        }
    }

    if(idx == b.size()){
        cout << "YES" << "\n";
        cout << a << "\n";
    }
    else cout << "NO" << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}