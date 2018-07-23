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

node* minimumNode(struct node* x, struct node *y, int k){
    if(x == NULL && y == NULL)
        return NULL;
    else if(x == NULL)
        return y;
    else if(y == NULL)
        return x;
    else if(x->data[k] > y->data[k]){
        return y;
    }
    return x;
}

node* findMin(struct node *root, int k, int index){
    if(root == NULL)
        return NULL;
    if(index == k){
        if(root->l == NULL)
            return root;
        return minimumNode(root, findMin(root->l, k, (index + 1)%2), index);
    }
    return minimumNode(minimumNode(findMin(root->l, k, (index + 1)%2), findMin(root->r, k, (index + 1)%2), (index + 1)%2) , root, (index + 1)%2);
}

node* maxNode(struct node* x, struct node *y, int k){
    if(x == NULL && y == NULL)
        return NULL;
    else if(x == NULL)
        return y;
    else if(y == NULL)
        return x;
    else if(x->data[k] < y->data[k]){
        return y;
    }
    return x;
}

node* findMax(struct node *root, int k, int index){
    if(root == NULL)
        return NULL;
    if(index == k){
        if(root->r == NULL)
            return root;
        return maxNode(root, findMax(root->r, k, (index + 1)%2), index);
    }
    return maxNode(maxNode(findMax(root->l, k, (index + 1)%2), findMax(root->r, k, (index + 1)%2), (index + 1)%2) , root, (index + 1)%2);
}

node* deletePoint(struct node *root, vector<int> &data, int k){
    if(root == NULL)
        return NULL;
    else if(data[k] < root->data[k])
        root->l = deletePoint(root->l, data, ++k%2);
    else if(data[k] > root->data[k])
        root->r = deletePoint(root->r, data, ++k%2);
    else{
        if(root->l == NULL && root->r == NULL){
            delete root;
            root = NULL;
        }
        else if(root->l != NULL){
            struct node *temp = findMax(root->l, k, (k + 1)%2);
            cout<<temp->data[0]<<"--"<<temp->data[1]<<endl;
            root->data[0] = temp->data[0];
            root->data[1] = temp->data[1];
            root->l = deletePoint(root->l, temp->data, ++k%2);
        }
        else{
            struct node *temp = findMin(root->r, k, (k + 1)%2);
            cout<<temp->data[0]<<" == "<<temp->data[1]<<endl;
            root->data[0] = temp->data[0];
            root->data[1] = temp->data[1];
            root->r = deletePoint(root->r, temp->data, ++k%2);
        }
    }
    return root;
}

int main()
{
    vector<int> data(2,0);
    struct node *root = NULL;
    while(1){
        cout<<"Enter the point in 2-d_Tree :-\n";
        cin>>data[0]>>data[1];
        if(data[0] == -1)
            break;
        addNode(root, data, 0);
        cout<<"Level Order :-\n";
        levelOrder(root);
    }
    cout<<"Level Order :-\n";
    levelOrder(root);
    int givenDimension = 0;
    cout<<"Enter the point to be deleted from 2-d Tree :-\n";
    cin>>data[0]>>data[1];
    root = deletePoint(root, data, 0);//third argument is for knowing the dimension.
    cout<<"Level Order :-\n";
    levelOrder(root);
    return 0;
}
