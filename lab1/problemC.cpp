#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bsmin(vector<int> a, int n){
     int l = -1;
     int r = a.size();
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (a[m] == n)
            return m;
        if (a[m] < n)
            l = m;
        else
            r = m;        
    }
    return r;  
}
int bsmax(vector<int> a, int n){
     int l = -1;
     int r = a.size();
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (a[m] == n)
            return m;
        if (a[m] < n)
            l = m;
        else
            r = m;        
    }
    return l;  
}

int main() {
    int n, m;
    cin>>n>>m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < m; i++){
        int l1, r1, l2, r2, sum;
        cin>>l1>>r1>>l2>>r2;
        sum = bsmax(arr, min(r1, r2)) - bsmin(arr, min(l1, l2)) + bsmax(arr,max(r1,r2)) - bsmin(arr, max(l1, l2)) + 2;
        cout<< sum << endl;
    }


   return 0;
}