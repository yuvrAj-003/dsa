#include <iostream>
#include "node.h"
#include "reverse_list.cpp"
#include "count_elm.cpp"
#include "add_two_num.cpp"
#include "odd_even.cpp"
#include "merge_sorted_list.cpp"
#include "reverse_k_nodes.cpp"
#include "checkRemoveCycle.cpp"
#include "appendKnodes.cpp"
using namespace std;

// print linked list

int lengthOfL(node*&head){


    
    node* temp = head;
    int count = 0;

    while(temp!=NULL){
        count++;
        temp =temp->next;
    }

    return count;
}

void printLL(node* &head){

    node* temp = head;

    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
    cout << endl;
}

// insert at tail
void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

// insert at head
void insertAtHead(node* &head, int val){
    node* n = new node(val);

    n->next = head;
    head = n;
}

// delete head
void deleteHead(node* &head){
    node *toDelete = head;
    head = head->next;
    delete toDelete;
}

// delete node
void deleteNode(node* &head, int val){

    if(head == NULL){
        return;
    }

    if(head->next == NULL){
        deleteHead(head);
        return;
    }

    if(val == head->data){
        deleteHead(head);
        return;
    }
    node* temp = head;
    while(temp->next->data != val){
        temp = temp->next;
    }
    node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

// delete last node
void deleteLast(node* &head){
    node *temp = head;
    if(head == NULL){
        return;
    }

    if(head->next == NULL){
        deleteHead(head);
        return;

    }

    while(temp->next->next != NULL){
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

// check node
string check(node* &head, int data){
    node* temp = head;

    while(temp!=NULL){
        if(temp->data == data) return "true";
        temp=temp->next;
    }

    return "false";
}

// driver's code
int main(){
    node* head = NULL;
    insertAtTail(head , 1);
    insertAtTail(head , 2);
    insertAtTail(head , 3);
    insertAtTail(head , 4);
    insertAtTail(head , 5);
    insertAtTail(head , 6);

    oddEven(head);

    // node* newHead = mergeOddEven(h1,h2);

    printLL(head);
    // printLL(h2);

    // int l = lengthOfL(head);
    // int k = 3;
    // cout << l << endl;
    // node*newHead = AppendNodes(head,l,k);

    // makeCycle(head, 3);

    // removeCycle(head);

    // cout << checkCycle(head) << endl;

    // printLL(newHead);

    // insertAtHead(head, 10);
    // deleteLast(head);

    // head = reverseLL(head);
    // printLL(head);

    
    // cout << check(head, 5);


    return 0;
}

