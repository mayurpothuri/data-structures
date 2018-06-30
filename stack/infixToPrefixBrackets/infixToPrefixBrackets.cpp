#include <bits/stdc++.h>
using namespace std;

//Key point :-
//if the priority is equal then associativity is checked else the order of precedence of checked.
//order of precedence is ^ > / == * > + == -

//Note:-
//Difference between postfix and prefix logic -> In postfix expression, we placed the operator at the right most side of operands
//according to the associativity and precedence rules in our infix to postfix logic.
//In prefix expression, we reverse the logic. By "reverse the logic", what we mean is the placing of operator at left most side
// instead of placing at right most side.
//Now we saw that when scanning the string from left to right, the operator was placed at right side.
//What if we scanned the string from right to left ? Do the operator are placed at the right most side ?
//We then observe that the answer we want can  be then obtained just reversing the result.
//So that's how the logic, "reverse the string, apply the postfix expression, and then again reverse the result"
//came intuitively.
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

string infixToPrefix(string e){

    string result;
    stack<char> s;
    for(int i = e.size() - 1; i >= 0; i--){
        //eliminate whitespace
        if(e[i] == ' ')
        continue;
        // if operand is there then store it in result string
        if((e[i] - '0' >= 0) || (e[i] >= 'a' && e[i] <= 'z') || (e[i] >= 'A' && e[i] <= 'Z'))
            result += e[i];
        else if(e[i] == '('){
            //if the current symbol is ")" then as the stack contains the operator
            //in correct order(associativity and precedence rules), so we pop
            //all the elements till we find the opening bracket "(".
            while(!s.empty() && s.top() != ')'){
                    result += s.top();
                    s.pop();
            }
            s.pop();
        }
        else if(e[i] != ')'){
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
    //popping of all the operators when the entire expression is scanned.
    while(!s.empty()){
        result += s.top();
        s.pop();
    }
    //the obtained result is opposite to the required result.
    //So reverse the result string.
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    //input -> (2*3)-(2+2)/2
    //input --> 1+4-2*3/2
    //input -> ( (A * B) + (C / D) )
    //input -> ((A * (B + C) ) / D)
    //input -> (A * (B + (C / D) ) )
    string expression = "((2*3)-(2+2))/2";
    cout<<"Prefix expression :-\n";
    cout<<infixToPrefix(expression)<<endl;
    return 0;
}
