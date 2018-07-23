#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left,*right;
    node(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};

//adding data in binary search tree.
void addNode(struct node *&root, int data){
    if(root == NULL)
        root = new node(data);
    else if(data < root->data)
        addNode(root->left, data);
    else
        addNode(root->right, data);
    return;
}

//print inOrder.
void inOrder(struct node *root){
    if(root == NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
    return;
}

//print preOrder.
void preOrder(struct node *root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    return;
}

//print postOrder.
void postOrder(struct node *root){
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
    return;
}

//printing level-order.
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
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
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
        cout<<"Enter the data in binary search tree :- (-1 to exit)\n";
        cin>>data;
        if(data == -1)
            break;
        addNode(root, data);
        cout<<"Level Order :-\n";
        levelOrder(root);
    }

    cout<<"in-order traversal :-\n";
    inOrder(root);
    cout<<endl;

    cout<<"pre-order traversal :-\n";
    preOrder(root);
    cout<<endl;

    cout<<"post-order traversal :-\n";
    postOrder(root);
    cout<<endl;
    return 0;
}
