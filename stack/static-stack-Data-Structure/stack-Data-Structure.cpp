#include <bits/stdc++.h>
using namespace std;

//blueprint of what the stack can contain
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
bool full(struct Stack &s){
    if(s.index == s.size - 1)
        return true;
    return false;
}

//checking whether the stack is empty or not
bool empty(struct Stack &s){
    if(s.index == -1){
        s.index = 0;
        return true;
    }
    return false;
}

//pushing the element into the stack according to the paradigm "last-in-first-out"
void push(struct Stack &s, int data){
    if(!full(s)){
        s.data[++s.index] = data;
    }
    else{
        cout<<"Stack is full :-\n";
    }
    return;
}

//popping element into the stack according to the paradigm "last-in-first-out"
int pop(struct Stack &s){
    return s.data[s.index--];
}

int main()
{
    cout<<"Enter the size of stack you want :-\n";
    int size = 0,data = 0;
    cin>>size;
    struct Stack s(size);

    //Entering the data into stack
    while(1){
        //ADT for entering the data into stack -> push()
        cout<<"Enter the value to be inserted in stack :- \n(-1 to break the loop)\n";
        cin>>data;
        if(data == -1)
            break;
        push(s,data);
    }

    //printing the elements that were inserted in stack
    cout<<"Stack elements are :-\n";
    while(!empty(s)){
        cout<<pop(s)<<endl;
    }
    return 0;
}
