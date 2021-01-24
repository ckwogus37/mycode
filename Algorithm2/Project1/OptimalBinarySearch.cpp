#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int k = 0; // 각 i와 j에 대한 C연산에서의 rootnode값



int computationC(int i, int j, int array[][5]) {
	if (array[i][j] >= 0)	// 이미 C(i,j)가 계산되어있는지 확인합니다.
		return array[i][j];
	else if (i > j)		// i가 j보다 큰 경우 0을 반환합니다.
		return 0;
	else if (i == j)	// i=j인 경우 기존에 저장된 값을 반환합니다.
		return array[i][j];
	else
	{
		int total = 0, compare=10000;	// 각 C(i,j)의 total search cost의 최솟값을 찾기위한 비교대상입니다.
		for (int p = i; p <= j; p++)
		{
			total = computationC(i, p - 1, array) + computationC(p + 1, j, array);	// i와 j 그 사이의 값 k를 이용하여 C(i,j)값을 구합니다.
			if (compare > total)
			{
				compare = total;	// cost값이 최소일 때, cost값을 저장합니다.
				k = p;				// cost가 최소일 때, 그 때의 root node를 저장합니다.
			}
		}

		int fi = 0;		
		for (int m = i; m <= j; m++)	// i부터 j까지의 f값의 합.
			fi += array[m][m];
		array[i][j] = compare + fi;		// (i,j)에 최종 값을 넣어줍니다.
		return k;
	}
	return 0;
}

void main() {

	int array[5][5] = { {0,0,0,0,0}, {0,3,-1,-1,-1},{0,0,2,-1,-1},{0,0,0,4,-1},{0,0,0,0,1} };
	// PPT에 있는 BST와 같게 설정하였습니다.
	int node = 4;	//전체 node의 값
	int Cresult[5][5] = { 0 }; // 각 연산을 통해 나온 값들을 저장하였다가 최종적으로 array에 저장합니다.



	for (int re = 1; re<=node-1 ; re++)		// j-i가 1 부터 n-1 일때 까지 반복합니다.
	{
		for (int i = 1; i <= node; i++)
			for (int j = 1; j <= node; j++)
			{
				if (j - i == re)
					Cresult[i][j] = computationC(i, j, array);	// C(i,j)값의 결과를 한곳에 저장해놓습니다.

			}
	}


	cout << "Optaimal Binary Search Result (Array form)" << "\n"<<endl;

	int root = 0;	//각 C(i,j) 계산과정에서 root node를 출력하는데 사용되는 변수입니다.
	for (int row = 1; row <= 4; row++)
	{
		for (int col = 1; col <= 4; col++)
		{
			if (row < col)
			{
				cout << " "<<array[row][col] << "(";
				cout << Cresult[row][col] << ") ";
			}
			else cout << " "<<array[row][col]<<"     ";
		}
		cout << endl;
	}

}