#include <bits/stdc++.h>
using namespace std;

//blueprint of what queue data structure contains.
struct Queue{

    int *data;
    int size;
    int Front;
    int rear;
    Queue(int size){
        this->data = new int[size]();
        this->size = size;
        this->Front = this->rear = -1;
    }
};

//checking whether the stack is full or not
bool full(struct Queue *q){
    if(q->rear == q->size - 1)
        return true;
    return false;
}

//checking whether the stack is empty or not
bool empty(struct Queue *q){
    if(q->Front == -1){
        return true;
    }
    return false;
}

//pushing the data into the queue according to the paradigm "first-in-first-out".
Queue* push(struct Queue *q, int data){
    //if the queue is empty then point the front and rear to single available data.
    if(empty(q)){
        q->Front = q->rear = 0;
        q->data[q->Front] = data;
    }
    //if the queue is full copy and paste method is used here.
    else if(full(q)){
        struct Queue *temp = new Queue(q->size + 1);
        temp->Front = 0;
        for(int i = 0; i < q->size; i++){
            temp->data[++temp->rear] = q->data[i];
        }
        temp->data[++temp->rear] = data;
        return temp;
    }
    //now the data can be inserted.
    else{
        q->data[++q->rear] = data;
    }
    return q;
}

//popping element into the stack according to the paradigm "first-in-first-out"
int pop(struct Queue *q){
    int x = 0;
    if(q->Front == q->rear){
        x = q->data[q->Front];
        q->Front = q->rear = -1;
    }
    else{
        x = q->data[q->Front++];
    }
    return x;
}

int main()
{
    struct Queue *q = new Queue(1);
    int data = 0;
    while(1){
        cout<<"Enter the data in queue :-\n (-1 to exit)\n";
        cin>>data;
        if(data == -1)
            break;
        q = push(q, data);
    }
    cout<<"Queue elements are :-\n";
    while(!empty(q)){
        cout<<pop(q)<<endl;
    }
    return 0;
}
