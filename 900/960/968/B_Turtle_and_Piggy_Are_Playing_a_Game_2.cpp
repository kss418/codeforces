#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX];
multiset <ll> num;

int main()
{
    fastio;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            num.insert(arr[i]);
        }

        ll cur = 1;
        while (num.size() > 1) {
            if (cur % 2) num.erase(num.begin());
            else num.erase(--num.end());
            cur++;
        }

        cout << *num.begin() << "\n";
        num.clear();
    }

    return 0;
}
