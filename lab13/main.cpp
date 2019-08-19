#include <iostream>
#include "stacktype.cpp"


using namespace std;


bool areParanthesisBalanced(string expr)
{

    StackType <char> s;
    char x;


    // Traversing the Expression
    for (int i=0; i<expr.length(); i++)
    {
        if (expr[i]=='('||expr[i]=='['||expr[i]=='{')
        {
            // Push the element in the stack
            s.Push(expr[i]);
            continue;
        }

        // IF current current character is not opening
        // bracket, then it must be closing. So stack
        // cannot be empty at this point.
        if (s.IsEmpty())
           return false;

//
//        if (expr[i]==')' )
//        {
//            if (s.Top()=='(')
//                s.Pop();
////            else
////                s.Push(expr[i]);
//        }
//
//    }
//    }
        switch (expr[i])
        {
        case ')':

            // Store the top element in a
            x = s.Top();
            s.Pop();
            if (x=='{' || x=='[')

                return (expr[')']);
            break;
           // s.Push(expr[')']);

        case '}':


            // Store the top element in b
            x = s.Top();
            s.Pop();
            if (x=='(' || x=='[')

                return (expr['}']);
            break;
           // s.Push(expr['}']);

        case ']':

            // Store the top element in c
            x = s.Top();
            s.Pop();
            if (x =='(' || x == '{')

                return(expr[']']);
            break;
            //s.Push(expr[']']);
        }
    }
//stack<char> s;
//    for (int i=0; i<len; i++)
//    {
//        if (expr[i]=='}' && !s.empty())
//        {
//            if (s.top()=='{')
//                s.pop();
//            else
//                s.push(expr[i]);
//        }
//        else
//            s.push(expr[i]);
//    }
    // Check Empty Stack
    return (s.IsEmpty());
}

// Driver program to test above function
int main()
{
    string expr = "{({())}[]";
//int s.Pop(expr[i]);

    if (areParanthesisBalanced(expr))
        cout << "the Balanced expression is "<<expr;
    else
        cout << "the Not Balanced expression is "<<expr;
    return 0;
}
