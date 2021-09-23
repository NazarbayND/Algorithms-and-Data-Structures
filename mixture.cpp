#include <iostream>
#include <vector>

using namespace std;
 vector<int> a;

int parent(int i) {
    return (i - 1) / 2;
};

int left(int i) {
    return 2 * i + 1;
};

int right(int i) {
    return 2 * i + 2;
}

void heapify(int i){
    if (left(i) > a.size() - 1)
        return;
    int j = left(i);
    if (right(i) < a.size() && a[right(i)] < a[left(i)])
        j = right(i);
    if (a[i] > a[j]) {
        swap(a[i], a[j]);
        heapify(j);
    }
};   

void siftUp( int i){
    while (i > 0 && a[parent(i)] > a[i]) {
        swap(a[parent(i)], a[i]);
        i = parent(i);
    }
};

int extractMin() {
    int root_value = a[0];
    swap(a[0], a[a.size() - 1]);
    a.pop_back();
    heapify(0);
    return root_value;
};

void insert(int k) {
    a.push_back(k);
    int i = a.size() - 1;
    siftUp(i);
};

void increaseKey(int i, int new_value) {
    a[i] = new_value;
    heapify(i);
};

int main() {
    int n, m;
    cin>>n;
    cin>>m;
    for(int i = 0; i < n; i++){
        int d;
        cin>>d;
        insert(d);
    }
    int res = 0;
    while(a[0] < m && a.size() > 1){
        int least = extractMin();
        int newleast = a[0];
        increaseKey(0, least + newleast*2);
        res++;
    }
    if(a[0] < m){
        cout<<-1;
    }
    else {
        cout<<res;
    }
    
    
    
   return 0;

}