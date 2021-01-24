#include<math.h>
#include<iostream>

using namespace std;

int n = 4;	// ����� �� ����
int m = 3;	// ���� ��
int vcolor[5] = { 0 };	
int W[5][5] = { {0,0,0,0,0}, {0,0,1,1,1},{0,1,0,1,0},{0,1,1,0,1},{0,1,0,1,0} }; // �� ������ ������Ȳ (���� 1������ 4�� ���� �߽��ϴ�)
int checknode = 0;		// ��ĥ�� �ϸ鼭 ���� ������ �� ����� Ȯ���մϴ�.

bool promising(int i) {		// ����� ���� ������ ������Ű���� ������ Ȯ��
	int j = 1;
	bool checkok = true;
	while (j < i && checkok) {		// ���� ���� �������� ��ĥ�ؿ� ��� ������ ��
		if(W[i][j] && vcolor[i] == vcolor[j])	// �� ��尡 ������ �����鼭 ���� ���ٸ�
			checkok = false;			// �������� ����
		j++;
	}
	return checkok;
}

void m_coloring(int i) {
	int color;

	if (promising(i))
	{
		if (i == n)		// ���� ������ ��尡 �ùٸ� ���� ������ ��� ��� ����� ���� ���
		{
			for (int k = 1; k <= n; k++)
				cout << vcolor[k] << " ";
			cout << endl;
			
		}
		else
		{
			for (color = 1; color <= m; color++) {		// ���� ��带 �������� ������忡 ��� ���� ��ĥ�غ��� ������ ������Ű���� ��
				vcolor[i+1] = color;
				checknode++;
				m_coloring(i + 1);

			}
		}
	}

}

void main() {
	cout << "< �� ��忡 �� �� �ִ� �� ���� >" << endl;

	m_coloring(0);			// �� ó�� ������ ��ĥ ����
	cout << endl;
	int timecomplexity = (pow(m, n + 1) - 1) / (m - 1);
	cout << "Backtracking�� ���� ������ ����� �� : " << checknode << endl;		// Backtracking�� ���� ������ �ɸ��� �ð����� �ξ� �پ�� �ð��� ���
	cout << "Graph Coloring�� �ð� ���⵵ T(4,3)�� ���� ���°���Ʈ���� ��ü Node�� �� = " <<timecomplexity << endl;
	
}