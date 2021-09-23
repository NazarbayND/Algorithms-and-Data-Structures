#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class BST {
    private:
    Node *root;
    public:
    BST() {
        root = NULL;
    }
    void insert(int data) {
        Node *node = new Node(data);
        if (root == NULL) {
            root = node;
            return;
        }

        Node *current = root;
        while(true) {
            if(data < current->data){
                if(current->left == NULL){
                    current->left = node;
                    break;
                }
                current = current->left;
            }
            else {
                if(current->right == NULL){
                    current->right = node;
                    break;
                }
                current = current->right;
            }
        }    
    }
    int recursion (Node *parent) {
            int ans = 0, l=0, r=0;
            if (parent->left == NULL && parent->right == NULL){
                return 0;
            }
            if (parent->left != NULL && parent->right != NULL){
                ans++;
            }

            if(parent->left != NULL){
                l = recursion(parent->left);
            }
            if(parent->right != NULL){
                r = recursion(parent->right);
            }
            return ans + l + r;
    }
    
    int findSmallestTriangles () {
        return recursion(root);
    }
    
   
};

int main() {
    BST *bst = new BST();
    int N;
    cin>>N;
    for (int i = 0; i < N; i++){
        int data;
        cin>>data;
        bst->insert(data);
    }
    cout<<bst->findSmallestTriangles()<<endl;

    return 0;
}