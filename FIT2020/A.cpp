#include <iostream>
#include <vector>

using namespace std;

void primenext(int n){
    int i=1;
    while (true){
        int k=0;
        for(int j = 1; j<=i;j++){
            if(i%j==0){
                k+=1;
            }
        }
        if(k==2){
            n-=1;
        }
        i+=1;
        if(n==0){
            break;
        }
    }
    cout<<i-1<<endl;
}



int main() {
    int n;
    cin>>n;
    primenext(n);
   //recpf(n,q);
   return 0;
}