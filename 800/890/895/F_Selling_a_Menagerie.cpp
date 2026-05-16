#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull; ll n, m, k, t; string s;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAX = 101010;
ll a[MAX], c[MAX], mi[MAX], result[MAX], ans, pl[MAX], sell[MAX];
multiset <pll> arr;


int main() {
  fastio;

  cin >> t;
  while(t--){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> c[i];
    memset(mi, 0, sizeof(mi));
    memset(sell, 0, sizeof(sell));

    for(int i = 1;i <= n;i++) pl[a[i]] += c[i];
    for(int i = 1;i <= n;i++) arr.insert({pl[i], i});

    ll cnt = 0;


    while(!arr.empty()){
      pll cur = *arr.begin();
      arr.erase(arr.begin());
      ll v = cur.first;
      ll idx = cur.second;

      if(sell[idx]) continue;
      sell[idx] = 1;

      pl[a[idx]] -= c[idx];
      arr.insert({pl[a[idx]], a[idx]});
      result[++cnt] = idx;
    }

    for(int i = 1;i <= n;i++) cout << result[i] << " ";
    cout << "\n";
  }


  return 0;
}

 
