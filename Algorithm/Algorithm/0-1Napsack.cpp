#include<algorithm>
#include<iostream>
using namespace std;

int W = 16;	//������ �ִ� ����
int n = 4;	// �������� ��
int checknode = 0;	// ��θ� Ž���ϸ� ���� �� ��� ��


int weight=0;	//���� ������ ����
int profit=0;
int maxprofit=0;
int p[5] = { 0,40,30,50,10 };
int w[5] = { 0,2,5,10,5 };
int bestset[5] = { 0,0,0,0,0 };
int include[5] = { 0,0,0,0,0 };				// PPT�� �ִ� �⺻ ������� �Ͽ����ϴ�.

bool promising(int i,int profit, int weight) {
	int j, k;
	int totweight;
	float bound;
	if (weight >= W)
		return false;
	else {
		j = i + 1;
		bound = profit;
		totweight = weight;
		while ((j <= n) && (totweight + w[j] <= W)) {
			totweight = totweight + w[j];
			bound = bound + p[j];
			j++;
		}
	}
	k = j;
	if (k <= n)
		bound = bound + ((W - totweight) * (p[k] / w[k]));
	return bound > maxprofit;
}

void knapsack(int i, int profit, int weight) {
	if (weight <= W && profit > maxprofit) {	//maxprofit���� ������ ���û�Ȳ�� �ֽ�ȭ�մϴ�.
		maxprofit = profit;
		copy(include, include + 5, bestset);
	}
	if (promising(i,profit, weight)) {
		include[i + 1] = 1;
		checknode++;
		knapsack(i + 1, profit + p[i + 1], weight + w[i + 1]);
		include[i + 1] = 0;
		checknode++;
		knapsack(i + 1, profit, weight);
	}
}

void main() {

	knapsack(0, 0, 0);

	cout << "< ���� 0-1knapsack�� ���õ� ������ >" << endl;
	for (int m = 1; m <= n; m++)
		cout << m << "�� ������ : " << bestset[m]<<endl;

	cout << "\n"<<"���� ������ ��ġ : " << maxprofit << endl;

	cout << "0-1knapsack ���ൿ�� ���� ����� �� : " << checknode<<endl;
}