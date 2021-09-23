#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {

    string s; 
    cin>>s;
    int n = s.length();

  
    const int p = 31;
    vector<ll> p_pow (n);
    p_pow[0] = 1;
    for (size_t i=1; i<p_pow.size(); ++i)
        p_pow[i] = p_pow[i-1] * p;



   
    vector<ll> h (n);
    for (size_t i=0; i<n; ++i)
    {
        h[i] = (s[i] - 'a' + 1) * p_pow[i];
        if (i)  h[i] += h[i-1];
    }

    int result = 0;


    for (int l = 1; l <= n; ++l)
    {
        vector<ll> hs (n-l+1);
        for (int i = 0; i < n - l + 1; ++i)
        {
            ll cur_h = h[i+l-1];
            if (i)  cur_h -= h[i-1];
        
            cur_h *= p_pow[n-i-1];
            hs[i] = cur_h;
        }
   
        sort(hs.begin(), hs.end());
        hs.erase(unique (hs.begin(), hs.end()), hs.end());
        result += (int) hs.size();
    }

    cout << result<<endl;
}