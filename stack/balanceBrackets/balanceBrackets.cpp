#include <bits/stdc++.h>
using namespace std;

//for every opening brace there should be closing brace of "same type"
bool balanceBrackets(string e){

    stack<char> s;
    for(unsigned int i = 0; i < e.size(); i++){
        if(e[i] == ' ')
        continue;
        if((e[i] == '(') || (e[i] == '{') || (e[i] == '['))
            s.push(e[i]);
        else{
            if(s.empty())
                return false;
            else if(e[i] == ')' && s.top() == '(')
                s.pop();
            else if(e[i] == '}' && s.top() == '{')
                s.pop();
            else if(e[i] == ']' && s.top() == '[')
                s.pop();
            else
                return false;
        }
    }
    if(s.empty())
        return true;
    return false;
}

int main()
{
    //input -> ()
    //input -> {}
    //input -> []
    //input -> ({)}
    //input -> ({)
    //input -> ({})
    //input -> ({}))
    //input -> ){}
    string expression = "){}";
    if(balanceBrackets(expression)){
        cout<<"It is in order :-\n";
    }
    else{
        cout<<"Out of order :-\n";
    }
    return 0;
}
