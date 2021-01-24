#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int k = 0; // �� i�� j�� ���� C���꿡���� rootnode��



int computationC(int i, int j, int array[][5]) {
	if (array[i][j] >= 0)	// �̹� C(i,j)�� ���Ǿ��ִ��� Ȯ���մϴ�.
		return array[i][j];
	else if (i > j)		// i�� j���� ū ��� 0�� ��ȯ�մϴ�.
		return 0;
	else if (i == j)	// i=j�� ��� ������ ����� ���� ��ȯ�մϴ�.
		return array[i][j];
	else
	{
		int total = 0, compare=10000;	// �� C(i,j)�� total search cost�� �ּڰ��� ã������ �񱳴���Դϴ�.
		for (int p = i; p <= j; p++)
		{
			total = computationC(i, p - 1, array) + computationC(p + 1, j, array);	// i�� j �� ������ �� k�� �̿��Ͽ� C(i,j)���� ���մϴ�.
			if (compare > total)
			{
				compare = total;	// cost���� �ּ��� ��, cost���� �����մϴ�.
				k = p;				// cost�� �ּ��� ��, �� ���� root node�� �����մϴ�.
			}
		}

		int fi = 0;		
		for (int m = i; m <= j; m++)	// i���� j������ f���� ��.
			fi += array[m][m];
		array[i][j] = compare + fi;		// (i,j)�� ���� ���� �־��ݴϴ�.
		return k;
	}
	return 0;
}

void main() {

	int array[5][5] = { {0,0,0,0,0}, {0,3,-1,-1,-1},{0,0,2,-1,-1},{0,0,0,4,-1},{0,0,0,0,1} };
	// PPT�� �ִ� BST�� ���� �����Ͽ����ϴ�.
	int node = 4;	//��ü node�� ��
	int Cresult[5][5] = { 0 }; // �� ������ ���� ���� ������ �����Ͽ��ٰ� ���������� array�� �����մϴ�.



	for (int re = 1; re<=node-1 ; re++)		// j-i�� 1 ���� n-1 �϶� ���� �ݺ��մϴ�.
	{
		for (int i = 1; i <= node; i++)
			for (int j = 1; j <= node; j++)
			{
				if (j - i == re)
					Cresult[i][j] = computationC(i, j, array);	// C(i,j)���� ����� �Ѱ��� �����س����ϴ�.

			}
	}


	cout << "Optaimal Binary Search Result (Array form)" << "\n"<<endl;

	int root = 0;	//�� C(i,j) ���������� root node�� ����ϴµ� ���Ǵ� �����Դϴ�.
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