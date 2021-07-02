<<<<<<< HEAD
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
// 잘못 생각했다 ㅠㅠ
// bool cmp(const pair<int,int>& a,const pair<int,int>& b)
// {
// 	if(a.second==b.second) return a.first<b.first;
// 	return a.second > b.second
// }
//처음에 플러그 꽉찰때까지 쓰였던 것들 중 후에 많이 쓰이는거를 판별해서(--) 적게 쓰이는거 부터 떼주고, 빈도수같으면 후 index부터 때준다.
int main()
{
	int N,K;
	cin>>N>>K;
	int sequence[K];  
	map<int,int> m1;
	int temp =N;
	for(int i=0;i<K;i++)
	{
		cin>>sequence[i];
		m1[sequence[i]]++;
		// if(m1.size()==temp)
		// {
		// 	map<int> m2(m1);//m2는 N개까지의 우선순위 map
		// 	temp = 0;
		// }
	}
	
	
	// vector<pair<int,int>> vec1(m1.begin(),m1.end());
	// sort(vec1.begin(),vec1.end(),cmp);
	
	// vector<pair<int,int>> vec2(m2.begin(),m2.end());
	// sort(vec2.begin(),vec2.end(),cmp);
	
	int count=0;
	// int tab[N];
	vector<int>::iterator iter;
	// for(int k=0;k<N;k++)
	// {
	// 	tab[k]=m2[k].first;
	// }
	for(int j=0;j<K;j++)
	{
		m1[sequence[j]]--;
		iter = find(vec2.begin(),vec2.end(),sequence[j]);
		if(m2.size()>N)
		{
			
		}
		
		//쓰면 사용횟수에서 -1씩 해줘서 우선순위 정하고, 같을때 그냥 아무거나 빼주면됨	
	}
}
=======
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
// 잘못 생각했다 ㅠㅠ
// bool cmp(const pair<int,int>& a,const pair<int,int>& b)
// {
// 	if(a.second==b.second) return a.first<b.first;
// 	return a.second > b.second
// }
//처음에 플러그 꽉찰때까지 쓰였던 것들 중 후에 많이 쓰이는거를 판별해서(--) 적게 쓰이는거 부터 떼주고, 빈도수같으면 후 index부터 때준다.
int main()
{
	int N,K;
	cin>>N>>K;
	int sequence[K];
	map<int,int> m1;
	int temp =N;
	for(int i=0;i<K;i++)
	{
		cin>>sequence[i];
		m1[sequence[i]]++;
		// if(m1.size()==temp)
		// {
		// 	map<int> m2(m1);//m2는 N개까지의 우선순위 map
		// 	temp = 0;
		// }
	}
	
	
	// vector<pair<int,int>> vec1(m1.begin(),m1.end());
	// sort(vec1.begin(),vec1.end(),cmp);
	
	// vector<pair<int,int>> vec2(m2.begin(),m2.end());
	// sort(vec2.begin(),vec2.end(),cmp);
	
	int count=0;
	// int tab[N];
	vector<int>::iterator iter;
	// for(int k=0;k<N;k++)
	// {
	// 	tab[k]=m2[k].first;
	// }
	for(int j=0;j<K;j++)
	{
		m1[sequence[j]]--;
		iter = find(vec2.begin(),vec2.end(),sequence[j]);
		if(m2.size()>N)
		{
			
		}
		
		//쓰면 사용횟수에서 -1씩 해줘서 우선순위 정하고, 같을때 그냥 아무거나 빼주면됨	
	}
}
>>>>>>> 882d5feaba4d55e11e9dac0726a60737826541e0
