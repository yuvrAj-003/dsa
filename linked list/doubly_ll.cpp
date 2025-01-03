#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next=NULL;
        node* prev=NULL;
        node(int val): data(val){}
};

void delete_at_head(node*&head){
    node*toDel = head;
    head=head->next;
    head->prev = NULL;
    delete toDel;
}

void delete_node(node*&head,int val){

    node*temp = head;

    if(head->data == val){
        delete_at_head(head);
        return;
    }

    while(temp->data != val && temp != NULL){
        temp=temp->next;
    }

    node *toBeDeleted = temp;
    if(temp->prev != NULL) temp->prev->next = temp->next;
    if(temp->next != NULL) temp->next->prev = temp->prev;
    delete toBeDeleted;
}
void insert_at_head(node*&head, int val){
    node* n = new node(val);

    n->next = head; 
    if(head != NULL){
        head->prev = n;
    }
    head=n;
}


void insert_at_tail(node*&head, int val){
    node* n = new node(val);

    if(head == NULL){
        insert_at_head(head,val);
        return;
    }

    node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = n;
    n->prev = temp;
}


void displayList(node* &head){

    node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout <<"NULL"<<endl;
}



int main(){
    node*head = NULL;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_head(head,5);
    displayList(head);
    delete_node(head,2);
    displayList(head);


    return 0;
}