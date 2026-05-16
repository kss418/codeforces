#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
ll arr[MAX], cnt[MAX];

int main()
{
    fastio;

    cin >> t;
    while (t--) {
        cin >> n;
        ll result = n / 4;
        result += (n % 4 == 2);

        cout << result << "\n";
    }


    return 0;
}
