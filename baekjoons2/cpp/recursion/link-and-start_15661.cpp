#include <iostream>
#include <vector>
#include <algorithm>

int n;
std::vector<std::vector<int>> board(21, std::vector<int>(21, 0));
bool visited[21];
int minSum = 40001;

void link_start(int prev, int cnt) {
	int team1 = 0;
	int team2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (visited[i] && visited[j]) {
				team1 += board[i][j];
				team1 += board[j][i];
			}
			else if (!visited[i] && !visited[j]) {
				team2 += board[i][j];
				team2 += board[j][i];
			}
		}
	}
	minSum = std::min(minSum, std::abs(team1 - team2));

	if (cnt == n / 2) {
		return;
	}
	for (int i = prev; i < n; i++) {
		visited[i] = true;
		link_start(i + 1, cnt + 1);
		visited[i] = false;
	}
}

int main()
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			std::cin >> x;
			board[i][j] = x;
		}
	}
	for (int i = 0; i < n; i++) {
		visited[i] = true;
		link_start(i + 1, 1);
		visited[i] = false;
	}
	std::cout << minSum << "\n";
	return 0;
}