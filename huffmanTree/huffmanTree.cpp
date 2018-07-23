#include <bits/stdc++.h>
#include<string>
using namespace std;

struct node{
    int f;
    char character;
    struct node *l,*r;
    node(int f){
        this->f = f;
        this->l = this->r = NULL;
    }
    node(int f, char character){
        this->f = f;
        this->character = character;
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
            cout<<root->f<<" "<<root->character<<"_";
            if(root->l)
                q.push(root->l);
            if(root->r)
                q.push(root->r);
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

void displayEncoding(struct node *root, string &s){
    if(root == NULL)
        return;
    if(root->l == NULL && root->r == NULL){
        cout<<s<<" ";
        cout<<" -> "<<root->character<<endl;
        return;
    }
    s.push_back('0');
    displayEncoding(root->l,s);
    s.erase(s.end() - 1);
    s.push_back('1');
    displayEncoding(root->r,s);
    s.erase(s.end() - 1);
    return;
}

void decodeDisplay(struct node *root, struct node *temp, string &str){
    if(root == NULL)
        return;
    if(root->l == NULL && root->r == NULL){
        cout<<root->character;
        return;
    }
    while(!str.empty()){
        if(*str.begin() == '0'){
            str.erase(str.begin());
            decodeDisplay(root->l,temp,str);
            if(root != temp)
                break;
        }
        else{
            str.erase(str.begin());
            decodeDisplay(root->r,temp,str);
            if(root != temp)
                break;
        }
    }
    return;
}

map<int,vector<char> >::iterator checkVectorInMap(map<int, vector<char> > &m, map<int, vector<char> >::iterator &it){
    it->second.erase(it->second.begin());
    if(it->second.empty()){
        m.erase(it);
        it = m.begin();
    }
    return it;
}

void createHuffmanTree(map<int, vector<char> > &m, struct node *&root){
    if(m.empty())
        return;
    map<int, vector<char> >::iterator it = m.begin();
    if(root == NULL){
        struct node *temp1 = new node(it->first, *(it->second.begin()));
        it = checkVectorInMap(m,it);
        struct node *temp2 = new node(it->first, *(it->second.begin()));
        it = checkVectorInMap(m, it);
        root = new node(temp1->f + temp2->f, '*');
        root->l = temp1;
        root->r = temp2;
        createHuffmanTree(m, root);
    }
    else if(it->first < root->f){
        struct node *temp1 = new node(it->first, *(it->second.begin()));
        it = checkVectorInMap(m, it);
        struct node *temp2 = new node(root->f + temp1->f, '*');
        temp2->l = temp1;
        temp2->r = root;
        root = temp2;
        createHuffmanTree(m, root);
    }
    else{
        struct node *temp1 = new node(it->first, *(it->second.begin()));
        it = checkVectorInMap(m, it);
        struct node *temp2 = new node(root->f + temp1->f, '*');
        temp2->l = root;
        temp2->r = temp1;;
        root = temp2;
        createHuffmanTree(m, root);
    }
    return;
}

int main()
{
    int f = 0;
    char character;
    struct node *root = NULL;
    map<int, vector<char> > m;
    while(1){
        cout<<"Enter the frequency and character you want in tree :-\n";
        cin>>f;
        if(f == -1)
            break;
        cin>>character;
        m[f].push_back(character);
    }
    createHuffmanTree(m,root);
    string s;
    cout<<"Decoding :-\n";
    displayEncoding(root, s);
    cout<<"Enter the encoded binary data :-\n";
    cin>>s;
    struct node *temp = root;
    decodeDisplay(root, temp, s);
    return 0;
}
