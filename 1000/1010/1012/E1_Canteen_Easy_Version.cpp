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
ll a[2 * MAX], b[2 * MAX];
stack <ll> st;

void run(){
    cin >> n >> m; while(!st.empty()) st.pop();
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];
    for(int i = 1;i <= n;i++) a[i] = a[n + i] = a[i] - b[i];

    ll result = 0;
    for(int i = 1;i <= 2 * n;i++) a[i] += a[i - 1];
    for(int i = 2 * n;i >= 1;i--){
        while(!st.empty() && a[st.top()] > a[i]) st.pop();
        if(i <= n) result = max(result, st.top() - i);
        st.push(i);
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
