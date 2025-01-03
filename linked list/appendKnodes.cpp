#include <iostream>
#include "node.h"
using namespace std;


node* AppendNodes(node*&head,int l, int k){
    node*newHead;
    node*newTail;
    node*tail = head;
    int count = 1;
   
    while(tail->next!=NULL){

        if(count == l-k){
            newTail=tail;
        }

        if(count == l-k+1){
            newHead = tail;
        }
        tail=tail->next;
        count++;
    }


    newTail->next = NULL;
    tail->next = head;
    return newHead;
}