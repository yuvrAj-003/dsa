#include "node.h"
#include <iostream>

using namespace std;

node* reverseKnodes(node *head , int k){

    node* prevPtr = NULL;
    node* currPtr = head;
    node* nextPtr;

    int count = 0;
    while(currPtr != NULL && count < k){

        nextPtr = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;
        count++;
    }

    if(nextPtr != NULL){
        head->next = reverseKnodes(nextPtr, k);
    }

    return prevPtr;
    
}