#include <bits/stdc++.h>
using namespace std;

//blueprint of what the list node contains.
struct node{
    int data;
    struct node *next;
    node(){
        this->next = NULL;
    }
    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

//printing the list.
void print(struct node *l){
    if(l == NULL)
        return;
    cout<<l->data<<" ";
    print(l->next);
    return;
}

//adding data into the list.
void addNode(struct node *&l, int data){
    if(l == NULL){
        l = new node(data);
    }
    else
        addNode(l->next, data);
    return;
}

//deleting last node.
//Note :-
//Here after the statement "delete temp->next", if we try to access that location, it will show the
//contents of that memory  and we might think that the "delete" keyword is not working.
//Here we need to understand that "delete" keyword is just saying to "memory management unit"(Operating System)
//that this memory location is longer to use so it can be re-used when require and it also doesn't
//delete the content of that memory too unless if required.
void deleteLastNode(struct node *&l){
    if(l == NULL)
        return;
    if(l->next == NULL){
        delete l;
        l = NULL;
    }
    else{
        struct node *temp = l;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    return;
}

int main()
{
    int data = 0;
    struct node *l = NULL;
    while(1){
        cout<<"Enter the data in list :- (-1 to exit)\n";
        cin>>data;
        if(data == -1)
            break;
        addNode(l, data);
    }
    print(l);

    cout<<"\nAfter deleting last node :-\n";
    deleteLastNode(l);
    print(l);
    return 0;
}
