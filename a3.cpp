#include <iostream>
#include <vector>
#include <string>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits
using namespace std;

struct Lord
{
    string name;
    int income;
    bool tax_free;
    bool is_thief;
};

struct Kingdom
{
    string title;
    int coffer;
    double tax;
    int lord_count;
    Lord lords[10000];
};




int main() {
    int n;
    cin>>n;
    Kingdom arr[n];


    for(int i = 0; i < n; i++){
        cin>>arr[i].title>>arr[i].coffer>>arr[i].tax>>arr[i].lord_count;
        for(int j = 0; j < arr[i].lord_count; j++){
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            getline(cin, arr[i].lords[j].name);
            cin>>arr[i].lords[j].income>>arr[i].lords[j].tax_free>>arr[i].lords[j].is_thief;
            if(!arr[i].lords[j].tax_free){
                arr[i].coffer += arr[i].lords[j].income * arr[i].tax;
            }
            if(arr[i].lords[j].is_thief){
                arr[i].coffer -= arr[i].lords[j].income;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout<<arr[i].title<<" - "<<arr[i].coffer<<endl; 
    }

    return 0;
}