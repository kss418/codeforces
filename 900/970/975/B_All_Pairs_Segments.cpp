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
constexpr ll MAX = 101010;
constexpr ll MOD = 998244353;
ll arr[MAX], cnt[MAX];
map <ll, ll> result;

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m;
        result.clear();

        for(int i = 1;i <= n;i++) cin >> arr[i];
        for(int i = 1;i <= n;i++){
            cnt[i] = cnt[i - 1];
            cnt[i] += n - i;
            cnt[i] -= max(i - 2, 0);
        }

        for(int i = 1;i <= n;i++) {
            result[cnt[i]]++;
            if(i == 1) continue;
            result[cnt[i] - n + i] += (arr[i] - arr[i - 1] - 1);
        }

        while(m--){
            cin >> k;
            cout << result[k] << " ";
        }
        cout << "\n";
    }

    return 0;
}
