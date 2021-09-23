#include <iostream>
#include <vector>
#include <climits>
#define ll long long

using namespace std;

ll t[4000000];

void push (int v) {
	if (t[v] != -1) {
		t[v*2] = t[v*2+1] = t[v];
		t[v] = -1;
	}
}
 
void update (int v, int tl, int tr, int l, int r, int x) {
	if (l > r)
		return;
	if (l == tl && tr == r)
		t[v] = x;
	else {
		push (v);
		int tm = (tl + tr) / 2;
		update (v*2, tl, tm, l, min(r,tm), x);
		update (v*2+1, tm+1, tr, max(l,tm+1), r, x);
        t[v] = t[v*2] + t[v*2 + 1];
	}
}
 
int get (int v, int tl, int tr, int l, int r) {
    if(t[v] == 0) return 0;
	if (tl == tr)
		return t[v];
	push (v);
	int tm = (tl + tr) / 2;
    else return get (v*2, tl, min(r, tm), l, r) + get (v*2+1, tm+1, tr, l, r);
}


int main() {
    int n,m;
    cin>>n>>m;

    for (int i = 1; i <= m; ++i) {
        string req;
        cin >> req;

        if(req == "A"){
            int l, r, x;
            cin>>l>>r>>x;
            update(1, 1, n, l, r, x);
        }

        if(req == "Q"){
            int l,r;
            cin>>l>>r;
            // cout << get(1, 1, n, l, r) <<" ";
        }
    }
   
    for(int i = 0; i < 16; i++){
        cout<<t[i]<<" ";
    }


    return 0;
}