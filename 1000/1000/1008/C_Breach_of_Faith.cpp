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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll b[2 * MAX], result[2 * MAX], sum;
ll pre[2 * MAX];
map <ll, bool> v;

void run(){
    cin >> n; v.clear(); sum = 0;
    for(int i = 1;i <= 2 * n;i++) cin >> b[i], v[b[i]] = 1;
    sort(b + 1, b + 2 * n + 1, greater<ll>());
    for(int i = 1;i <= 2 * n;i += 2){
        sum += b[i] - b[i + 1];
        pre[i] = (i == 1 ? 0 : pre[i - 2]) + b[i];
        pre[i + 1]= pre[i - 1] + b[i + 1];
    }

    if(!v.count(sum)){
        cout << sum << " ";
        for(int i = 1;i <= 2 * n;i++) cout << b[i] << " ";
        cout << "\n"; return;
    }

    for(int i = 1;i <= 2 * n;i++){
        if(i & 1){
            sum = (i != 1 ? pre[i - 2] : 0ll) - pre[i - 1];
            sum += (pre[2 * n] - pre[i - 1]) - (pre[2 * n - 1] - pre[i]);
        }
        else{
            sum = pre[i - 1] - pre[i - 2];
            sum += (pre[2 * n - 1] - pre[i - 1]) - (pre[2 * n] - pre[i]);
        }

        if(sum > b[i]){
            sum -= b[i];
            if(v.count(sum)) continue;
            cout << b[i] << " ";
            for(int j = 1;j <= 2 * n;j++) cout << (i == j ? sum : b[j]) << " ";
            cout << "\n"; return;
        }
        else if(sum < b[i]){
            sum += b[i];
            if(v.count(sum)) continue;
            cout << b[i] << " ";
            for(int j = 1;j <= 2 * n;j++) cout << (i == j ? sum : b[j]) << " ";
            cout << "\n"; return;
        }
    }
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
 
