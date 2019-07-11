#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

bool Matrix[52][52];
bool Matrix2[52][52];
int N = 0, M = 0;
int ReverseCount = 0;

int ReverseMatrix(int Cn, int Cm)
{
	if (Cn + 2 >= N || Cm + 2 >= M)
	{
		// 더 이상 바꿀 수 없는 곳이면 -1
		return -1;
	}

	for (int i = Cn; i < Cn + 3; ++i)
	{
		for (int j = Cm; j < Cm + 3; ++j)
		{
			Matrix[i][j] = !Matrix[i][j];
		}
	}

	return ReverseCount + 1;
}

int main()
{
	
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			scanf_s("%1d", &Matrix[i][j]);
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			scanf_s("%1d", &Matrix2[i][j]);
		}
	}

	// 바꿔야 할 요소들을 순차적으로 변환
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Matrix[i][j] != Matrix2[i][j])
			{
				ReverseCount = ReverseMatrix(i, j);
				if (ReverseCount == -1)
				{
					printf("%d", ReverseCount);
					return 0;
				}
			}
		}
	}

	printf("%d", ReverseCount);
	return 0;
}