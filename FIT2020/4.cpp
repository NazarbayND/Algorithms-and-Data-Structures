#include <iostream>
#include <vector>


using namespace std;

bool check(string a, string b){
    if(a.size() != b.size()){
        return false;
    }
    for(int i = 0; i < a.size(); i++){
       if(tolower(a[i]) == 'i' || tolower(a[i]) == 'e'){
           if( tolower(b[i]) == 'i' || tolower(b[i]) == 'e') {
               continue;
           }
           else return false;
       }
       if(tolower(a[i]) == 'b' || tolower(a[i]) == 'p'){
           if( tolower(b[i]) == 'b' || tolower(b[i]) == 'p') {
               continue;
           }
           else return false;
       }
       else {
           if( tolower(a[i]) != tolower(b[i])) return false;
       }
    }
    return true;

}   

int main() {
    int n;
    cin>>n;
    
    for(int i = 0; i < n; i++){
        string a,b;
        cin>>a>>b;
        if(check(a,b)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    
   return 0;
}