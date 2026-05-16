#include <bits/stdc++.h>
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
ll result;
vector <ll> vec;
vector <ll> arr = {2, 3, 5, 7};

void bt(ll cur){
    if(vec.size() == cur){
        ll mul = 1;
        for(auto& i : vec) mul *= i;

        result += (m / mul - n / mul) * (cur % 2 ? 1 : -1);
        return;
    }

    for(auto& i : arr){
        if(!vec.empty() && i <= vec.back()) continue;
        vec.push_back(i);
        bt(cur);
        vec.pop_back();
    }
}

void run(){
    cin >> n >> m; result = 0; vec.clear(); n--;
    for(int i = 1;i <= 4;i++) bt(i);

    cout << m - n - result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
