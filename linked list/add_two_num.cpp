#include "node.h"
#include <iostream>
using namespace std;


node* addTwoNum(node* &head1, node* &head2){

    node* t1 = head1;
    node* t2 = head2; 

    node* dummy = new node(-1);
    node* current = dummy;

    int carry = 0;
    int sum = 0;

    while(t1 != NULL || t2 != NULL){
        sum = carry;

        if(t1) sum = sum + t1->data;
        if(t2) sum = sum + t2->data;


        node* newNode = new node(sum % 10);
        carry = sum / 10;
        current->next = newNode;
        current = current->next;

        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next;

    }

    node* carrayNode = new node(carry);

    current->next = carrayNode;
    return dummy->next;

}