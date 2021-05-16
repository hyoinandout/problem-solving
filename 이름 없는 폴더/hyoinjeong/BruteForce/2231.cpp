#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX_NUM 1000000

int func(int n)
{
	int sum=0;
	string str = to_string(n);
	vector<int> element;
	for(int i=0;i<str.length();i++)
	{
		element.push_back(stoi(str[i]));
		sum+= element[i];
	}
	//cout<<sum<<endl;
	return sum+n;
}

int main()
{
	int n, z, x=1;
	cin>>n;	
	
	while(1)
	{
		z=func(x);
		if(n==z)
		{
			cout<<x<<endl;
			break;
		}
		else if(x>MAX_NUM)
		{
			cout<<0<<endl;
			break;
		}
		x++;
	}
	return 0;
}
//stoi는 어떨까?
//범위변경: 최솟값과 최댓값