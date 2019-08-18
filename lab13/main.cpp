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

        switch (expr[i])
        {
        case ')':

            // Store the top element in a
            x = s.Top();
            s.Pop();
            if (x=='{' || x=='[')
                return false;
            break;

        case '}':

            // Store the top element in b
            x = s.Top();
            s.Pop();
            if (x=='(' || x=='[')
                return false;
            break;

        case ']':

            // Store the top element in c
            x = s.Top();
            s.Pop();
            if (x =='(' || x == '{')
                return false;
            break;
        }
    }

    // Check Empty Stack
    return (s.IsEmpty());
}

// Driver program to test above function
int main()
{
    string expr = "{()}[]";

    if (areParanthesisBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}
