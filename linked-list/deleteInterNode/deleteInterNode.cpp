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

//deleting first node of list.
void deleteBeginNode(struct node *&l){
    if(l == NULL)
        return;
    struct node *temp = l;
    l = l->next;
    delete temp;
    return;
}

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

//deleting any node as per specified by user is implemented here.
void deleteInterNode(struct node *&l){

    if(l == NULL)
        return;
    int option = 0,pos = 1;
    struct node *prev = l,*curr = l;
    cout<<"\nHere we will be traversing the list \nand while traversing, enter \'1\'\nif you want to delete node at that position\nelse enter \'0\' :-\n";
    while(curr != NULL){
        cout<<"Position no. = "<<pos<<" and data value = "<<curr->data<<endl;
        cin>>option;
        if(option == 1)
            break;
        if(pos == 1){
            curr = curr->next;
            pos++;
            continue;
        }
        prev = prev->next;
        curr = curr->next;
        pos++;
    }
    if(option == 1){
        if(pos == 1){
            deleteBeginNode(l);
        }
        else if(curr->next == NULL){
            delete curr;
            prev->next = NULL;
        }
        else{
            prev->next = curr->next;
            delete curr;
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

    //delete Inter Node function is called here.
    deleteInterNode(l);
    print(l);
    return 0;
}
