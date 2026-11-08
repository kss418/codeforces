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
constexpr ll MAX = 44; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX];
pll org[2 * MAX];
vector <pll> result;

void sa(int idx){
    org[a[idx]] = {idx + 1, 0};
    org[a[idx + 1]] = {idx, 0};
    swap(a[idx], a[idx + 1]);
    result.push_back({1, idx});
}

void sb(int idx){
    org[b[idx]] = {idx + 1, 1};
    org[b[idx + 1]] = {idx, 1};
    swap(b[idx], b[idx + 1]);
    result.push_back({2, idx});
}

void su(int idx){
    org[a[idx]] = {idx, 1};
    org[b[idx]] = {idx, 0};
    swap(a[idx], b[idx]);
    result.push_back({3, idx});
}   

void run(){
    cin >> n; result.clear();
    for(int i = 1;i <= n;i++) cin >> a[i], org[a[i]] = {i, 0};
    for(int i = 1;i <= n;i++) cin >> b[i], org[b[i]] = {i, 1};

    for(int i = 1;i <= 2 * n;i++){
        if(i % 2){
            if(org[i].y) su(org[i].x);
            while(org[i].x != (i + 1) / 2) sa(org[i].x - 1);
        }
        else{
            if(!org[i].y) su(org[i].x);
            while(org[i].x != i / 2) sb(org[i].x - 1);
        }
    }

    cout << result.size() << "\n";
    for(auto& [x, y] : result) cout << x << " " << y << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}