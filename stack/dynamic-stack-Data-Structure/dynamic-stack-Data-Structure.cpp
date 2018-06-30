#include <bits/stdc++.h>
using namespace std;

//blueprint for what the stack contains
struct Stack{

    int *data;
    int index;
    int size;
    Stack(int size){
        this->data = new int[size]();
        this->index = -1;
        this->size = size;
    }
};

//checking whether the stack is full or not
bool full(struct Stack *s){
    if(s->index == s->size - 1)
        return true;
    return false;
}

//checking whether the stack is empty or not
bool empty(struct Stack *s){
    if(s->index == -1){
        s->index = 0;
        return true;
    }
    return false;
}

//pushing the data in stack according to the paradigm "last-in-first-out"
Stack* push(struct Stack *s, int data){

    bool check = full(s);
    if(check){
        struct Stack *temp = new Stack(s->size + 1);
        for(int i = 0; i < s->size; i++){
            temp->data[++temp->index] = s->data[i];
        }
        temp->data[++temp->index] = data;
        return temp;
    }
    else{
        s->data[++s->index] = data;
    }
    return s;
}

//popping data in stack according to the paradigm "last-in-first-out"
int pop(struct Stack *s){
    return s->data[s->index--];
}

int main()
{
    int data = 0;
    Stack *s = new Stack(1);
    while(1){

        cout<<"Enter the data in stack :-\n (-1 to exit)\n";
        cin>>data;
        if(data == -1)
            break;
        s = push(s, data);
    }

    cout<<"Stack elements are :-\n";
    while(!empty(s)){
        cout<<pop(s)<<endl;
    }
    return 0;
}
