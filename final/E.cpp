#include <iostream>
#include <vector>

using namespace std;
long long a[100100], n, k;
bool ask(long long x){
    long long sum = 0;
    for(int i = 0; i < n; i++)
        sum += (a[i] + x - 1) / x;
    if(sum <= k)return true;
    return false;
}
int go(int l, int r){
    if(l == r)return l;
    int m = (l + r) / 2;
    if(ask(m))r = m;
    else l = m + 1;
    return go(l, r);
}
signed main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
        cin >> a[i];
	}
	cout << go(1, 1e9);

    return 0;
}
