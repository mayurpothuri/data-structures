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

void addNode(struct node *&root, vector<int>& data, int index){
    if(root == NULL)
        root = new node(data);
    else if(data[index%data.size()] < root->data[index%data.size()])
        addNode(root->l, data, ++index);
    else
        addNode(root->r, data, ++index);
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
        while(root){
            cout<<root->data[0]<<", "<<root->data[1]<<"__";
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

int findMin(struct node *root, int k, int index){
    if(root == NULL)
        return 10000000000;
    if(index == k){
        if(root->l == NULL)
            return root->data[k];
        return min(root->data[k], findMin(root->l, k, index%2));
    }
    return min(min(findMin(root->l, k, ++index%2), findMin(root->r, k, ++index%2)) , root->data[k]);
}

int main()
{
    vector<int> data(2,0);int k = 0;
    struct node *root = NULL;
    while(1){
        cout<<"Enter the data in 2-d_Tree :-\n";
        cin>>data[0]>>data[1];
        if(data[0] == -1)
            break;
        addNode(root, data, 0);
        cout<<"Level Order :-\n";
        levelOrder(root);
    }
    cout<<"Level Order :-\n";
    levelOrder(root);
    /*cout<<"Enter the dimension for which minimum is to be found :-\n";
    cin>>k;
    cout<<findMin(root, 1, 0)<<endl;*/
    cout<<"Minimum in 0th dimension = "<<findMin(root, 0, 0)<<endl;
    cout<<"Minimum in 1st dimension = "<<findMin(root, 1, 0)<<endl;
    return 0;
}
