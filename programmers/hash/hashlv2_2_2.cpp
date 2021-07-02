#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	vector<vector<string>> clothes;
	vector<string> cloth[3];
	string element;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<2;j++)
			{
				cin >> element;
				cloth[i].push_back(element);
			}
		clothes.push_back(cloth[i]);
	}
	int count=1;
	int answer=1;
	for(int i = 0; i < clothes.size(); i++)
	{
		swap(clothes[i][0],clothes[i][1]);
	}
	sort(clothes.begin(),clothes.end());
	// cout<<"======================================="<<endl;
	// cout<<clothes[0][0]<<endl;
	// cout<<clothes[0][1]<<endl;
	// cout<<clothes[1][0]<<endl;
	// cout<<clothes[1][1]<<endl;
	// cout<<clothes[2][0]<<endl;
	// cout<<clothes[2][1]<<endl;
	for(int i=0;i<clothes.size();i++)
	{
		if(i==clothes.size()-1)
		{
			++count;
			continue;
		}
		if(clothes[i][0]!=clothes[i+1][0])
		{	
			answer *= ++count;
			count = 1;
		}
		else
		{
			++count;
		}
        
	}
	answer*=count;
    // c.push_back(count+1);
    // for(int j = 0;j< c.size();j++)
    // {
    //     answer*=c[j];
    // }
	cout<< answer << endl;
    return answer-1;
}