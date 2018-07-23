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

bool searchNode(struct node *root, string data, int index){
    bool flag;
    if(root == NULL)
        return false;
    else if(root->data == data)
        return true;
    else if(data[index%data.size()] == '0')
        flag =  searchNode(root->l, data, ++index);
    else if(data[index%data.size()] == '1')
        flag =  searchNode(root->r, data, ++index);
    else{
        cout<<"Invalid Binary Data :-\n";
        return false;
    }
    return flag;
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
    cout<<"Enter the string to be searched :-\n";
    cin>>data;
    if(searchNode(root, data, 0))
        cout<<"Binary Data Found :-\n";
    else
        cout<<"Not Found :-\n";
    return 0;
}
