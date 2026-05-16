#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull; ll n, m, k, t; string s;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAX = 201010;
ll arr[MAX];


int main() {
  fastio;

  cin >> t;
  while(t--){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    ll fi = arr[1], la = arr[n];
    ll st = 1, en = n, result = INF;
    while(st <= en){
      ll cur = max({arr[st] - fi, la - arr[en], arr[en - 1] - arr[st + 1]});
      result = min(result, cur / 2 + cur % 2);

      if(la - arr[en - 1] > arr[st + 1] - fi) st++;
      else en--;
    }

    cout << result << "\n";
  }


  return 0;
}
