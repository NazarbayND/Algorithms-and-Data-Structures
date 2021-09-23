#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int tree[4000000], a[1000000];

int set(int i, int l, int r, int tl, int tr){
    if( l > tr) return 0;
    if( r < tl) return 0;
    if ( l == r ) {
        tree[i] = a[l];
        return tree[i];
    }
    int m = ( l + r ) / 2;
    tree[i] = set(i * 2, l, m, tl, tr) + set(i * 2 +1, m+1, r, tl, tr);
    return tree[i];
}

int getsum(int i, int tl, int tr, int l, int r){
    if(tree[i] == 0) return 0;
    if(l> tr || tl >r ) return 0;
    if(l <= tl && tr <= r) return tree[i];
    int m = (tl + tr) / 2;
    return getsum(i * 2, tl, m, l, r) + getsum(i*2+1, m+1, tr, l, r);
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
            for(int j = l; j <= r; j++){
                cin>>a[j];
            }
            cout<< "req A"<<" ";
        }

        if(req == "Q"){
            int l,r;
            cin>>l>>r;
            cout<< "req B"<<" ";
            // cout << set(1, 1, n, l, r);
        }
    }

    return 0;
}