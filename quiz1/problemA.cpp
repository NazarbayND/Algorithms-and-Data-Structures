#include <iostream>
using namespace std;

struct Node
{
    string word;
    Node *next;

    Node() {}

    Node(string word)
    {
        this->word = word;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node *front, *tail;

    LinkedList()
    {
        front = NULL;
        tail = NULL;
    }

    void push_back(string data)
    {
        Node *node = new Node(data);

        if (tail == NULL)
        {
            tail = node;
            front = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }
};

// your code goes here

void cyclicShift(LinkedList *ll, int k){
    if(k == 0) return;

    ll->tail->next = ll->front;
    for (int i = 0; i < k; i++){
        ll->tail = ll->tail->next;
    }
    ll->front = ll->tail->next;
    ll->tail->next = NULL;
    return;
}

void print(LinkedList *ll)
{
    Node *cur = ll->front;
    while (cur != NULL)
    {
        cout << cur->word << " ";
        cur = cur->next;
    }
    cout << endl;
    return;
}

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;

    LinkedList *ll = new LinkedList();
    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        ll->push_back(word);
    }

    cyclicShift(ll, k);
    print(ll);

    return 0;
}