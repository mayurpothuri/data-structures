#include <bits/stdc++.h>
using namespace std;

struct node{
    vector<int> data;
    struct node *l,*r;
    node(vector<int> &data){
        this->data.push_back(data[0]);
        this->data.push_back(data[1]);
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
            cout<<root->data[0]<<","<<root->data[1]<<"__";
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

void addNode(struct node *&root, vector<int> &data, int index){
    if(root == NULL)
        root = new node(data);
    else if(data[index%data.size()] < root->data[index%data.size()])
        addNode(root->l, data, ++index);
    else
        addNode(root->r, data, ++index);
    return;
}

int findMax(struct node *root, int k, int index){
    if(root == NULL)
        return -1;
    if(index == k){
        if(root->r == NULL)
            return root->data[k];
        return max(root->data[k], findMax(root->r, k, ++index%2));
    }
    return max(max(findMax(root->l, k, ++index%2), findMax(root->r, k, ++index%2)) , root->data[k]);
}

int main()
{
    vector<int> data(2,0);
    struct node *root = NULL;
    while(1){
        cout<<"Enter the points in 2-d tree :-\n";
        cin>>data[0]>>data[1];
        if(data[0] == -1)
            break;
        addNode(root, data, 0);
        cout<<"Level Order :-\n";
        levelOrder(root);
    }
    cout<<"Level Order :-\n";
    levelOrder(root);
    cout<<"Maximum in 0th dimension = "<<findMax(root, 0, 0)<<endl;
    cout<<"Maximum in 1st dimension = "<<findMax(root, 1, 0)<<endl;
    return 0;
}
