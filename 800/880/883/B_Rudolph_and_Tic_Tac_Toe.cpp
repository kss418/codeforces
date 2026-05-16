#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull; ll n, m, k, t; string s;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAX = 201;
string st[4];


int main() {
  fastio;

  cin >> t;
  while(t--){
    for(int i = 1;i <= 3;i++) cin >> st[i];
    if(st[1][0] == st[1][1] && st[1][1] == st[1][2] && st[1][0] != '.') cout << st[1][0] << "\n";
    else if(st[2][0] == st[2][1] && st[2][1] == st[2][2] && st[2][0] != '.') cout << st[2][0] << "\n";
    else if(st[3][0] == st[3][1] && st[3][1] == st[3][2] && st[3][0] != '.') cout << st[3][0] << "\n";
    else if(st[1][0] == st[2][0] && st[2][0] == st[3][0] && st[1][0] != '.') cout << st[1][0] << "\n";
    else if(st[1][1] == st[2][1] && st[2][1] == st[3][1] && st[1][1] != '.') cout << st[1][1] << "\n";
    else if(st[1][2] == st[2][2] && st[2][2] == st[3][2] && st[1][2] != '.') cout << st[1][2] << "\n";
    else if(st[1][0] == st[2][1] && st[2][1] == st[3][2] && st[1][0] != '.') cout << st[1][0] << "\n";
    else if(st[1][2] == st[2][1] && st[2][1] == st[3][0] && st[1][2] != '.') cout << st[1][2] << "\n";
    else cout << "DRAW\n";
  }


  return 0;
}

 
