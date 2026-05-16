#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull; ll n, m, k, t; string s;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAX = 101;


int main() {
  fastio;

  cin >> t;
  while(t--){
    cin >> n >> m >> k;
    if(m > n) swap(n, m);
    ll cnt = 0;
    while(n > m){
      cnt++;
      n -= k; m += k;
    }

    cout << cnt << '\n';
  }


  return 0;
}

 
