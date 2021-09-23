#include <iostream>
#include <vector>

using namespace std;

bool search(string s, int m) {
	int n = s.size();
	vector<int> z(n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && tolower(s[z[i]]) == tolower(s[i+z[i]]))
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
        if(z[i] == m) return true;
	}
	return false;
}

int main() {
    char a;
    string s,b;
    while(cin>>a>>b){
        if(a == 'A'){
            s += b;
        }
        if(a == '?') {
            if(search(b + "#" + s, b.size())) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}