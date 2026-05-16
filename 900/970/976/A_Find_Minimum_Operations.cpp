#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m;
        ll cur = 1, result = 0;
        if(m == 1) {
            cout << n << "\n";
            continue;
        }
        while(n >= cur) cur *= m;

        while(n){
            while(cur > n) cur /= m;
            ll div = n / cur;
            n -= div * cur;
            result += div;
        }

        cout << result << "\n";
    }


    return 0;
}
