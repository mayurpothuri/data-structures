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

void addNode(struct node *&root, int data){
    if(root == NULL)
        root = new node(data);
    else if(data < root->data)
        addNode(root->l, data);
    else
        addNode(root->r, data);
    return;
}

void levelOrder(struct node *root){
    if(root == NULL)
        return;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        root = q.front();
        q.pop();
        while(root != NULL){
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

node* findMax(struct node *root){
    if(root == NULL)
        return NULL;
    if(root->r == NULL)
        return root;
    return findMax(root->r);
}

node* deleteNodeBst(struct node *&root, int data){
    if(root == NULL)
        return NULL;
    if(data < root->data)
        root->l = deleteNodeBst(root->l, data);
    else if(data > root->data)
        root->r = deleteNodeBst(root->r, data);
    else{
        if(root->l == NULL && root->r == NULL){
            delete root;
            root = NULL;
        }
        else if(root->l == NULL){
            struct node *temp = root;
            root = root->r;
            delete temp;
        }
        else if(root->r == NULL){
            struct node *temp = root;
            root = root->l;
            delete temp;
        }
        else{
            struct node *temp = findMax(root->l);
            root->data = temp->data;
            cout<<"temp = "<<temp->data<<endl;
            root->l = deleteNodeBst(root->l, temp->data);
        }
    }
    return root;
}

int main()
{
    int data = 0;
    struct node *root = NULL;
    while(1){
        cout<<"Enter the data in Bst :- (-1 to exit)\n";
        cin>>data;
        if(data == -1)
            break;
        addNode(root, data);
        cout<<"Level Order :-\n";
        levelOrder(root);
    }
    cout<<"Enter the data to be deleted :-\n";
    cin>>data;
    root = deleteNodeBst(root, data);
    cout<<"Level Order :-\n";
    levelOrder(root);
    return 0;
}
