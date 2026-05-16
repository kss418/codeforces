#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll a[MAX], cnt[MAX];
set <ll> dis;

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m;
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0;i < n;i++) {
            cin >> a[i]; a[i]--;
            ll mn = min<ll>(i, a[i]), mx = max<ll>(i, a[i]);
            cnt[mn]++; cnt[mx]--;
        }
        for(int i = 0;i < n;i++) cnt[i] += cnt[i - 1];
        cin >> s; dis.clear();

        for(int i = 0;i < n - 1;i++){
            if(s[i] == 'L' && s[i + 1] == 'R' && cnt[i]) dis.insert(i);
        }

        while(m--){
            cin >> k; k--;
            if(s[k] == 'L') s[k] = 'R'; else s[k] = 'L';

            if(k && s[k - 1] == 'L' && s[k] == 'R' && cnt[k - 1]) dis.insert(k - 1);
            else if(k && dis.count(k - 1)) dis.erase(k - 1);

            if(k + 1 < n && s[k] == 'L' && s[k + 1] == 'R' && cnt[k]) dis.insert(k);
            else if(k + 1 < n && dis.count(k)) dis.erase(k);

            if(!dis.empty()) cout << "NO\n";
            else cout << "YES\n";
        }
    }


    return 0;
}
