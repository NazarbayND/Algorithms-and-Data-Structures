#include <iostream>
#include <vector>

using namespace std;

void primefactor(int n){
    int k=n;
    for(int i=2;i<=n;i++){
        if (k%i==0){
            k=k/i;
            cout<<i<<" ";
            i=1;
        }
        if(k==1){
            break;
        }
    }
}



int main() {
    int n;
    cin>>n;
    int q=2;
    primefactor(n);

   return 0;
}