#include<iostream>
using namespace std;

int vindex[8] = { 1,0,0,0,0,0,0,0 };	//��� ��������� ��� ��ȣ�� �����մϴ�. ����� ù ������ 1�� ����Դϴ�.
int W[9][9] = { 0};	// PPT�� �ִ� �׷����� ������ķ� ǥ���߽��ϴ�.
int checknode = 0;	// ��θ� Ž���ϸ� ���� �� ��� ��

bool promising(int i,int W[][9],int n) {
	int j = 1;
	bool pruning = true;

	if (i == n - 1 && !W[vindex[n - 1]][vindex[0]])
		pruning = false;
	else if (i > 0 && !W[vindex[i - 1]][vindex[i]])
		pruning = false;
	else 
	{
		while (j < i && pruning) 
		{
			if (vindex[i] == vindex[j])
				pruning = false;
			j++;
		}
	}
	return  pruning;
}

void hamiltonian(int i, int W[][9],int n, int w) {
	int j;

	if(promising(i,W,n))
		if (i == n - 1)
		{

			for (int p = 0; p < n; p++)
				cout << vindex[p] << " ";
			cout << endl;
		}
		else
		{
			for (j = 2; j <= n; j++)
			{
				vindex[i + 1] = j;
				checknode++;
				hamiltonian(i + 1, W,n,w);
			}
		}
}

void main() {
	int low=0, col=0;		//W�迭�� ��� �� , �׷����� ��� ���� ������Ȳ�� �Է��ڷκ��� �޽��ϴ�.
	int n;	//�� ��� ����
	int w;	//�� edge ����

	cout << "�� ����� ���� �Է��Ͻÿ� : ";
	cin >> n;
	cout << "�� edge�� ���� �Է��Ͻÿ� : ";
	cin >> w;
	cout << endl;

	cout << "������ �ִ� ��带 �Է��Ͻÿ� "<<endl;
	for (int k = 0; k < w; k++)
	{
		cout << "���� ��� : ";
		cin >> col >> low;
		W[col][low] = 1;
		W[low][col] = 1;
	}
	cout << endl;
	cout << "--------<Hamiltonian Circuits>---------"<<endl;
	hamiltonian(0,W,n,w);
	cout << endl;
	cout << "��θ� Ž���ϸ� ���� �� ����� �� : " << checknode << endl;
}