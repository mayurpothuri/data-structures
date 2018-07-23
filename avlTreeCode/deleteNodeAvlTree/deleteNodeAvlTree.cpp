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
        cout<<root->data<<" -> "<<balance<<endl;
    }
    else if(balance < -1){
        if(y > x){
            root = left_rotate(root);
        }
        else{
            root->r = right_rotate(root->r);
            root = left_rotate(root);
        }
        cout<<root->data<<" -> "<<balance<<endl;
    }
    return;
}

void inOrder(struct node *root){
    if(root == NULL)
        return;
    inOrder(root->l);
    cout<<root->data<<" ";
    inOrder(root->r);
    return;
}

void preOrder(struct node *root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->l);
    preOrder(root->r);
    return;
}

void postOrder(struct node *root){
    if(root == NULL)
        return;
    postOrder(root->l);
    postOrder(root->r);
    cout<<root->data<<" ";
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
            cout<<"( "<<height(root->l) - height(root->r)<<" ) ";
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
    else if(root->r == NULL)
        return root;
    return findMax(root->r);
}

node* deleteNode(struct node *&root, int data){
    if(root == NULL)
        return NULL;
    if(data < root->data){
        root->l = deleteNode(root->l, data);
    }
    else if(data > root->data){
        root->r = deleteNode(root->r, data);
    }
    else{
        //node to be deleted.
        if(root->l == NULL && root->r){
            delete root;
            root = NULL;
            return root;
        }
        else if(root->l == NULL){
            struct node *temp = root;
            root = root->r;
            delete temp;
            return root;
        }
        else if(root->r == NULL){
            struct node *temp = root;
            root = root->l;
            delete temp;
            return root;
        }
        else{
            struct node *temp = findMax(root->l);
            root->data = temp->data;
            root->l = deleteNode(root->l, temp->data);
        }
    }
    //for re-balancing
    int x = height(root->l);
    int y = height(root->r);
    int balance = x - y;
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
    return root;
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
    cout<<"Enter the data to be deleted :- \n"<<endl;
    cin>>data;
    root = deleteNode(root, data);
    cout<<"InOrder Traversal :-\n";
    inOrder(root);
    cout<<"\nPreOrder Traversal :-\n";
    preOrder(root);
    cout<<"\nPostOrder Traversal :-\n";
    postOrder(root);
    cout<<"\nLevel Order :-\n";
    levelOrder(root);
    return 0;
}
