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
class node{
public:
    vector <ll> arr;
    ll sum = 0;

    void insert(ll num){
        arr.push_back(num);
        sum += num;
    }

    bool operator < (const node& ot) const{
        return sum > ot.sum;
    }
};

void run(){
    cin >> n >> m;
    vector <node> a;
    ll result = 0, sum = 0;
    for(int i = 0;i < n;i++){
        node now;
        for(int j = 0;j < m;j++){
            cin >> k; now.insert(k);
        }
        a.push_back(now);
    }
    sort(all(a));

    for(auto& i : a){
        for(auto& j : i.arr){
            sum += j; result += sum;
        }
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}
