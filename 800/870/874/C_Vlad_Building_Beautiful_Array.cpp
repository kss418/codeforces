#include <bits/stdc++.h>
#define fastio 	cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAX = 201010;
ll arr[MAX];


int main() {
	fastio;

    cin >> t;
    while(t--){
        cin >> n;
        ll odd = 0;
        for(int i = 1; i <= n;i++) {
            cin >> arr[i];
            if(arr[i] % 2) odd = 1;
        }

        sort(arr + 1, arr + n + 1);
        if(arr[1] % 2) cout << "YES" << "\n";
        else{
            if(odd) cout <<"NO" << "\n";
            else cout << "YES" << "\n";
        }
    }



	return 0;
}
