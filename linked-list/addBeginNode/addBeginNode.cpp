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
void addBegin(struct node *&l, int data){
    struct node *temp = new node(data);
    temp->next = l;
    l = temp;
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

    //add begin function is called here.
    cout<<"\nEnter the data to inserted at beginning of the list :-\n";
    cin>>data;
    addBegin(l, data);
    print(l);
    return 0;
}
