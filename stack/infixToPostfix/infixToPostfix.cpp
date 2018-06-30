#include <bits/stdc++.h>
using namespace std;

//Key point :-
//if the priority is equal then associativity is checked else the order of precedence of checked.
//order of precedence is ^ > / == * > + == -
int precedence(char test){
    switch(test){
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '^': return 3;
    }
    return -1;
}

string infixToPostfix(string e){
    string result;
    stack<char> s;
    for(unsigned int i = 0; i < e.size(); i++){
        //eliminate whitespace
        if(e[i] == ' ')
        continue;
        // if operand is there then store it in result string
        if((e[i] - '0' >= 0) || (e[i] >= 'a' && e[i] <= 'z'))
            result += e[i];
        else{
            //if operator is present then check against the operators present/or not present in stack.
            while(!s.empty() && precedence(e[i]) <= precedence(s.top())){
                result += s.top();
                s.pop();
            }
            s.push(e[i]);
        }
    }
    while(!s.empty()){
        result += s.top();
        s.pop();
    }
    return result;
}

int main()
{
    //input --> 1+4-2*3/2
    //input -> A * B + C / D
    //input -> A * B + C / D
    //input -> A * B + C / D
    string expression;
    cout<<"Enter the infix expression :-\n";
    getline(cin, expression);
    cout<<"Postfix Expression :-\n";
    cout<<infixToPostfix(expression)<<endl;
    return 0;
}
