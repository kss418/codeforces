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
ll arr[MAX];
char st[5] = {'a', 'e', 'i', 'o', 'u'};

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n;
        ll div = n / 5;
        ll mod = n % 5;
        for(int i = 0;i < mod;i++){
            for(int j = 1;j <= div + 1;j++) cout << st[i];
        }

        for(int i = mod;i < 5;i++){
            for(int j = 1;j <= div;j++) cout << st[i];
        }
        cout << "\n";
    }


    return 0;
}
