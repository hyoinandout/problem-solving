#include<iostream>
#include<stack>
using namespace std;
void fn(char *a)   
{    stack <char> s;
    char output[50],t;
    for(int i=0;a[i]!='\0';i++)
    {   char ch = a[i];
        switch(ch)
        {
        case '^':
        case '-': 
        case '+':
        case '/':
        case '*':   s.push(ch);
                    break;
        case ')': t=s.top();
                    s.pop();
                   cout<<t;
                    break;
        }
        if (isalnum(ch))
            cout<<ch;
    }
    t=s.top();
    s.pop();
    cout<<t;
}
int main()
{
    char a[] = "((5+2)*(8-3))/4";
    char b[] = "a+b*c+(d*e+f)*g";
    
    fn(a);
    cout<<endl;
    fn(b);
    return 0;
}