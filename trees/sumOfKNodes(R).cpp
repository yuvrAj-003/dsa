#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};


Node* buildTree(int arr[], int& i, int size) {
    if (i >= size || arr[i] == -1) {
        i++; // Move to the next index for the next call
        return NULL;
    }

    Node* newNode = new Node(arr[i++]);
    newNode->left = buildTree(arr, i, size);
    newNode->right = buildTree(arr, i, size);

    return newNode;
}


void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}




void clear(Node* root){
    if(root == NULL){
        return;
    }

    clear(root->left);
    clear(root->right);
    delete root;
}

int levelOrder(Node *root, int n){
    int k = 2;
    queue<Node*> q;
    stack<Node*> st;
    q.push(root);
    q.push(NULL);



    while(!q.empty()){
        Node* currentNode = q.front();
        q.pop();
        st.push(currentNode);

        if(currentNode == NULL){
            // cout << endl;

            if(q.empty()){
                break;
            }
            else{
                q.push(NULL);
            }
        }

        else{
            if(currentNode->left) q.push(currentNode->left);
            if(currentNode->right) q.push(currentNode->right);
  
        }

    }
    st.pop();
    int sum = 0;
    while(k > 0){
        if(st.top()) sum += st.top()->data;
        if(st.top() == NULL){
            k--;
        }
        st.pop();
    }

    return sum;
}

int main(){
    const int n = 12;
    int nodes[n] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1};
    int i = 0;
    Node* root = buildTree(nodes, i , n);
    // int sum = 0;
    // int k = 2;
    int Total = levelOrder(root, 2);
    cout << Total;

    
    clear(root);
    // cout << sum << endl;
}
