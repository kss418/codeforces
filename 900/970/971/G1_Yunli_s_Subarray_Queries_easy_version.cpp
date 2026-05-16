#include <bits/stdc++.h>
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
ll a[MAX], result[MAX]; 
multiset <pll> num;
map <ll,ll> cnt;

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        cnt.clear(); num.clear();
        for(int i = 1;i <= n;i++) cin >> a[i], a[i] -= i;
        for(int i = 1;i < m;i++){
            cnt[a[i]]++;
            num.insert({cnt[a[i]], a[i]});
            if(cnt[a[i]] >= 2) num.erase(num.find({cnt[a[i]] - 1, a[i]}));
        }

        for(int i = m;i <= n;i++){
            cnt[a[i]]++;
            num.insert({cnt[a[i]], a[i]});
            if(cnt[a[i]] >= 2) num.erase(num.find({cnt[a[i]] - 1, a[i]}));

            result[i - m + 1] = m - (--num.end())->x;

            cnt[a[i - m + 1]]--;
            num.erase(num.find({cnt[a[i - m + 1]] + 1, a[i - m + 1]}));
            if(cnt[a[i - m + 1]]) num.insert({cnt[a[i - m + 1]], a[i - m + 1]});
        }

        while(k--){
            ll l, r; cin >> l >> r;
            cout << result[l] << "\n";
        }
    }
    
    
    return 0;
}
