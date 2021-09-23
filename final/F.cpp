#include <iostream>
#include <vector>

using namespace std;
int t[400100], a[111100];

void update (int v, int tl, int tr, int l, int r, int add) {
	if (l > r)
		return;
	if (l == tl && tr == r)
		t[v] ^= add;
	else {
		int tm = (tl + tr) / 2;
		update (v*2, tl, tm, l, min(r,tm), add);
		update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
	}
}

int get (int v, int tl, int tr, int pos) {
	if (tl == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	if (pos <= tm)
		return t[v] ^ get (v*2, tl, tm, pos);
	else
		return t[v] ^ get (v*2+1, tm+1, tr, pos);
}
int main(){
    int n, t;
    cin >> n >> t;
    char c;
    int x, y, z;
	for(int i = 0; i < t; i++){
        cin >> c >> x >> y;
        if(c == 'A'){
            if(a[x] > 0)
                update(1, 1, n, x, n, a[x]);
            a[x] = y;
            update(1, 1, n, x, n, a[x]);
        }else {
            z = get(1, 1, n, y);
            if(x == 1)
                cout << z << endl;
            else
                cout << (z ^ get(1, 1, n, x - 1)) << endl;
        }
	}
	return 0;
}
