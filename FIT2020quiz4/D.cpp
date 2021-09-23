#include <iostream>
#include <vector>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    a = b + "#" + a;
    int n = a.size();
    vector<int> p(n, 0);
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && a[i] != a[j])
            j = p[j - 1];
        if (a[i] == a[j])
            j++;
        p[i] = j;
    }
    for (int i = 0; i < n; i++)
        if (p[i] == b.size())
            cout << i - 2 * b.size()<< " ";
    return 0;
}