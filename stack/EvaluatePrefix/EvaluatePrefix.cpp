#include <bits/stdc++.h>
using namespace std;

int evaluate(int x, int y, char test){
    switch(test){
        case '+': return (x + y);
        case '-': return (x - y);
        case '*': return (x * y);
        case '/': return (x / y);
        case '^': return (pow(x,y));
    }
    return -1;
}

//As the prefix expression gives the unambiguous expression, we scan the string char by char and
//whenever an operator is found it is associated with the operators stored in stack(right).
int evaluatePrefix(string e){

    stack<int> s;
    for(int i = e.size() - 1; i >= 0; i--){
        if(e[i] == ' ')
        continue;
        if((e[i] - '0') >= 0)
            s.push(e[i] - '0');
        else{
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            s.push(evaluate(x, y, e[i]));
        }
    }
    return s.top();
}

int main()
{
    //input -> - * 2 3 / + 2 2 2
    //input -> / - * 2 3 + 2 2 2
    string expression = "/ - * 2 3 + 2 2 2";
    cout<<"Evaluated answer :-\n";
    cout<<evaluatePrefix(expression)<<endl;
    return 0;
}
