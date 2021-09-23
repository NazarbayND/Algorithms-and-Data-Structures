#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int sorting(string a, string b){
    string d1 = a.substr(0, 2);
    string m1 = a.substr(3, 2);
    string y1 = a.substr(6, 4);
 
    string d2 = b.substr(0, 2);
    string m2 = b.substr(3, 2);
    string y2 = b.substr(6, 4);
 
  
    if (y1 < y2)
        return 1;
    if (y1 > y2)
        return 0;
 

    if (m1 < m2)
        return 1;
    if (m1 > m2)
        return 0;
 

    if (d1 < d2)
        return 1;
    if (d1 > d2)
        return 0;
    return 0;
}
 
int main()
{
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i = 0; i < n; i++){
       cin>>a[i];
    }

    sort(a.begin(), a.end(), sorting);
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << endl;


    return 0;
}