#include <bits/stdc++.h>
using namespace std;

//blueprint of what queue data structure contains.
struct Queue{

    int *data;
    int Front;
    int rear;
    int size;
    Queue(int size){

        this->data = new int[size]();
        this->Front = this->rear = -1;
        this->size = size;
    }
};

//checking whether the stack is full or not
bool full(struct Queue &q){
    if(q.rear == q.size - 1)
        return true;
    return false;
}

//checking whether the stack is empty or not
bool empty(struct Queue &q){
    if(q.Front == -1){
        return true;
    }
    return false;
}

//pushing the data into the queue according to the paradigm "first-in-first-out".
void push(struct Queue &q, int data){
    //if the queue is empty then point the front and rear to single available data.
    if(empty(q)){
        q.Front = q.rear = 0;
        q.data[q.Front] = data;
    }
    //if the queue is full then any more data can't be inserted in queue.
    else if(full(q)){
        cout<<"Queue is full :-\n";
    }
    //now the data can be inserted.
    else{
        q.data[++q.rear] = data;
    }
    return;
}

//popping element into the stack according to the paradigm "first-in-first-out"
int pop(struct Queue &q){
    int x = 0;
    if(q.Front == q.rear){
        x = q.data[q.Front];
        q.Front = q.rear = -1;
    }
    else{
        x = q.data[q.Front++];
    }
    return x;
}

int main()
{
    int size = 0, data = 0;
    cout<<"Enter the size of queue :-\n";
    cin>>size;
    struct Queue q(size);
    while(1){
        cout<<"Enter the data :-\n(-1 to exit)\n";
        cin>>data;
        if(data == -1)
            break;
         //ADT for entering the data into queue -> push()
        push(q, data);
    }
    //printing the elements that were inserted in queue
    cout<<"Queue elements are :-\n";
    while(!empty(q)){
        cout<<pop(q)<<endl;
    }
    return 0;
}
