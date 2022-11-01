#include <iostream>
#include <queue>
#include <string>
#include "TwoQueueStack.hpp"
#include "TwoStackQueue.hpp"
using namespace std;
///----------------------------------------------
void task1(int n)
{
	///n = 4
	///Ivan Borislavov Borissov 4MI0800058
	TwoQueueStack<string>StudentID;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		StudentID.push(s);
	}
	while (!StudentID.empty())
	{
		cout << StudentID.top() << " ";
		StudentID.pop();
	}
	///4MI0800058 Borissov Borislavov Ivan
}
///----------------------------------------------
void task2(int n)
{
	/*TwoStackQueue<string>StudentID;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		StudentID.push(s);
	}
	while (!StudentID.empty())
	{
		cout << StudentID.front() << " ";
		StudentID.pop();
	}
	*/
}
///----------------------------------------------
void task3()
{
	return;
}
///----------------------------------------------
void task4(int n)
{
	queue<string>binaryNums;
	binaryNums.push("1");
	while (n)
	{
		string currNum = binaryNums.front();

		cout << currNum << " ";

		currNum = currNum + "0";
		binaryNums.push(currNum);
		currNum = binaryNums.front() + "1";
		binaryNums.push(currNum);

		binaryNums.pop();
		n--;
	}
	cout << endl;
}
///----------------------------------------------
void task5(int n, int k)
{
	queue<int>players;

	for (int i = 1; i <= n; i++)
	{
		players.push(i);
	}

	int tempK = k;
	while (players.size() > 1)
	{
		if (tempK == 1)
		{
			tempK = k;
			//cout << players.front() << endl;
			players.pop();
		}
		players.push(players.front());
		players.pop();
		tempK--;
	}
	cout << players.front() << endl;
}
///----------------------------------------------
void task6(vector<int>& nums, int k)
{
	return;
}
///----------------------------------------------
void init(int used[][128], int n, int m, int arr[][128])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0)
				used[i][j] = 1;
			else
				used[i][j] = 0;
		}
	}
}

void task7(int arr[][128], const int n, const int m, int startX, int startY, int finishX, int finishY)
{
	int directions[2][4] = {{-1, 1, 0, 0},
							{ 0, 0, -1, 1 }};

	int used[128][128];
	init(used, n, m, arr);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << used[i][j] << " ";
		}
		cout << endl;
	}

	queue<pair<int, int> >q;

	q.push( { startX, startY } );
	used[startX][startY] = 1;

	while (!q.empty())
	{
		pair<int, int>curr = q.front();
		q.pop();

		int x, y;
		for (int i = 0; i < 4; i++)
		{
			x = curr.first + directions[0][i];
			y = curr.second + directions[1][i];

			if (used[x][y] == 0)
			{
				q.push(make_pair(x,y));
				used[x][y] = used[curr.first][curr.second] + 1;

				if (x == finishX && y == finishY)
				{
					cout << used[x][y] - 1 << endl;
					return;
				}
			}
		}
	}
}
///----------------------------------------------
int main()
{
	/*int n;
	cin >> n;
	task1(n);
	*/
	
	/*int n;
	cin >> n;
	task2(n);*/

	/*int n;
	cin >> n;
	task4(n);
	*/

	/*int n, k;
	cin >> n >> k;
	task5(n,k);
	*/

	/*int n, m, startx, starty, finishx, finishy, arr[128][128];
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cin >> startx >> starty;
	cin >> finishx >> finishy;

	task7(arr, n, m, startx, starty, finishx, finishy);
	*/

	return 0;
}
/*
10 10
1 1 1 1 1 0 0 1 1 1
0 1 1 1 1 1 0 1 0 1
0 0 1 0 1 1 1 0 0 1
1 0 1 1 1 0 1 1 0 1
0 0 0 1 0 0 0 1 0 1
1 0 1 1 1 0 0 1 1 0
0 0 0 0 1 0 0 1 0 1
0 1 1 1 1 1 1 1 0 0
1 1 1 1 1 0 0 1 1 1
0 0 1 0 0 1 1 0 0 1

0 0
7 5
*/