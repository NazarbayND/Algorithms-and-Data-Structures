#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin>>n;
    int a[n][2];
    vector<int> b(n);

	for(int i = 0; i < n; i++){
	   for(int j = 0; j < 2; j++){
	      cin >> a[i][j];
	   }
	}

    cout<<0<<endl;

	for(int i = 1; i < n; i++){ 
        int j = i - 1;
        while (j > -1 && !(((a[i][0]==a[j][0]) && (a[i][1]==a[j][1])) || ((a[i][0]==a[j][1]) && (a[i][1] == a[j][0])))){
            j--;
        }
        if(j == -1) cout << 0 <<endl;
        else {
            b[i] = b[j] + 1;
            cout<<b[i]<<endl;
            }
	}

	   return 0;
}



