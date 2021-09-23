#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
 vector<int> a;

void recursion(int l, int r){
    if(l > r)
        return;
    int m = (l+r) / 2;
    cout<<a[m]<<" ";
    recursion(l, m-1);
    recursion(m +1, r);
  
};

int main() {
    int N;
    cin>>N;
    for (int i = 0; i < pow(2 ,N) - 1; i++){
        int data;
        cin>>data;
        a.push_back(data);
    }
    sort(a.begin(), a.end());
    recursion(0, a.size() - 1);

    return 0;
}