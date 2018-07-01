#include <bits/stdc++.h>
using namespace std;

//blueprint of what tree node contains.
struct tree{
    int data;
    struct tree *left,*right;
    tree(){
        this->data = 0;
        this->left = this->right = NULL;
    }
    tree(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};

//adding the data element in tree
void addNode(struct tree *&root, int data){
    if(root == NULL){
        root = new tree(data);
    }
    else if(data <= root->data){
        addNode(root->left, data);
    }
    else{
        addNode(root->right, data);
    }
    return;
}

//using queue, displaying the level order of binary tree.
void levelOrder(struct tree *root){
    if(root == NULL)
        return;
    queue<tree*> q;
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
    return;
}

int main()
{
    int data = 0;
    struct tree *root = NULL;
    while(1){
        cout<<"Enter the data in tree :-\n";
        cin>>data;
        if(data == -1)
            break;
        addNode(root, data);
    }
    levelOrder(root);
    return 0;
}
