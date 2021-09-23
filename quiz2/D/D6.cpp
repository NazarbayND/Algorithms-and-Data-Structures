#include <iostream>
#include <vector>
#include <climits>
#define ll long long

using namespace std;

ll t[4000000], marked[4000000];

void push(int v,int l,int r) {
    if (marked[v]) {
        int m = (l+r) / 2;
        t[v*2] =  t[v] / (m-l + 1);
        t[v*2+1] = t[v] / (r-m);
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
        int tm = (tl + tr) / 2;
        push(v, tl, tr);
        update(v*2, tl, tm, l, min(r, tm), new_val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
        t[v] = t[v*2] + t[v*2 + 1];
    }
}

int get(int v, int tl, int tr, int l, int r) {
    if(l> tr || tl >r ) return 0;
    if(l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) / 2;
    push(v, tl ,tr);
    return get(v*2, tl, tm, l, min(r, tm)) + get(v*2+1, tm+1, tr, max(l, tm+1), r);
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
            cout << get(1, 1, n, l, r) <<" ";
        }
    }
   
    // for(int i = 0; i < 16; i++){
    //     cout<<t[i]<<" ";
    // }


    return 0;
}