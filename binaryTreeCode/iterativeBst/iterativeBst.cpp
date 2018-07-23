#include<bits/stdc++.h>
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
    if(root == NULL){
        root = new node(data);
        return;
    }
    else{
        struct node *temp = root;
        while(1){
            if(data < temp->data){
                if(temp->l != NULL){
                    temp = temp->l;continue;
                }
                temp->l = new node(data);break;
            }
            else{
                if(temp->r != NULL){
                    temp = temp->r;continue;
                }
                temp->r = new node(data);break;
            }
        }
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

void InOrder(struct node *root){
    stack<node*> s;
    s.push(root);
    while(!s.empty()){
        if(root->l){
            root = root->l;
            s.push(root);continue;
        }
        first:
        if(root){
            cout<<root->data<<" ";
            if(root->r){
                s.pop();
                root = root->r;
                s.push(root);
            }
            else{
                s.pop();
                if(!s.empty()){
                    root = s.top();
                }
                else{
                    root = NULL;
                }
                goto first;
            }
        }
    }
    cout<<endl;
    return;
}

void PreOrder(struct node *root){
    stack<node*> s;
    s.push(root);
    while(!s.empty()){
        cout<<root->data<<" ";
        if(root->l){
            root = root->l;
            s.push(root);continue;
        }
        first:
        if(root){
            if(root->r){
                s.pop();
                root = root->r;
                s.push(root);
            }
            else{
                s.pop();
                if(!s.empty()){
                    root = s.top();
                }
                else{
                    root = NULL;
                }
                goto first;
            }
        }
    }
    cout<<endl;
    return;
}

void PostOrder(struct node *root){
    stack<node*> s;
    s.push(root);
    while(!s.empty()){
        if(root->l){
            root = root->l;
            s.push(root);continue;
        }
        struct node *current = root;
        while(root){
            if(root->r && root->r != current){
                root = root->r;
                s.push(root);break;
            }
            else if(root->r == current){
                cout<<root->data<<" ";
                current = s.top();
                s.pop();
                if(!s.empty())
                    root = s.top();
                else
                    root = NULL;
            }
            else{
                cout<<root->data<<" ";
                current = s.top();
                s.pop();
                if(!s.empty()){
                    root = s.top();
                }
                else{
                    root = NULL;
                }
            }
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
        cout<<"Enter the data in tree :- (-1 to exit)\n";
        cin>>data;
        if(data == -1)
            break;
        addNode(root, data);
    }
    cout<<"Iterative InOrder Traversal :-\n";
    InOrder(root);
    cout<<"InOrder Traversal :-\n";
    inOrder(root);
    cout<<endl;
    cout<<"Iterative PreOrder Traversal :-\n";
    PreOrder(root);
    cout<<"PreOrder Traversal :-\n";
    preOrder(root);
    cout<<endl;
    cout<<"Iterative PostOrder Traversal :-\n";
    PostOrder(root);
    cout<<"PostOrder Traversal :-\n";
    postOrder(root);
    return 0;
}
