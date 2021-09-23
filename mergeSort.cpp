#include <iostream>

using namespace std;
int a[100000];
int n;

void merge(int l, int m, int r) {
    int k1 = l;
    int k2 = m + 1;
    int k = l;
    while(k <= r && k1 <= r && k2 <= r){
        if(a[k1] <= a[k2] && k1 < m + 1){
            k1++;
        }
        if(a[k1] > a[k2] && k1 < m + 1){
            swap(a[k], a[k2]);
            k1 = k2;
            k2++;
        }
        if(a[k1] <= a[k2] && k1 > m + 1){
            swap(a[k], a[k1]);
            if(k == k1){
                k1++;
            }
        }
         if(a[k1] > a[k2] && k1 > m + 1){
           swap(a[k], a[k2]);
           k2++;
        }
        k++;
    }    
}

void mergesort(int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergesort(l, m);
        mergesort(m + 1, r);
        merge(l, m, r);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mergesort(0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}