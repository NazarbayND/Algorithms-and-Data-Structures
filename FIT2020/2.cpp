#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<string> a(n);
    vector<string> c;
    for(int i = 0; i < n; i++){
       cin>>a[i];
       for (int j = i - 1; j >= 0; j--){
           if (a[i] == a[j]) {
               bool con = false;
               for (int b = 0; b < c.size(); b++){
                   if(c[b] == a[i]){
                       con = true;
                   }
               }
               if(!con) c.push_back(a[i]);
           }
       }
    }

   
    for(int i = 0; i < c.size(); i++){
       cout<<c[i]<<endl;
    }
    if (c.size() == 0){
        cout<< "Understandable, have a great day"<< endl;
    }
   return 0;
}