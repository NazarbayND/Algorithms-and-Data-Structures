#include <bits/stdc++.h>

using namespace std;

struct Node{
	int val;
	Node * left, * right;
	Node(int x){
		val = x;
		left = right = NULL;
	}
};

int n, a[111111], k;
long long t[444444], add[444444];
void build (int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		t[v] = a[tl];
        add[v] = -1;
    }
	else {
		int tm = (tl + tr) / 2;
		build (v*2, tl, tm);
		build (v*2+1, tm+1, tr);
		t[v] = t[v*2] + t[v*2+1];
	}
}
void push(int v, int tl, int tr) {
    if (add[v] != -1) {
        int tm = (tl + tr) >> 1;
        add[v+v] = add[v];
        add[v+v+1] = add[v];
        t[v+v] = (tm - tl + 1) * add[v];
        t[v+v+1] = (tr - tm) * add[v];
        add[v] = -1;
    }
}
void upd(int l, int r, int x, int v = 1, int tl = 1, int tr = n) {
    if (l > tr || tl > r) return;
    if (l <= tl && tr <= r) {
        t[v] = (tr - tl + 1) *1ll* x;
        add[v] = x;
        return;
    }  
    push(v, tl, tr);
    int tm = (tl+tr) >> 1;
    upd(l, r, x, v+v, tl, tm);
    upd(l, r, x, v+v+1, tm+1, tr);
    t[v] = t[v+v] + t[v+v+1];
}
long long getsum(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > tr || tl > r)
		return 0;
	if (l <= tl && tr <= r)
		return t[v];
    push(v, tl, tr);
	int tm = (tl + tr) / 2;
	return getsum(l, r, v+v, tl, tm) + getsum(l, r, v+v+1, tm+1, tr);
}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    cin >> n >> k;
    build();

    while (k--) {
        char ch;
        int l, r, x;
        cin >> ch >> l >> r;
        if (ch == 'Q') {
            cout << getsum(l, r) << endl;
        } else {
            cin >> x;
            upd(l, r, x);
        }
    }
	return 0;
}