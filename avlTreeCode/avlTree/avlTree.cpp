#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *l,*r;
    node(int data){
        this->data = data;
        this->l = this->r = NULL;
    }
};

int height(struct node *root){
    if(root == NULL)
        return -1;
    return (max(height(root->l) , height(root->r)) + 1);
}

node* right_rotate(struct node *root){
    struct node *newroot = root->l;
    root->l = newroot->r;
    newroot->r = root;
    return newroot;
}

node* left_rotate(struct node *root){
    struct node *newroot = root->r;
    root->r = newroot->l;
    newroot->l = root;
    return newroot;
}

void addNode(struct node *&root, int data){
    if(root == NULL)
        root = new node(data);
    else if(data < root->data)
        addNode(root->l, data);
    else
        addNode(root->r, data);
    int x = height(root->l), y = height(root->r);
    int balance =  x - y;
    if(balance > 1){
        if(x > y){
            root = right_rotate(root);
        }
        else{
            root->l = left_rotate(root->l);
            root = right_rotate(root);
        }
    }
    else if(balance < -1){
        if(y > x){
            root = left_rotate(root);
        }
        else{
            root->r = right_rotate(root->r);
            root = left_rotate(root);
        }
    }
    return;
}

void levelOrder(struct node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        root = q.front();
        q.pop();
        while(root){
            cout<<root->data<<" ";
            if(root->l)
                q.push(root->l);
            if(root->r)
                q.push(root->r);
            root = q.front();
            q.pop();
        }
        if(q.front() != NULL){
            cout<<endl;
            q.push(NULL);
        }
    }
    cout<<endl;
    return;
}

int main()
{
    int data = 0;
    struct node *root = NULL;
    while(1){
        cout<<"Enter the data in AVL tree :- (-1 to exit)\n";
        cin>>data;
        if(data == -1)
            break;
        addNode(root, data);
        cout<<"Level Order :-\n";
        levelOrder(root);
    }
    return 0;
}
