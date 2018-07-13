#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    vector<node*> v;
};

//printing multi-list.
void print(struct node *l){
    if(l == NULL)
        return;
    queue<node*> q;
    q.push(l);
    q.push(NULL);
    while(!q.empty()){
        l = q.front();
        q.pop();
        while(l != NULL){
            cout<<l->data<<" ";
            for(unsigned int i = 0; i < l->v.size(); i++){
                if(l->v[i])
                    q.push(l->v[i]);
            }
            l = q.front();
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

//add node function is implemented here.
void addNode(struct node *&l, int data){

    if(l == NULL){
        l = new node;
        l->data = data;
    }
    else{
        int flag = 0;
        cout<<"From data = "<<l->data<<endl;
        for(unsigned int i = 0; i < l->v.size(); i++){
            cout<<"Link No. = "<<i + 1<<"\nEnter 1 for choosing the link else enter 0 :-\n";
            cin>>flag;
            if(flag == 1){
                addNode(l->v[i], data);
                return;
            }
        }
        if(flag == 0){
            cout<<data<<" is going to attach the link containing data = "<<l->data<<endl;
            l->v.push_back(NULL);
            addNode(l->v[l->v.size() - 1], data);
        }
    }
    return;
}

int main()
{
    struct node *l = NULL;

    int data = 0;
    while(1){
        cout<<"Enter the data in multi-list :-\n";
        cin>>data;
        if(data == -1)
            break;
        addNode(l, data);
        cout<<"Level Order :-\n";
        print(l);
    }
    return 0;
}
