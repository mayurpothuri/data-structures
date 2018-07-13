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

//add begin node function is implemented here.
void addBeginNode(struct node *&l, int data){

    struct node *temp = new node(data);
    temp->next = l;
    l->prev = temp;
    l = temp;
    return;
}

//adding node at intermediate position
void addInterNode(struct node *&l, int data){
    if(l == NULL){
        addNode(l, data);
        return;
    }
    int option = 0,pos = 1;
    struct node *temp = l;
    cout<<"Here we will be traversing the list \nand while traversing, enter \'1\'\nif you want to insert node at that position\nelse enter \'0\' :-\n";
    while(temp != NULL){
        cout<<"Position no. = "<<pos<<" and data value = "<<temp->data<<endl;
        cin>>option;
        if(option != 1){
            temp = temp->next;
            pos++;
            continue;
        }
        else
            break;
    }
    if(option == 1){
        if(temp == l)
            addBeginNode(l, data);
        else if(temp->next == NULL){
            temp->next = new node(data);
            temp->next->prev = temp;
        }
        else{
            temp = temp->prev;
            struct node *p = temp->next;
            temp->next = new node(data);
            temp->next->prev = temp;
            temp->next->next = p;
            p->prev = temp->next;
        }
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

    //add inter node function is called here.
    cout<<"\nEnter the data here to add at any intermediate position :-\n";
    cin>>data;

    addInterNode(l, data);

    print(l);
    cout<<endl;
    printReverse(l);
    return 0;
}
