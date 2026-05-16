#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <string>
#include <map>
using namespace std; typedef long long ll;
typedef pair <int, int> pi; typedef pair <ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 201010;
ll arr[MAX], seg[MAX * 4], lazy[MAX * 4];


void prop(int st, int en, int node) {
    if (!lazy[node]) {
        return;
    }

    if (st < en) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    else if (st == en) {
        while (lazy[node]--) {
            ll cur = seg[node];
            ll nxt = 0;
            ll mod = 1e9;
            if (cur < 10) {
                break;
            }

            while (cur) {
                if (cur >= mod) {
                    ll moc = cur / mod;
                    nxt += moc;
                    cur -= moc * mod;
                }
                mod /= 10;
            }
            seg[node] = nxt;
        }
    }
    lazy[node] = 0;
}


void update(int st, int en, int node, int l, int r) {
    prop(st, en, node);

    if (en < l || st > r) {
        return;
    }

    if (st >= l && en <= r) {
        lazy[node]++;
        prop(st, en, node);
        return;
    }

    int mid = (st + en) / 2;
    update(st, mid, node * 2, l, r);
    update(mid + 1, en, node * 2 + 1, l, r);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

ll query(int st, int en, int node, int l, int r) {
    prop(st, en, node);

    if (en < l || st > r) {
        return 0;
    }

    if (st >= l && en <= r) {
        return seg[node];
    }

    int mid = (st + en) / 2;
    return query(st, mid, node * 2, l, r) + query(mid + 1, en, node * 2 + 1, l, r);
}

ll mk_seg(int st, int en, int node) {
    if (st == en) {
        seg[node] = arr[st];
        return seg[node];
    }

    int mid = (st + en) / 2;
    seg[node] = mk_seg(st, mid, node * 2) + mk_seg(mid + 1, en, node * 2 + 1);
    return seg[node];
}

void mk_lazy(int st, int en, int node) {
    if (st == en) {
        lazy[node] = 0;
        return;
    }

    int mid = (st + en) / 2;
    lazy[node] = 0;
    mk_lazy(st, mid, node * 2);
    mk_lazy(mid + 1, en, node * 2 + 1);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        mk_seg(1, n, 1);
        mk_lazy(1, n, 1);

        while (m--) {
            ll com, a, b;
            cin >> com;
            if (com == 1) {
                cin >> a >> b;
                update(1, n, 1, a, b);
            }
            else {
                cin >> a;
                cout << query(1, n, 1, a, a) << "\n";
            }
        }
    }

    return 0;
}
