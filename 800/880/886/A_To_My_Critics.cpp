#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll; 
typedef pair<int, int> pi; typedef pair<ll, ll> pll; 
typedef unsigned long long ull; ll n, m, k, t; string s;
        
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAX = 1010101;
ll arr[4];

int main() { 
    fastio;
    
    cin >> t;
    while(t--){
        for(int i = 1; i <= 3;i++) cin >> arr[i];
        ll result = 0;
        for(int i = 1;i <= 3;i++){
            for(int j = 1;j <= 3;j++){
                if(i == j) continue;
                ll sum = arr[i] + arr[j];
                if(sum >= 10) result = 1;
            }
        }
        
        if(result) cout << "YES\n";
        else cout << "NO\n";
    }
        
        
    return 0;
}

     
  
  
