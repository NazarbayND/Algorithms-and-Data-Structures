#include <iostream>
#include <vector>

using namespace std;

/*void primefactor(int n){
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
}*/

void recpf(int n, int q){
    if (n==1){
        n=1;
    }
    else if (n%q==0){
        cout<<q<<" ";
        n=n/q;
        recpf(n,q);
    }
    else{
        q+=1;
        recpf(n,q);
    }
}


int main() {
    int n;
    cin>>n;
    int q=2;
    //primefactor(n);
   recpf(n,q);
   return 0;
}