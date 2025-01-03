#include <iostream>
using namespace std;

class node{
    public:
    int val;
    node* left;
    node* right;

    node(int val) : val(val) , left(NULL) , right(NULL) {};
};


class Bst{
    public:
    node* insert(node* root, int val){
        if(root==NULL){
            root = new node(val);
            return root;
        }
        if(val < root->val){
            root->left = insert(root->left, val);
        }

        if(val > root->val){
            root->right = insert(root->right, val);
        }

        return root;
        
    }

    void inorder(node* root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }

    void clear(node* root) {

        if (root == NULL) {
            return;
        }
        clear(root->left);
        clear(root->right);
        delete root; 
    }

};


int main(){
    Bst bst;
    int elms[] = {5,1,3,4,2,7};
    node* root = NULL;


    for(int i = 0; i < 6; i++){
        root = bst.insert(root, elms[i]);
    }

    bst.inorder(root);

    bst.clear(root);
    return 0;
}