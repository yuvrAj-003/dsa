

#include <iostream>
#include "node.h"
using namespace std;

int countElm(node* &head){

    if(head == NULL){
        return 0;
    }

    if(head->next == NULL){
        return 1;
    }

    int c = 0;

    node *temp = head;
    while(temp != NULL){
        c++;
        temp = temp->next;
    }

    return c;
}