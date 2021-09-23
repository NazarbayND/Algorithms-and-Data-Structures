#include <iostream>
#include <vector>
#include <string>

using namespace std;

int re(int n){
  int r1 = 0;
  int r;
  while(n) {
    r = n%10;
    n /= 10;

    r1*=10;
    r1+=r;
  }
  return r1;
}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int a, b, sum;
        cin >> a >> b;
        sum = re(a) + re(b);
        cout << re(sum) << endl;
    }
  return 0;
}