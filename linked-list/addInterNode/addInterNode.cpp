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

//adding data at the beginning of the list.
void addBeginNode(struct node *&l, int data){
    struct node *temp = new node(data);
    temp->next = l;
    l = temp;
    return;
}

//adding data at last position of list.
void addLastNode(struct node *l, int data){
    struct node *temp = new node(data);
    while(l->next != NULL)
        l = l->next;
    l->next = temp;
    return;
}

//adding node at intermediate position
void addInterNode(struct node *&l, int data){
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
        if(temp->next == NULL)
            addLastNode(l, data);
        else{
            struct node *p = new node(data);
            p->next = temp->next;
            temp->next = p;
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

    //adding node at intermediate position function is called here..
    cout<<"\nEnter the data :-\n";
    cin>>data;
    addInterNode(l, data);
    print(l);
    return 0;
}
