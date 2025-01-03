#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next=NULL;
        node (int val) : data(val) {};
};

void deleteHead(node*&head){
    if(head==NULL){
        return;
    }
    node *toBeDeleted = head;

    node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }

    temp->next = head->next;
    head=head->next;
    delete toBeDeleted;

}
void deleteNode(node*&head,int pos){
    node* temp = head;
    int count = 1;

    if(pos ==1){
        deleteHead(head);
        return;
    }
    while(count != pos-1){
        temp = temp->next;
        count++;
    }
    node *toBedeleted = temp->next;
    temp->next = temp->next->next;
    delete toBedeleted;
    

}
void insertAtHead(node*&head,int v){
    node* newNode = new node(v);

    if(head==NULL){
        newNode->next = newNode;
        head=newNode;
        return;
    }

    node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    head=newNode;


    

}

void insertAtTail(node*&head, int v){
    node* newNode = new node(v);
    
    node* temp = head;

    if(head==NULL){
        insertAtHead(head,v);
        return;
    }
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    
}

void display(node*&head){
    node *temp = head;
    do{
        cout << temp->data << " ";
        temp=temp->next;
    }
    while(temp!=head);
    cout << endl;
}

int main(){

    node* head = NULL;

    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    // insertAtHead(head,5);
    // deleteHead(head);
    deleteNode(head,3);

    display(head);

}