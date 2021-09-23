#include <iostream>
#include <vector>

#define ll long long 

using namespace std;

ll p_pow[2000];

void init_p(int n) {
    ll p = 31;
    p_pow[0] = 1;
    for (int i = 1; i <= n; i++)
        p_pow[i] = p_pow[i - 1] * p;
}

int hash_(string s) {
    vector<ll> h(s.size());
    int res = 1;
    h[0] = s[0];

    for (int i = 1; i < s.size(); i++){
        h[i] = h[i - 1] + s[i] * p_pow[i];
        for (int j = i - 1; j >= 0; j--){
            if(h[i] % h[j] == 0){
                res--;
            }
        }
        res += i + 1; 
    }
    return res;
}

int main() {
    string s;
    cin>>s;
    init_p(s.size());
    cout<<hash_(s)<<endl;
    

    return 0;
}