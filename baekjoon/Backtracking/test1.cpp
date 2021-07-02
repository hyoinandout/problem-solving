#include<iostream>
#include<stack>
using namespace std;

int prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 

bool op(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
	{
		return true;
	}
	else
	{
		return false;
	}
}
string fn(string infix)
{
	stack<char> s;
	string postfix;
	for(int i=0;i<infix.length();i++)
	{
		if(isalnum(infix[i]))
		{
			postfix+=infix[i];
		}
		else if(infix[i] == '(')
		{
			s.push(infix[i]);
		}
		else if(infix[i] == ')')
		{
			while((s.top()!='(') && (!s.empty()))
			{
				char temp=s.top();
				postfix+=temp;
				s.pop();
			}
			if(s.top()=='(')
			{
				s.pop();
			}
		}
		else if(op(infix[i]))
		{
			if(s.empty())
			{
				s.push(infix[i]);
			}
			else
			{
				if(prec(infix[i])>prec(s.top()))
				{
					s.push(infix[i]);
				}	
				else if((prec(infix[i])==prec(s.top()))&&(infix[i]=='^'))
				{
					s.push(infix[i]);
				}
				else
				{
					while((!s.empty())&&(prec(infix[i])<=prec(s.top())))
					{
						postfix+=s.top();
						s.pop();
					}
					s.push(infix[i]);
				}
			}
		}
	}
	while(!s.empty())
	{
		postfix+=s.top();
		s.pop();
	}
	
	return postfix;
}

int main() 
{  

  	string infix_exp1, postfix_exp1;
  	infix_exp1 = "((5+2)*(8-3))/4";
	cout<<infix_exp1<<endl;
  	postfix_exp1 = fn(infix_exp1);
  	cout<<postfix_exp1<<endl;
	  
	string infix_exp2, postfix_exp2;
  	infix_exp2 = "a+b*c+(d*e+f)*g";
	cout<<infix_exp2<<endl;
  	postfix_exp2 = fn(infix_exp2);
  	cout<<postfix_exp2<<endl;
	  
	return 0;
}