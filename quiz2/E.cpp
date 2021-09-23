#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll p_pow[100000];

void init_p(int n) {
    ll p = 31;
    p_pow[0] = 1;
    for (int i = 1; i <= n; i++)
        p_pow[i] = p_pow[i - 1] * p;
}



vector<ll> hash_(string s) {
    vector<ll> h(s.size());
    h[0] = s[0];
    for (int i = 1; i < s.size(); i++)
        h[i] = h[i - 1] + s[i] * p_pow[i];
    return h;
}

ll hash_string(string s) {
    ll sum = 0;
    for (int i = 0; i < s.size(); i++)
        sum += s[i] * p_pow[i];
    return sum;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> var(n);
    init_p(s.size());
    vector<ll> h = hash_(s);
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        string sub;
        cin>>sub;
        int size = sub.size();
        ll hash_sub = hash_string(sub);
        for (int i = 0; i + size - 1 < n; i++) {
            int j = i + size - 1;
            ll hash_i_j = h[j];
            if (i) hash_i_j -= h[i - 1];
            if (hash_sub * p_pow[i] == hash_i_j)
                for (int j = i; j < i + size; j++){
                    var[j] = 1;
                }
        }
    }
    bool res = true;
    for(int i = 0; i < n; i++){
       if(!var[i]) {
           res = false;
           break;
        }
    }
    if(res) cout<< "YES"<<endl;
    else cout<< "NO"<<endl;

    

    return 0;
}