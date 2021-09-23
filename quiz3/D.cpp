#include <iostream>
#include <vector>

using namespace std;

int z_function(string s, int m) {
	int n = (int) s.length();
	vector<int> z (n);
    int sum = 0;
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
        if(z[i] == m) sum++;
	}
	return sum;
}

int main() {
    string a,b;
    cin>>a>>b;
    a = b + "#" + a;
    int res = z_function(a, b.size());
    cout<<res<<endl;
   return 0;
}