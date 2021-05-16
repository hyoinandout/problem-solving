#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int count(vector<vector<char>> array)
{
	vector<int> counted;
	for(int i=0;i<array.size();i++)
	{
		int count = 1;
		for(int j=0;j<array.size();j++)
		{
			if(array[i][j]==array[i][j+1])
			{
				count++;
			}
			else
			{
				counted.push_back(count);
				count = 1;
			}
		}
	}
	for(int i=0;i<array.size();i++)
	{
		int count = 1;
		for(int j=0;j<array.size();j++)
		{
			if(array[j][i]==array[j+1][i])
			{
				count++;
			}
			else
			{
				counted.push_back(count);
				count = 1;
			}
		}
	}
	return *max_element(counted.begin(),counted.end());
}

int main()
{
	//입력
	int n;
	char color;
	cin>>n;
	vector<vector<char>> board(50);
	for(int i=0;i<n;i++)
	{
		vector<char> row(50);
		for(int j=0;j<n;j++)
		{
			cin>>color;
			row.push_back(color);
		}
		board.push_back(row);
	}
	//스왑경우의수
	vector<vector<vector<char>>> casesboard(50);
	for(int i=0;i<board.size();i++)
	{
		for(int j=0;j<board.size()-1;j++)
		{
			if(board[i][j]!=board[i][j+1])
			{
				//vector<vector<char>> test(board);
				//swap(test[i][j],test[i][j+1]);
				swap(board[i][j],board[i][j+1]);
				casesboard.push_back(board);
			}
		}
	}
	
	for(int i=0;i<board.size();i++)
	{
		for(int j=0;j<board.size()-1;j++)
		{
			if(board[j][i]!=board[j+1][i])
			{
				vector<vector<char>> test(board);
				swap(test[j][i],test[j+1][i]);
				casesboard.push_back(test);
			}
		}
	}
	
	//각 경우의 수에대한 최대개수 중 최대개수
	vector<int> answer;
	for(int i=0;i<casesboard.size();i++)
	{
		answer.push_back(count(casesboard.at(i)));
	}
	cout<<*max_element(answer.begin(),answer.end());
	return 0;
}