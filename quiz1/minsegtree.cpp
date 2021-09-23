#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int tree[4000000], a[1000000];

void set(int i, int l, int r){
    if ( l == r ) {
        tree[i] = a[l];
        return;
    }
    int m = ( l + r ) / 2;
    set(i * 2, l, m);
    set(i * 2 +1, m+1, r);
    tree[i] = min(tree[i*2], tree[i*2 +1]);
}

int getmin(int i, int tl, int tr, int l, int r){
    if(l> tr || tl >r ) return INT_MAX;
    if(l <= tl && tr <= r) return tree[i];
    int m = (tl+tr) / 2;
    return min(getmin(i * 2, tl, m, l, r), getmin(i*2+1, m+1, tr, l, r));
}

int main() {
    int n,m;
    cin>>n>>m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    set(1, 1, n);
    long long sum = 0;
    for (int i = 1; i <= m; ++i){
        int l, r;
        cin>>l>>r;
        sum += getmin(1, 1, n, l, r);
    }
    cout<<sum<<endl;

    return 0;
}