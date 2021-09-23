#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll p_pow[1000000];
vector<ll> h(1000000);

void init_p(int l, int r) {
    ll p = 31;
    p_pow[0] = 1;
    int size =  l + r;
    if(l == 0) l++;
    if(r == 1) return;
    for (int i = l; i < size; i++)
        p_pow[i] = p_pow[i - 1] * p;
}

void hash_(string s, int l) {
    int size = l + s.size();
    if (l == 0){
        h[0] = s[0];
        l++;
    }
    for (int i = l; i < size; i++){
        h[i] = h[i - 1] + s[i] * p_pow[i]; 
    }
}

ll hash_string(string s) {
    ll sum = 0;
    for (int i = 0; i < s.size(); i++)
        sum += s[i] * p_pow[i];
    return sum;
}

void check (string s) {
    int size = s.size();
    bool has = false;
    ll hash_t = hash_string(s);
    for (int j = size - 1; j < h.size() - 1; j++){
                ll h_i_j = h[j];

                if (j >= size){
                    // cout<<h_i_j<<" " << h[j-size]<<endl;
                    h_i_j -= h[j-size];
                }
            cout<<h_i_j << " " << hash_t * p_pow[j - size + 1]<<endl;

                if ( h_i_j == hash_t * p_pow[j - size + 1]){
                    has = true;
                    break;
            }
        }
    if(has) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    string s, t;
    while (true) {
        cin >> t;
        string w;
        if(t == "+"){
            cin>>w;
            int size = s.size();
            int w_size =  w.size();
            init_p(size, w_size);
            hash_(w, size);
            s += w;
        }
        else if (t == "?"){
            cin>>w;
            if(w.size() > s.size())
                cout<<"NO"<<endl; 
            else check(w);
        }
        else {
            break;
        }
    }
    return 0;
}