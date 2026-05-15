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
ll a[MAX];
vector <ll> arr;

void run(){
    cin >> n >> m; arr.clear();
    for(int i = 1;i <= n;i++) cin >> a[i], arr.push_back(a[i]);
    sort(all(arr)); arr.erase(unique(all(arr)), arr.end());
    ll now = a[m], result = 1;

    for(int i = 0;i < arr.size() - 1;i++){
        if(arr[i] < now) continue;
        ll diff = arr[i + 1] - arr[i];
        if(now < diff) result = 0;
    }

    cout << (result ? "YES" : "NO") << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

