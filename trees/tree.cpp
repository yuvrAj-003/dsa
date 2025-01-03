#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class TreeData{

        public:
            int height;
            int diam;

            TreeData(int height, int diam){
                this->height = height;
                this->diam = diam;
            }
    };

class binaryTree { 
    public:
    static int idx;
    node* buildTree(int nodes[], int size) {
        idx++;
        if (idx >= size || nodes[idx] == -1) {
            return NULL;
        }
        node* newNode = new node(nodes[idx]);
        newNode->left = buildTree(nodes, size);
        newNode->right = buildTree(nodes, size);

        return newNode;
    }


    TreeData* diameter(node* root){
        if(root == NULL){
            return new TreeData(0,0);
        }

        TreeData *leftDia = diameter(root->left);

        TreeData *rightDia = diameter(root->right);

        int myHeight = max(leftDia->height, rightDia->height) + 1;

        int dia1 = leftDia->diam;
        int dia2 = rightDia->diam;
        int dia3 = leftDia->height + rightDia->height + 1;


        int myDia = max(max(dia1, dia2), dia3);

        TreeData *dia = new TreeData(myHeight, myDia);

        return dia;

        
    }

    // pre order
    void preorder(node* root) {
        if (root == NULL) {
            return;
        }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    // inorder
    void inorder(node* root) {
        if (root == NULL) {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    // post order
    void postorder(node* root){
        if(root== NULL){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " " ;
    }


    // level order
    void levelOrder(node* root){
        queue<node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            node *currentEle = q.front();
            q.pop();

            if(currentEle == NULL){
                cout << endl;

                if(q.empty()){
                    break;
                }
                else{
                    q.push(NULL);
                }
            }
            else{
                cout << currentEle->data << " ";
                if(currentEle->left) q.push(currentEle->left);
                // if(currentEle->right) q.push(currentEle->right);
            }

        }
    }

    // count all nodes
    int countAllNode(node *root){
        if(root == NULL){
            return 0;
        }

        int left = countAllNode(root->left);
        int right = countAllNode(root->right);

        return left + right + 1;
    }

    // sum of nodes

    int sumOfNodes(node* root){
        // static int sum = 0;

        if(root == NULL){
            return 0;
        }
        int left = sumOfNodes(root->left);
        int right = sumOfNodes(root->right);

        return left + right + root->data;

    }

    // height of node

    int heightOfNode(node* root){

        if(root == NULL){
            return 0;
        }
        int left = heightOfNode(root->left);
        int right = heightOfNode(root->right);

        int myHieght = max(left , right) + 1;

        return myHieght;
    }
    
    
   

    

    // Destructor to free memory
    void clear(node* root) {

        idx = -1;
        if (root == NULL) {
            return;
        }
        clear(root->left);
        clear(root->right);
        delete root; 
    }
};

int binaryTree::idx = -1;

int main() {
    const int n = 12;
    int nodes[n] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1};

    // creation
    binaryTree bt;
    node* root = bt.buildTree(nodes, n);
    
    // traversal
    // cout << "posorder Traversal" << endl;
    // bt.inorder(root);

    TreeData *dia = bt.diameter(root);

    cout << dia->diam << endl;
    // Clear memory
    bt.clear(root);

    return 0;
}