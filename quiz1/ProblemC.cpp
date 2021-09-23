#include <iostream>
#include <vector>

using namespace std;

void ans (vector<int> a) {
    for(int i = 0; i<a.size(); i++){
        int k=0;
        for(int j=i; j>-1;j--){
            if(a[i]-a[j]<=3000){
                k+=1;
            }
            else{
                break;
            }
        }
        cout<<k<<endl;
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i=0; i < n; i++ ){
        cin>>a[i];
    }
    
    ans(a);



    return 0;
}