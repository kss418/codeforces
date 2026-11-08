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
ll a[MAX], pre[MAX];
map <ll, ll> mp;
bool v[MAX];

void run(){
    cin >> n >> m >> k; mp.clear();
    for(int i = 1;i <= n;i++) cin >> a[i], pre[i] = pre[i - 1] + a[i];
    for(int i = 0;i <= n;i++) v[i] = 0;

    ll idx1 = 0, idx2 = 0, result = 0;
    for(int i = 1;i <= n;i++){
        if(a[i] == k){
            for(int j = max(idx1, idx2);j < i;j++) mp[pre[j]]++, v[j] = 1;
            idx1 = i;
        }
        else if(a[i] > k){
            for(int j = idx2;j < i;j++){
                if(v[j]) mp[pre[j]]--;
                v[j] = 0;
            }
            idx2 = i;
        }

        auto it = mp.find(pre[i] - m);
        if(it != mp.end()) result += it->second;
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}