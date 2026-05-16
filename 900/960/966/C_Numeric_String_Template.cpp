#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
ll arr[MAX];
map <ll, ll> use;
map <char, ll> cu;
map <ll, char> cn;


int main()
{
    fastio;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];
        cin >> m;

        while (m--) {
            use.clear(); cn.clear(); cu.clear();
            cin >> s;
            ll result = 1;
            if (s.size() != n) result = 0;
            if (!result) {
                cout << "NO\n";
                continue;
            }

            for (int i = 0; i < n; i++) {
                if (use[arr[i]]) continue;
                if (cu[s[i]]) continue;
                use[arr[i]] = 1;
                cu[s[i]] = 1;
                cn[arr[i]] = s[i];
            }

            for (int i = 0; i < s.size(); i++) {
                if (cn[arr[i]] == s[i]) continue;
                result = 0; break;
            }


            if (result) cout << "YES\n";
            else cout << "NO\n";
        }
    }


    return 0;
}
