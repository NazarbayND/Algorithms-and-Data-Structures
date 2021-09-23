#include <iostream>
#include <vector>
#include <climits>

using namespace std;


int tree[4000000], a[1000000];

void build(int x, int lx, int rx) {
    if (rx == lx) {
       tree[x] = a[lx];
       return;
    } 
    int m = (lx + rx) / 2;
    build( 2 * x, 1, m);
    build( 2 * x + 1, m + 1, rx);
    tree[x] = min(tree[2 * x], tree[2 * x + 1]);
    cout<< tree[x];
}

int mini(int l, int r, int x, int lx, int rx) {
    if (l > rx || lx > r)
        return INT_MAX;
    if (lx >= l && rx <= r)
        return tree[x];
    int m = (lx + rx) / 2;
    return min( mini(l, r, 2 * x , lx, m),  mini(l, r, 2 * x + 1, m + 1, rx));
}



int main() {
    
    int n, m;
    cin >> n >> m; 
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    build(1 , 1 , n);
    long long sum = 0;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        sum += mini(l, r, 1, 1, n);
    }

    cout << sum;
    return 0;
}


