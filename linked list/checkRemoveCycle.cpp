#include "node.h"
#include <iostream>
using namespace std;



bool checkCycle(node* &head){

    node *slow = head;
    node *fast = head;
    while(fast != NULL && fast->next != NULL){

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }

    }
    return false;
}


void makeCycle(node* &head, int k){

    node* temp = head;
    int count = 1;
    node* startNode;
    while(temp->next != NULL){
        if(count == k){
            startNode = temp;
        }

        temp = temp->next;
        count++;
    }

    temp->next = startNode;

}


void removeCycle(node* &head){


    node* slow = head;
    node* fast = head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    }
    while(slow != fast);


    fast = head;

    while(fast->next != slow->next){

        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
}