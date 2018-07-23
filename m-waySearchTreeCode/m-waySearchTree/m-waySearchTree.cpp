#include <bits/stdc++.h>
using namespace std;

const int m = 2;

struct node{
    vector<int> data;
    struct node **p;
    node(){
        this->p = new node*[m + 1]();
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
            for(unsigned int i = 0; i < root->data.size(); i++){
                cout<<root->data[i]<<" ";
                if(root->p[i])
                    q.push(root->p[i]);
            }
            if(root->p[root->data.size()])
                q.push(root->p[root->data.size()]);
            root = q.front();
            q.pop();
            cout<<"\t";
        }
        if(q.front() != NULL){
            cout<<endl;
            q.push(NULL);
        }
    }
    cout<<endl;
    return;
}

void addNode(struct node *&root, int data){
    if(root == NULL){
        root = new node();
        root->data.push_back(data);
    }
    else if(root->data.size() == m){
        unsigned int i;
        for(i = 0; i < root->data.size(); i++){
            if(data < root->data[i])
                break;
        }
        addNode(root->p[i], data);
    }
    else{
        root->data.push_back(data);
        sort(root->data.begin(), root->data.end());
    }
    return;
}

int main()
{
    int data = 0;
    struct node *root = NULL;
    while(1){
        cout<<"Enter the data in m-way search tree :-\n";
        cin>>data;
        if(data == -1)
            break;
        addNode(root, data);
        cout<<"Level Order :-\n";
        levelOrder(root);
    }
    cout<<"Level Order :-\n";
    levelOrder(root);
    return 0;
}
