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

void run(){
    cin >> n >> m; ll result = 0;
    if(n % 2 && m % 2){
        n -= m; result++; m--;
        result += n / m + (n % m ? 1 : 0);
    }
    else if(n % 2){
        n -= m - 1; result++;
        result += n / m + (n % m ? 1 : 0);
    }
    else if(m % 2){
        result += n / (m - 1) + (n % (m - 1) ? 1 : 0);
    }
    else{
        result = n / m + (n % m ? 1 : 0);
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
 
