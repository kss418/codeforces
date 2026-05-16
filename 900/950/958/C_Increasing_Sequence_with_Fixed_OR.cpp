#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010;
vector <ll> result;

int main()
{
    fastio;
    cin >> t;
    while (t--) {
        cin >> n;
        ll st = n;
        result.clear();

        while (n) {
            result.push_back(n);
            ll cur = n; ll rev = 0;
            for (ll i = 1; i <= n; i <<= 1) if (!(n & i) && (st & i)) rev |= i;
            while ((n | rev) >= cur) {
                ll lsb = n & (~n + 1);
                n -= lsb;
            }

            n |= rev;
            if ((cur | n) != st) break;
        }

        reverse(result.begin(), result.end());
        cout << result.size() << "\n";
        for (auto& i : result) cout << i << " ";
        cout << "\n";
    }


    return 0;
}
