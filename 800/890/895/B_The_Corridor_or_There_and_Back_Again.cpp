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
    cin >> n;
    ll result = INF;
    while(n--){
      cin >> m >> k;
      result = min(result, m + (k + 1) / 2 - 1);
    }
    cout << result << "\n";
  }


  return 0;
}

 
