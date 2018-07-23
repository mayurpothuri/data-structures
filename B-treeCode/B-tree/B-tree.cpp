#include <bits/stdc++.h>
using namespace std;

//in b-tree node:-
//maximum keys that a node can contain is 2*size - 1
//limit for children of node is 2 <= #children <= 2*size

const int size = 5; //degree of node

struct node{
    vector<int> data;
    struct node **p;
    node(){
        this->p = new node*[size + 2]();//(2*size + 2)for given "size", the no. of pointers should be "size + 1".
                                //Here the #pointers are "size + 2" for storing extra node while splitting a node in recursion.
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
            cout<<"\t";
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

void sort(struct node *&root){
    for(int i = root->data.size() - 1; i >= 0; i--){
        int h,key = root->data[i];
        struct node *temp = root->p[i + 1];
        for(h = i; (root->data[h - 1] > key) && (h > 0); h--){
            root->data[h] = root->data[h - 1];
            root->p[h + 1] = root->p[h];
        }
        root->data[h] = key;
        root->p[h + 1] = temp;
    }
    return;
}

node* getParent(struct node *child, struct node *parent){
    if(child == NULL)
        return NULL;
    if(parent == child)
        return parent;
    unsigned int i;
    for(i = 0; i < parent->data.size(); i++){
        if(parent->data[i] > child->data[0])
            break;
    }
    if(parent->p[i] == child)
        return parent;
    return getParent(child, parent->p[i]);
}

void split(struct node *root,struct node *parentOfRoot, struct node *&parent){
    struct node *temp = new node();
    unsigned int mid = (root->data.size()/2) + 1, size = root->data.size();
    //The new node called "temp" will have the right side data part(from mid onwards) and pointers stored.
    temp->data.assign(root->data.begin() + mid, root->data.begin() + size);
    for(unsigned int j = mid; j <= size; j++){
        if(j < size)
            root->data.erase(root->data.begin() + mid);
        temp->p[j - mid] = root->p[j - 1];
        root->p[j - 1] = NULL;
    }
    if(parentOfRoot == root){
        parentOfRoot = new node();
        parentOfRoot->data.push_back(root->data[mid - 1]);
        root->data.erase(root->data.begin() + (mid - 1));
        parentOfRoot->p[0] = root;
        parentOfRoot->p[1] = temp;
        parent = parentOfRoot;
    }
    else{
        parentOfRoot->data.push_back(root->data[mid - 1]);
        root->data.erase(root->data.begin() + (mid - 1));
        parentOfRoot->p[parent->data.size()] = temp;
        sort(parentOfRoot);
        if(parentOfRoot->data.size() == size)//2*size
            split(parentOfRoot, getParent(parentOfRoot, parent), parent);
    }
    return;
}

void addNode(struct node *&root, struct node *&parent, int data){
    if(root->p[0]){
        unsigned int i;
        for(i = 0; i < root->data.size(); i++){
            if(data < root->data[i])
                break;
        }
        addNode(root->p[i], parent, data);
    }
    else{
        root->data.push_back(data);
        sort(root);
        if(root->data.size() == size)//2*size
            split(root, getParent(root, parent), parent);
    }
    return;
}

int main()
{
    struct node *root = new node();
    struct node *parent = root;
    int data = 0;
    while(1){
        cout<<"Enter the data in b-tree :-\n";
        cin>>data;
        if(data == -1)
            break;
        addNode(root, parent, data);
        root = parent;
        cout<<"Level Order :-\n";
        levelOrder(root);
    }
    return 0;
}
