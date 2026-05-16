#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull; ll n, m, k, t; string s;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAX = 10101010;


ll gcd(ll a, ll b){
  ll tmp;
  while(b){
    tmp = a % b;
    a = b;
    b = tmp;
  }

  return a;
}

int main() {
  fastio;

  cin >> t;

  while(t--){
    cin >> n >> m >> k;
    ll pl = n / m, mi = n / k, z = n / (m * k / gcd(m, k));
    ll result = 0;
    result += n * (n + 1) / 2 - (n - pl + z) * (n - pl + z + 1) / 2;
    result -= (mi - z) * (mi - z + 1) / 2;


    cout << result << "\n";
  }


  return 0;
}

 
