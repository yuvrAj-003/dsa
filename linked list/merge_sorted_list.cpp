#include "node.h"

#include <iostream>

using namespace std;


node* mergeList(node* &h1 , node* &h2){

    node* t1 = h1;
    node* t2 = h2;

    node* dummy = new node(-1);
    node* current = dummy;

    while(t1 != NULL && t2 != NULL){


        if(t1->data < t2->data){    
            current->next = t1;
            t1 = t1->next;
        }
        else{
            current->next = t2;
            t2 = t2->next;
        }

        current = current->next;

    }

    while(t1 != NULL){
        current->next = t1;
        t1 = t1->next;
        current = current->next;
    }

    while(t2 != NULL){
        current->next = t2;
        t2 = t2->next;
        current = current->next;
    }

    return dummy->next;
}


node* mergeRecursive(node* &h1 , node* &h2){

    if(h1 == NULL) return h2;

    if(h2 == NULL) return h1;

    node* result;
    if(h1->data < h2->data){   
        result = h1;
        result->next = mergeRecursive(h1->next , h2);
    }
    else{
        result = h2;
        result->next = mergeRecursive(h1, h2->next);
    }

    return result;
}