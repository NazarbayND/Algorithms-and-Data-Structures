#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, b;
    cin>>n>>a>>b;
    string str;
    cin>>str;
    int sumA = 0, sumB = 0;

    for(int i = 0; i < n; i++){
       if(islower( str[i])){
           sumB += b;
       }
       else {
           sumA += a;
       }
    }
    cout<<min(sumA, sumB)<<endl;
    return 0;
}