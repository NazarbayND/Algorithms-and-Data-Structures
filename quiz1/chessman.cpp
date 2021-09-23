#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int finder (vector<int> arr,  int num){
    int l = -1;
    int r = arr.size();
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (arr[m] == num)
            return num;
        if (arr[m] < num)
            l = m;
        else
            r = m;        
    }
    return arr[r];  
}

int main() {
    int N,Q;
    cin>>N;
    cin>>Q;
    vector<int> arr1(N);
    vector<int> arr2(Q);
    for (int i=0; i < N; i++){
        cin>>arr1[i];
    }

    for (int i=0; i < Q; i++){
        cin>>arr2[i];   
    }
    
    sort(arr1.begin(), arr1.end());


    for (int j=0; j < Q; j++){
        int num = arr2[j];
        int ans = finder(arr1, num);
        cout<<ans<<endl;
    }

    return 0;
}