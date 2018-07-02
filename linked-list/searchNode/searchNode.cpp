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

//search function is implemented here.
bool searchNode(struct node *l, int data){
    while(l != NULL){
        if(l->data == data)
            return true;
        l = l->next;
    }
    return false;
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

    //search function is called here.
    cout<<"\nEnter the data to be searched :-\n";
    cin>>data;
    if(searchNode(l, data))
        cout<<"Data Found :-\n";
    else
        cout<<"Not Found :-\n";
    return 0;
}
