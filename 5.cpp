#include <iostream>
#include <vector>

using namespace std;

vector<int> unique_n(int n){
    vector<int> res;
    for(int i = 0 - (n / 2); i <= n / 2; i++){    
        res.push_back(i);
    }
    if(n % 2 == 0){
        res[n-1] -= res[0]; 
    }
    return res;
}

int main() {
    int n;
    cin>>n;
    vector<int> a = unique_n(n);
    for(int i = 0; i < n; i++){
       cout<<a[i] <<" ";
    }
    

    return 0;
}