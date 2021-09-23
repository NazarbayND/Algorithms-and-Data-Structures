#include <iostream>
#include <vector>
#include <climits>
#define ll long long

using namespace std;


int tree[4000000];

void set(int i, int l, int r, int lx, int rx, int x){
    if ( l == r ) {
        tree[i] = x;
        return;
    }
    int m = ( l + r ) / 2;
    if (lx > m){
        set(i * 2 +1, m + 1, r, lx, rx, x);
    }
    else if (rx <= m){
        set(i * 2, l, m, lx, rx, x);
    }
    else {
        set(i * 2, l, m, lx, rx, x);
        set(i * 2 +1, m + 1, r, lx, rx, x);
    }
    tree[i] = tree[i * 2] + tree[i*2 + 1];
}

ll getsum(int i, int tl, int tr, int l, int r){
    if(tree[i] == 0) return 0;
    if(l > tr || tl > r ) return 0;
    if(l <= tl && tr <= r) return tree[i];
    int m = (tl + tr) / 2;
    return getsum(i * 2, tl, m, l, r) + getsum(i*2+1, m+1, tr, l, r);
}

void print () {
     for(int i = 0; i < 16; i++){
         cout<<tree[i]<<" ";
    }
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
            set(1,1,n,l,r,x);
        }

        if(req == "Q"){
           int l,r;
           cin>>l>>r;
            cout << getsum(1, 1, n, l, r)<< " ";
        }
    }
    cout<<endl;

    // print();
   
    return 0;
}