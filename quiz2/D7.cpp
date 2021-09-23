#include <iostream>
#include <vector>
#include <climits>
#define ll long long

using namespace std;
vector<ll> t;
vector<bool> marked;

void push(int v) {
    if (marked[v]) {
        t[v * 2] = t[ v * 2 + 1] = t[v] / 2;
        marked[v*2] = marked[v*2+1] = true;
        marked[v] = false;
    }
}

void update(int v, int tl, int tr, int l, int r, int new_val) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] = new_val * 1ll * (r - l + 1);
        marked[v] = true;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), new_val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
        t[v] = t[v*2] + t[v*2 + 1];
    }
}

ll get(int v, int tl, int tr, int l, int r) {
    if(l > tr || tl > r ) return 0;
    if(l <= tl && tr <= r) return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return get(v*2, tl, tm, l, min(r, tm)) + get(v*2+1, tm+1, tr, max(l, tm+1), r);
}


int main() {
    int n,m;
    cin>>n>>m;

    int size = 1;
    while (size < n) size *= 2;
    t.assign(2 * size, 0);
    marked.assign(2 * size, false);

    for (int i = 1; i <= m; i++) {
        string req;
        cin >> req;

        if(req == "A"){
            int l, r, x;
            cin>>l>>r>>x;
            update(1, 1, size, l, r, x);
        }

        if(req == "Q"){
            int l,r;
            cin>>l>>r;
            cout << get(1, 1, size, l, r)<< " ";
        }
    }
  

    return 0;
}