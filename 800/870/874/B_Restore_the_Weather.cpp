#include <bits/stdc++.h>
#define fastio 	cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAX = 101010;
pll arr[MAX]; ll num[MAX], result[MAX];


int main() {
	fastio;

    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n;i++) cin >> arr[i].first;
        for(int i = 1; i <= n;i++) arr[i].second = i;
        for(int i = 1; i <= n;i++) cin >> num[i];

        sort(arr + 1, arr + n + 1);
        sort(num + 1, num + n + 1);
        for(int i = 1;i <= n;i++) result[arr[i].second] = num[i];
        for(int i = 1;i <= n;i++) cout << result[i] << " ";
        cout << "\n";
    }



	return 0;
}
