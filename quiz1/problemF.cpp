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
    };

void siftUp(int i) {
        while (i > 0 && a[parent(i)] > a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    };


void heapify(int i) {
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

  

int extractMin() {
        int root_value = a[0];
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        heapify(0);
        return root_value;
    };
   


int main() {
    int min, N;
    cin>>N;
    cin>>min;
   
    for(int i = 0; i < N; i++){
        cin>>a[i];
    }

    int result = 0;
    while(a[0] < min && a.size() > 0){
        int least = extractMin();
        int newLeast = a[0];
        a[0] = least + 2 * newLeast;
        heapify(0);
        result++;
    }
    cout<<a[0]<<endl;
    if(a[0] < min){
        cout<<"-1";
    }
    else {
        cout<<result<<endl;
    }

    

    return 0;
}
