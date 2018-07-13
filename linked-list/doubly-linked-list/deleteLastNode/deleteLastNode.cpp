#include <bits/stdc++.h>
using namespace std;

struct node{

    int data;
    struct node *prev,*next;
    node(int data){
        this->data = data;
        this->prev = this->next = NULL;
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

//printing in reverse.
void printReverse(struct node *l){
    if(l == NULL)
        return;
    while(l->next != NULL)
        l = l->next;
    while(l != NULL){
        cout<<l->data<<" ";
        l = l->prev;
    }
    return;
}

//adding data into the list.
void addNode(struct node *&l, int data){
    if(l == NULL)
        l = new node(data);
    else{
        struct node *temp = l;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = new node(data);
        temp->next->prev = temp;
    }
    return;
}

//deleting last node of list.
void deleteLastNode(struct node *&l){

    if(l == NULL)
        return;
    else if(l->next == NULL){
        delete l;
        l = NULL;
    }
    else{
        struct node *temp = l;
        while(temp->next->next != NULL)
            temp = temp->next;
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
    cout<<endl;
    printReverse(l);

    //delete last node function is called here.
    cout<<"\nAfter Deleting last node of list :-\n";
    deleteLastNode(l);

    print(l);
    cout<<endl;
    printReverse(l);
    return 0;
}
