#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin>>n;
    int a[n][2];

	for(int i = 0; i < n; i++){
	  
	   for(int j = 0; j < 2; j++){
	      cin >> a[i][j];
	   }
	}

	for(int i = 0; i < n; i++){
       k=0; 
	   for(int j = 0; j < i; j++){
	      if( ((a[i][0]==a[j][0]) && (a[i][1]==a[j][1])) || ((a[i][0]==a[j][1]) && (a[i][1] == a[j][0])) ){
              k+=1;
          }
	   }
       cout<<k<<endl;
	}

	   return 0;
}


