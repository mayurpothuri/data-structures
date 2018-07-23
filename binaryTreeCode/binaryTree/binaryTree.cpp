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

//adding data in binary tree.
void addNode(struct node *&root, int data){
    if(root == NULL){
        root = new node(data);
    }
    else{
        char ch;
        jump:
        cout<<"Enter \'l\' for left\n or enter \'r\' for right of data = "<<root->data<<endl;
        cin>>ch;
        if(ch == 'l')
            addNode(root->left, data);
        else if(ch == 'r')
            addNode(root->right, data);
        else
            goto jump;
    }
    return;
}

//printing level order.
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
    struct node *root = NULL;
    int data = 0;
    while(1){
        cout<<"Enter the data in binary tree :-\n";
        cin>>data;
        if(data == -1)
            break;
        addNode(root, data);
        cout<<"Level Order :-\n";
        levelOrder(root);
    }
    return 0;
}
