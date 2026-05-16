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
ll arr[MAX];

int main() {
    fastio;

    cin >> t;
    while(t--){
        ll a = 0, b, c, d;
        cin >> b >> c >> d;

        for(ll i = 0;i < 63;i++){
            ll cur = 1ll << i;
            ll bc = b & cur;
            ll dc = d & cur;

            if(bc != dc) a |= cur;
        }

        if(((a | b) - (a & c)) == d) cout << a << '\n';
        else cout << -1 << "\n";
    }


    return 0;
}
