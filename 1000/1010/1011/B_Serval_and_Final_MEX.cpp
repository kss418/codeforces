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
constexpr ll MAX = 5010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> arr;
vector <pll> result;

void run(){
    cin >> n; arr.clear(); result.clear();
    for(int i = 1;i <= n;i++) cin >> m, arr.push_back(m);

    ll mi = 0;
    for(int i = 1;i <= n;i++){
        ll flag = 0;
        for(int j = 0;j < arr.size() - 1;j++){
            if(arr[j]) continue;
            result.push_back({j + 1, j + 2});
            arr.erase(arr.begin() + j);
            arr.erase(arr.begin() + j);
            arr.insert(arr.begin() + j, 1);
            flag = 1; break;
        }

        if(flag || arr.back()) continue;
        result.push_back({arr.size() - 1, arr.size()});
        arr.pop_back(); arr.pop_back();
        arr.push_back(1);
    }
    if(arr.size() > 1) result.push_back({1, arr.size()});

    cout << result.size() << "\n";
    for(auto[l, r] : result) cout << l << " " << r << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
