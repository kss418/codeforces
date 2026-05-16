#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX];
vector <ll> odd, even;

int main() {
    fastio;

    cin >> t;
    while (t--) {
        cin >> n;

        odd.clear(); even.clear();
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            if (arr[i] % 2) odd.push_back(arr[i]);
            else even.push_back(arr[i]);
        }

        ll result = 0;
        if (even.empty() || odd.empty()) { cout << result << "\n"; continue; }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());

        ll la = odd.back();
        for (int i = 0; i < even.size(); i++) {
            if (even[i] < la) {
                la += even[i], result++;

                continue;
            }

            while (even[i] > la) {
                la += even[i];
                la = min(INF, la);
                result++;
            }
            la = min(INF, la);
            la += even[i]; result++;
        }

        cout << min<ll>(result, even.size() + 1) << "\n";
    }



    return 0;
}
