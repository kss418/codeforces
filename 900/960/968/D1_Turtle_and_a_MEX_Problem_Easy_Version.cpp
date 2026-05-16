#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
vector <ll> arr[MAX];

int main() {
    fastio;
    cin >> t;
    while (t--) {

        cin >> n >> m;
        ll mx = 0;
        for (int i = 0; i < n; i++) {
            arr[i].clear();
            cin >> k;
            for (int j = 1;j <= k; j++) {
                ll num;
                cin >> num;
                arr[i].push_back(num);
            }
            sort(arr[i].begin(), arr[i].end());
        }

        for (int i = 0; i < n; i++) {
            ll fi = -1, se = -1;
            if (arr[i][0] == 1) fi = 0;
            else if(arr[i][0] >= 2) fi = 0, se = 1;

            for (int j = 1; j < arr[i].size(); j++) {
                if (fi != -1 && se != -1) break;
                if (arr[i][j] - arr[i][j - 1] <= 1) continue;
                if (arr[i][j] - arr[i][j - 1] == 2) {
                    if (fi == -1) fi = arr[i][j - 1] + 1;
                    else {
                        se = arr[i][j - 1] + 1;
                        break;
                    }
                    continue;
                }

                if (fi == -1) {
                    fi = arr[i][j - 1] + 1;
                    se = fi + 1;
                }
                else se = arr[i][j - 1] + 1;
                break;
            }

            if (fi == -1) {
                fi = arr[i].back() + 1;
                se = fi + 1;
            }
            else if (se == -1) se = arr[i].back() + 1;
            mx = max(se, mx);
        }

        ll mn = min(mx, m);
        ll result = mx * (mn + 1);
        ll sf = (mn + 1) * mn / 2;
        ll se = (m + 1) * m / 2;
        cout << result - sf + se << "\n";
    }

    return 0;
}
