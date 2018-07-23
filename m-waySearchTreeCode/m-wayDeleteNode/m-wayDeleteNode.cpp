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

node* findMax(struct node *root){
    if(root == NULL)
        return NULL;
    else if(root->p[root->data.size()] == NULL)
        return root;
    return findMax(root->p[root->data.size()]);
}

node* deleteNode(struct node *root, int data){
    if(root == NULL)
        return NULL;
    else{
        unsigned int i,f = 0;
        for(i = 0; i < root->data.size(); i++){
            if(root->data[i] == data){
                //this data is to be deleted
                if(root->data.size() == 1 && root->p[i] == NULL && root->p[i + 1] == NULL){
                    delete root;f = 1;
                    root = NULL;break;
                }
                else if(root->data.size() == 1 && root->p[i] != NULL){
                    struct node *temp = root;
                    root = root->p[i];f = 1;
                    delete temp;break;
                }
                else if(root->data.size() == 1 && root->p[i + 1] != NULL){
                    struct node *temp = root;
                    root = root->p[i + 1];f = 1;
                    delete temp;break;
                }
                else if(root->p[i] == NULL && root->p[i + 1] == NULL){
                    for(unsigned int j = i + 2; j <= root->data.size(); j++)
                        root->p[j - 1] = root->p[j];
                    root->data.erase(root->data.begin() + i);
                    f = 1;
                    break;
                }
                else if(root->p[i] == NULL || root->p[i + 1] == NULL){
                    unsigned int j;
                    if(root->p[i] == NULL)
                        j = i + 1;
                    else
                        j = i + 2;
                    for(; j <= root->data.size(); j++)
                        root->p[j - 1] = root->p[j];
                    root->data.erase(root->data.begin() + i);f = 1;
                    break;
                }
                else{
                    struct node *temp = findMax(root->p[i]);
                    root->data[i] = temp->data[temp->data.size() - 1];
                    root->p[i] = deleteNode(root->p[i], temp->data[temp->data.size() - 1]);f = 1;
                    break;
                }
            }
            else if(data < root->data[i]){
                root->p[i] = deleteNode(root->p[i], data);
                f = 1;
                break;
            }
        }
        if(f == 0)
            root->p[i] = deleteNode(root->p[i], data);
    }
    return root;
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
    while(1){
        cout<<"Level Order :-\n";
        levelOrder(root);
        cout<<"Enter the data to be deleted :-\n";
        cin>>data;
        if(data == -1)
            break;
        root = deleteNode(root, data);
    }
    cout<<"Level Order :-\n";
    levelOrder(root);
    return 0;
}
