#include<iostream>
using namespace std;

int vindex[8] = { 1,0,0,0,0,0,0,0 };	//경로 순서대로의 노드 번호를 저장합니다. 경로의 첫 시작은 1번 노드입니다.
int W[9][9] = { 0};	// PPT에 있는 그래프를 인접행렬로 표현했습니다.
int checknode = 0;	// 경로를 탐색하며 생긴 총 노드 수

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
	int low=0, col=0;		//W배열의 행과 열 , 그래프의 노드 간의 인접상황을 입력자로부터 받습니다.
	int n;	//총 노드 개수
	int w;	//총 edge 개수

	cout << "총 노드의 수를 입력하시오 : ";
	cin >> n;
	cout << "총 edge의 수를 입력하시오 : ";
	cin >> w;
	cout << endl;

	cout << "인접해 있는 노드를 입력하시오 "<<endl;
	for (int k = 0; k < w; k++)
	{
		cout << "인접 노드 : ";
		cin >> col >> low;
		W[col][low] = 1;
		W[low][col] = 1;
	}
	cout << endl;
	cout << "--------<Hamiltonian Circuits>---------"<<endl;
	hamiltonian(0,W,n,w);
	cout << endl;
	cout << "경로를 탐색하며 생긴 총 노드의 수 : " << checknode << endl;
}