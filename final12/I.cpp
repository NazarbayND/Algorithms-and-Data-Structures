#include <iostream>
#include <vector>

using namespace std;


int main() {
    string s, t;
    cin >> s >> t;
    int sn = s.size();
    int tn = t.size();
    string res;
    int i = 0, j = 0;
    while(i < sn || j < tn){
        if(i < sn){
            res += s[i];
            if( j < tn){
                if(s[i] != t[j]){
                    j = 0;
                }
                else j++;
            }
            i++;
        }
        else if(j < tn){
            res += t[j];
            j++;
        }
    }
    cout<<res<<endl;
    return 0;
}
