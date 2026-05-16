#include <bits/stdc++.h>
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
constexpr ll MAX = 10101;
constexpr ll MOD = 998244353;
ll p[MAX];


int main() {
    fastio;

    cin >> t;
    while (t--) {
        cin >> n;

        ll num; bool flag;
        for (int i = 2; i < n; i++) {
            cout << "? " << 1 << " " << i << endl;
            cin >> flag;
            if (flag) continue;
            num = i; break;
        }

        for (int i = 2; i < num; i++) p[i] = 0; p[num] = 1;
        ll l = 2;
        for (int r = num + 1; r < n; r++) {
            while(1){
                cout << "? " << l << " " << r << endl;
                cin >> flag; l++;
                if (flag) continue;
                p[r] = l - 1; break;
            }
        }

        cout << "! ";
        for (int i = 1; i < n; i++) cout << p[i] << " ";
        cout << endl;
    }


    return 0;
}
