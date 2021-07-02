#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int row, column;
	cin>>row;
	cin>>column;
	char board[row][column];
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			cin>>board[i][j];
		}
	}
	
	char Wchessboard[8][8];
	char Bchessboard[8][8];
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if((i+j)%2)
			{
				Wchessboard[i][j]='W';
				Bchessboard[i][j]='B';
			}
			else
			{
				Wchessboard[i][j]='B';
				Bchessboard[i][j]='W';
			}
		}
	}
	
	int countB=0;
	int countW=0;
	int minimum=50;
	for(int i=0;i<row-7;i++)
	{
		for(int j=0;j<column-7;j++)
		{
			for(int k=0;k<8;k++)
			{
				for(int h=0;h<8;h++)
				{
					if(Wchessboard[k][h]!=board[i+k][j+h])
					{
						countW++;
					}
					else if(Bchessboard[k][h]!=board[i+k][j+h])
					{
						countB++;
					}
				}
			}
			if(countW>countB)
			{
				minimum=min(minimum,countB);
			}
			else
			{
				minimum=min(minimum,countW);
			}
			countW=0;
			countB=0;
		}
	}
	cout<<minimum;
}