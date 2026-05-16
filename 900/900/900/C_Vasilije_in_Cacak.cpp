#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull; ll n, m, k, t; string s;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAX = 2010;


int main() {
  fastio;

  cin >> t;
  while(t--){
    cin >> n >> m >> k;
    ll cur = k;
    ll cnt = 0;


    if(m * (m + 1) / 2 > k) {
      cout << "NO\n";
      continue;
    }

    if(n * (n + 1) / 2 - (n - m) * (n - m + 1) / 2 < k) {
      cout << "NO\n";
      continue;
 }

    else cout << "YES\n";
  }

  return 0;
}
