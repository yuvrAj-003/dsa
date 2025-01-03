
#include "node.h"
#include <iostream>
using namespace std;

void oddEven(node* &head){
    node* odd = head;
    node* even = head->next;
    node* startEven = head->next;


    while(odd->next != NULL && even->next != NULL){

        odd->next = even->next;
        odd=odd->next;

        even->next = odd->next;
        even=even->next;
    }

    odd->next = startEven;
    if(even->next != NULL){
        even->next = NULL;
    }

    
}