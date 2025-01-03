

#include <iostream>
#include "node.h"
using namespace std;

node* reverseLL(node* &head){

    if(head == NULL || head->next == NULL){
        return head;
    }
    node* newNode = reverseLL(head->next);
    node* front = head->next;
    front->next = head;
    head->next = NULL;

    return newNode;


}