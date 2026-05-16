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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
vector <ll> arr;

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        arr.clear();
        for(int i = 1;i <= m;i++) {
            ll num; cin >> num;
            arr.push_back(num);
        }
        sort(all(arr));

        while(k--){
            ll num; cin >> num;
            if(num < arr[0]) cout << arr[0] - 1 << "\n";
            else if(num > arr[m - 1]) cout << n - arr[m - 1] << "\n";
            else{
                auto lb = lower_bound(all(arr), num);
                if(*lb == num) cout << 0 << "\n";
                else{
                    ll nxt = *lb, pre = *--lb;
                    ll diff = (nxt - pre) >> 1;
                    cout << diff << '\n';
                }
            }
        }
    }


    return 0;
}
