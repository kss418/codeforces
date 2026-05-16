#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 1e9 + 7;
ll a[MAX], b[MAX];

struct seg {
    vector <ll> arr, tree;
    seg(ll n) : arr(n), tree(4 * n) {}

    void init() {

    }

    ll con(ll st, ll en, ll node) {
        if (st == en) return tree[node] = arr[st];

        ll mid = (st + en) >> 1;
        return tree[node] = con(st, mid, node * 2) + con(mid + 1, en, node * 2 + 1);
    }

    ll query(ll st, ll en, ll node, ll l, ll r) {
        if (l > en || r < st) return 0;
        if (l <= st && r >= en) return tree[node];

        ll mid = (st + en) >> 1;
        return query(st, mid, node * 2, l, r) + query(mid + 1, en, node * 2 + 1, l, r);
    }

    void plus(ll st, ll en, ll node, ll idx, ll num) {
        if (idx < st || idx > en) return;
        tree[node] += num;
        if (st == en) return;

        ll mid = (st + en) >> 1;
        plus(st, mid, node * 2, idx, num);
        plus(mid + 1, en, node * 2 + 1, idx, num);
    }
};
map<ll, ll> num;

int main() {
    fastio;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];

        num.clear();
        ll flag = 1;
        for (int i = 1; i <= n; i++) num[a[i]] = i;
        for (int i = 1; i <= n; i++) {
            if (!num.count(b[i])) flag = 0;
            b[i] = num[b[i]];
        }

        if (!flag) {
            cout << "NO\n";
            continue;
        }
        seg seg(n);

        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += seg.query(1, n, 1, b[i] + 1, n);
            seg.plus(1, n, 1, b[i], 1);
        }

        if (sum % 2) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}
