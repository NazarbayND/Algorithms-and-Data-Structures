#include <iostream>
#include <vector>
#include <climits>
#define ll long long

using namespace std;

vector <ll> tree;

void set(int l, int r, int v, int x, int lx, int rx) {
        if (rx == lx) {
            tree[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (l > m){
            set(l, r, v, 2 * x + 1, m + 1, rx);
            }
        else if (r <= m){
            set(l, r, v, 2 * x, lx, m);
            }
        else {
            set(l, r, v, 2 * x, lx, m);
            set(l, r, v, 2 * x + 1, m + 1, rx);
        }
        tree[x] = tree[2 * x] + tree[2 * x + 1];
    }

int getsum(int i, int tl, int tr, int l, int r){
    if(tree[i] == 0) return 0;
    if(l > tr || tl > r ) return 0;
    if(l <= tl && tr <= r) return tree[i];
    int m = (tl+tr) / 2;
    return getsum(i * 2, tl, m, l, r) + getsum(i*2+1, m+1, tr, l, r);
}


int main() {
    int n,m;
    cin>>n>>m;

    int size = 1;
    while (size < n) size *= 2;
    tree.assign(2 * size, 0);

    for (int i = 1; i <= m; ++i) {
        string req;
        cin >> req;

        if(req == "A"){
            int l, r, x;
            cin>>l>>r>>x;
            set(l, r, x, 1, 1, size);
        }

        if(req == "Q"){
           int l,r;
           cin>>l>>r;
            cout << getsum(1, 1, size, l, r)<< " ";
        }
    }
    // for(int i = 0; i < tree.size(); i++){
    //      cout<<tree[i]<<" ";
    // }

    return 0;
}