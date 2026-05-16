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
vector <char> result;

void run(){
    cin >> n; result.clear();
    for(int i = 1;i <= n;i++) cin >> a[i];

    ll l = 1, r = n, flag = 0;
    while(l <= r){
        if(flag){
            if(a[l] > a[r]) result.push_back('L'), l++;
            else result.push_back('R'), r--;
        }
        else{
            if(a[l] > a[r]) result.push_back('R'), r--;
            else result.push_back('L'), l++;
        }

        flag ^= 1;
    }

    for(auto& i : result) cout << i;
    cout << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
