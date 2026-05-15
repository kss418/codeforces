#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> va, vb;

void run(){
    string a, b; cin >> a >> b;
    va.clear(); vb.clear();

    ll cnt = 0;
    for(auto& i : a){
        if(i == 'L' && cnt > 0) va.push_back(cnt), cnt = 0;
        if(i == 'R' && cnt < 0) va.push_back(-cnt), cnt = 0;
        cnt += (i == 'L' ? -1 : 1);
    }
    va.push_back(abs(cnt));

    cnt = 0;
    for(auto& i : b){
        if(i == 'L' && cnt > 0) vb.push_back(cnt), cnt = 0;
        if(i == 'R' && cnt < 0) vb.push_back(-cnt), cnt = 0;
        cnt += (i == 'L' ? -1 : 1);
    }
    vb.push_back(abs(cnt));

    if(va.size() != vb.size() || a[0] != b[0]){ cout << "NO\n"; return; }
    for(int i = 0;i < va.size();i++){
        if(va[i] > vb[i] || 2 * va[i] < vb[i]){
            cout << "NO\n"; return;
        }
    }

    cout << "YES\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}