#include <bits/stdc++.h>
using namespace std;

struct node{
    string data;
    struct node *l,*r;
    node(string data){
        this->data = data;
        this->l = this->r = NULL;
    }
};

void levelOrder(struct node *root){
    if(root == NULL)
        return;
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

int height(struct node *root){
    if(root == NULL)
        return -1;
    return max(height(root->l), height(root->r)) + 1;
}

void addNode(struct node *&root, string data, int index){
    if(root == NULL)
        root = new node(data);
    else if(data[index%data.size()] == '0')
        addNode(root->l, data, ++index);
    else if(data[index%data.size()] == '1')
        addNode(root->r, data, ++index);
    else
        cout<<"Invalid Binary Data :-\n";
    return;
}

node* deleteNode(struct node *root, string data, int index){
    if(root == NULL)
        return NULL;
    else if(root->data == data){
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
            struct node *temp;
            if(height(root->l) < height(root->r))
                temp = root->l;
            else
                temp = root->r;
            root->data = temp->data;
            root->l = deleteNode(temp, root->data, index);
        }
    }
    else if(data[index%data.size()] == '0')
        root->l = deleteNode(root->l, data, ++index);
    else if(data[index%data.size()] == '1')
        root->r = deleteNode(root->r, data, ++index);
    else{
        cout<<"Invalid Binary string to be deleted :-\n";
        return false;
    }
    return root;
}

int main()
{
    string data;
    struct node *root = NULL;
    while(1){
        cout<<"Enter the binary data in DST :-\n";
        cin>>data;
        if(data == "-1")
            break;
        addNode(root, data, 0);
        cout<<"Level Order :-\n";
        levelOrder(root);
    }
    cout<<"Enter the Binary Data to be deleted :-\n";
    cin>>data;
    root = deleteNode(root, data, 0);
    cout<<"Level Order :-\n";
    levelOrder(root);
    return 0;
}
