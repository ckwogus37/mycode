#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

int w[6] = { -1,5,6,10,11,16 };		// weight ���Ե��� ��ü����
int include[6] = { 0 };				// �� ���Ե��� subset�� ���ԵǴ��� �ƴ����� 0�� 1�� ǥ���մϴ�.
int n = 6;							// ��ü weight�� ����
int W = 21;							// �ڽ��� ���ϴ� �κ���

bool promising(int i,int weight, int total, int W) {		// ���� �����ִ� weight�� subset�� ���ԵǴµ� �������� Ȯ���ϴ� �Լ�
	return(weight + total >= W) && (weight == W || weight + w[i + 1] <= W);	
}

void sumofsubset(int i, int weight, int total, int W) {		// �κ����� �����ϴ� �κ������� ���ϴ� �Լ�
	if (promising(i,weight, total,W)) {						// �κ����տ� ���ԵǴ����� �������� Ȯ���Ͽ� ��� Ȯ�� ȸ���� ���Դϴ�.
		if (weight == W)									// �κ����� ������Ű�� �κ������̸�
		{
			cout << "   �κ����� : ";
			cout << "{ ";
			for (int p = 1; p < n; p++)						// include�迭�� Ȯ���Ͽ� ���ԵǾ��ִ� ���Ҹ� ã���ϴ�.
			{
				if (include[p] == 1)
					cout << w[p] <<" ";						// �κ����� ������Ű�� �κ������� ��� ���ҵ��� ����մϴ�.
			}
			cout << "}";
			cout << endl;
		}
	
		else {															// ���� �κ����� ������Ű�� �ʴ´ٸ�
			include[i + 1] = 1;											// ���� ���Ҹ� �����ϸ� 
			sumofsubset(i + 1, weight + w[i + 1], total - w[i + 1], W);	// ����Ͽ� �κ������� ���մϴ�.
			include[i + 1] = 0;											// ���� ���Ҹ� �������� �ʰ�
			sumofsubset(i + 1, weight, total - w[i + 1], W);			// ����Ͽ� �κ������� ���մϴ�.
		}
	}

}

void main() {

	int total = 0;					
	for (int u = 1; u < n; u++)			// ��ü������ ��ü ������ ���� total�� ���մϴ�.
		total += w[u];
	cout << endl;
	cout << "----�κ��� W �� ������Ű�� �κ����յ�----"<<"\n"<<endl;
	cout << "   ��ü ���� : { ";
	for (int k = 1; k < n; k++)
		cout << w[k]<<" ";
	cout << "}" << endl;

	cout << "   �κ��� : " << W << endl;

	sumofsubset(0, 0, total, W);		// �κ����� ���� ��Ű�� �κ������� ���մϴ�.

}