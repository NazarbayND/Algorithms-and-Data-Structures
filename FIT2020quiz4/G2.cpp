#include <iostream>

using namespace std;

int main() {
    int n, a, b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    int A = 0, B = 0;

    for(int i = 0; i < n; i++){
       if(isupper( s[i]))
           A += a;
       else 
           B += b;
       
    }
    cout<<min(A,B)<<endl;
    return 0;
}