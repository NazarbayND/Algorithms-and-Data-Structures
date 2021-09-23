#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
    vector<int> a;


int find_lower(int x) {
    int l = -1;
    int r = a.size();
    while (l +1 <= r) {
        int m = (l + r) / 2;
        if (a[m] < x)
            l = m;
        else
            r = m;        
    }
    return l;
}

int find_upper(int x) {
    int l = -1;
    int r = a.size();
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (a[m] >= x)
            r = m;
        else
            l = m;    
    }
    return r;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
      
        cin >> a[i];
       
    }
       
    sort(a.begin(), a.end());
    vector<int> sum(m);
    for (int i = 0; i < m; i++){
        int l1, r1, l2, r2;
        cin>>l1>>r1>>l2>>r2;
        cout<<find_lower(min(r1, r2)) << find_upper(min(l1, l2)) << find_lower(max(r1,r2)) << find_upper(max(l1, l2));
        sum[i] = find_lower(min(r1, r2)) - find_upper(min(l1, l2)) + find_lower(max(r1,r2)) - find_upper(max(l1, l2));
    }
    for (int i = 0; i < m; i++){
        cout<<sum[i]<<" ";
    }
    return 0;
}