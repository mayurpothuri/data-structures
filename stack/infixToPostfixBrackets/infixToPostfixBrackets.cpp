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
        if((e[i] - '0' >= 0) || (e[i] >= 'a' && e[i] <= 'z') || (e[i] >= 'A' && e[i] <= 'Z'))
            result += e[i];
        else if(e[i] == ')'){
            //if the current symbol is ")" then as the stack contains the operator
            //in correct order(associativity and precedence rules), so we pop
            //all the elements till we find the opening bracket "(".
            while(!s.empty() && s.top() != '('){
                    result += s.top();
                    s.pop();
            }
            s.pop();
        }
        else if(e[i] != '('){
            //if the current symbol is not "(" then store the operators
            //in correct order in stack normally.
            while(!s.empty() && precedence(e[i]) <= precedence(s.top())){
                result += s.top();
                s.pop();
            }
            s.push(e[i]);
        }
        else{
            //this case comes only when current symbol is opening bracket "("
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
    //input -> (2*3)-(1+2)/2
    //input --> 1+4-2*3/2
    //input -> ( (A * B) + (C / D) )
    //input -> ((A * (B + C) ) / D)
    //input -> (A * (B + (C / D) ) )
    string expression = "(2*3)-(2+2)/2";
    //getline(cin, expression);
    cout<<"Postfix expression :-\n";
    cout<<infixToPostfix(expression)<<endl;
    return 0;
}
