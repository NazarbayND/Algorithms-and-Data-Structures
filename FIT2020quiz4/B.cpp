#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main() {
    int n;
    string a,b;
    cin>>a;
    for(int i=0; i < a.length() ;i++) {
    	b = b + char(( (26 - (int(a[i]) - 97) - 1) + 97));
    }

    cout<<b;

    return 0;
}
