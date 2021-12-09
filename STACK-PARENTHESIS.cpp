#include <iostream>
#define SIZE 50  

using namespace std;
       

class Stack
{
    char s[SIZE];
    int top;
    public:
        Stack()
        {
            top=-1;
        }
        void push(char ch);
        char pop();
        bool isEmpty();
        bool isFull();
        bool check_Para(char para[]);
};

bool Stack::isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

bool Stack::isFull()
{
    if(top==SIZE-1)
        return 1;
    else
        return 0;
}

void Stack::push(char ch)
{
    if(!isFull())
    {
        top++;
        s[top]=ch;
    }
}

char Stack::pop()
{
    if(!isEmpty())
    {
        char ch=s[top];
        top--;
        return ch;
    }
    

}

bool Stack::check_Para(char para[])
{
    char x;
 
    for (int i=0; para[i]!='\0' ; i++)   //para[i]!='\0' for  character end 
    {
        if (para[i]=='('or para[i]=='['or para[i]=='{')
        {
           
            push(para[i]);
            continue;
        }
 
        
        if (isEmpty())
           return false;
 
        switch (para[i])
        {
        case ')':
 
            
            x = pop();
            if (x=='{' or x=='[')
                return false;
            break;
 
        case '}':
 
            
            x = pop();
           
            if (x=='(' or x=='[')
                return false;
            break;
 
        case ']':
 
            
            x = pop();
            
            if (x =='(' or x == '{')
                return false;
            break;
        }
    }
 
    return (isEmpty());
}
 


int main()
{    
    char para[50];
    int i=0,k=0;
    Stack exp;
    cout<<"\n Enter  Expression: ";
    cin>>para;
    if (exp.check_Para(para))
        cout << "given expression is well parenthesized";
    else
        cout << "given expression is not well parenthesized";

    return 0;
}
