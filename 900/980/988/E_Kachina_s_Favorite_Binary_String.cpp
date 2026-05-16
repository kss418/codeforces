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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

ll query(ll a, ll b){
    cout << "? " << a << " " << b << endl;
    ll ret; cin >> ret;
    return ret;
}

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n;
        ll flag = 0, pre = 0, able = 1;
        ll one = 0, zero = 0, cnt = 0;

        vector <char> result;
        for(int i = 2;i <= n;i++){
            ll q = query(1, i);

            if(!flag && q != pre){
                flag = 1;
                for(int j = 1;j <= i - q - 1;j++) result.push_back('1');
                for(int j = 1;j <= q;j++) result.push_back('0');
                result.push_back('1');
                one += i - q - 1; cnt = q;
                zero += q;
            }
            else if(q != pre && flag){
                result.push_back('1'); one++;
                cnt += zero;
                if(q != cnt) able = 0;
            }
            else if(q == pre && flag){
                result.push_back('0'); zero++;
                if(q != cnt) able = 0;
            }

            pre = q;
        }

        if(!able || !pre) cout << "! IMPOSSIBLE" << endl;
        else {
            cout << "! ";
            for(auto& i : result) cout << i;
            cout << endl;
        }
    }


    return 0;
}
