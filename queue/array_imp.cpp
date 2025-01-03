#include <iostream>
using namespace std;

class Queue {
    // int n = 5;
    int n;
    int *arr;
    public:
        int front, back;
        Queue(){
            n = 5;
            front = -1;
            back =  -1;
            arr = new int[n];
        }

        ~Queue(){
            delete arr;
        }


        

        void enqueue(int item){
            if(back > n){
                cout << "OVERFLOW" << endl;
                return;
            }  

            back++;
            arr[back] = item;

            if(front == -1){
                front++;
            }

        }

        void dequeue(){
            if(front == -1 || front > back){
                cout << "UNDERFLOW" << endl;
                return;
            }

            arr[front++] = 0;

            
        }

        int peek(){
            if(front == -1 || front > back) return -1;

            // if(front == -1) front++;
            return arr[front];
        }

        int rear(){
            return arr[back];
        }
        void display(){
            for(int i = front; i <= back; i++){
                cout << arr[i] << " ";
            }
        }

        bool empty(){

            if(front == -1 || front > back){
                return true;
            }
            return false;
        }
        
};


int main(){
    Queue q;

    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    cout << q.rear();
    // q.display();

    return 0;
}