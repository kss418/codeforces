#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
vector <pll> result;
ll si;

ll f(ll cur, ll num) {
    string st, ret;
    ll cnt = 0;
    st = to_string(cur);

    while (cnt < num) {
        ll mod = cnt % st.size();
        ret.push_back(st[mod]);
        cnt++;
    }

    return stoi(ret);
}

int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n < 10) si = 1;
        else if (n < 100) si = 2;
        else si = 3;

        result.clear();
        for (int dif = 1; dif <= 6; dif++) {
            for (ll cur = 1; cur <= 10000; cur++) {
                ll pre = si * cur - dif;
                if (pre <= 0) continue;
                if(n * cur - pre != f(n, dif)) continue;

                result.push_back({ cur, pre });
            }
        }

        cout <<result.size() << "\n";
        for (auto& i : result) cout << i.first << " " << i.second << "\n";
    }


    return 0;
}
