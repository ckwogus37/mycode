#include<algorithm>
#include<iostream>
using namespace std;

int W = 16;	//가방의 최대 무게
int n = 4;	// 아이템의 수
int checknode = 0;	// 경로를 탐색하며 생긴 총 노드 수


int weight=0;	//현재 가방의 무게
int profit=0;
int maxprofit=0;
int p[5] = { 0,40,30,50,10 };
int w[5] = { 0,2,5,10,5 };
int bestset[5] = { 0,0,0,0,0 };
int include[5] = { 0,0,0,0,0 };				// PPT에 있는 기본 설정대로 하였습니다.

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
	if (weight <= W && profit > maxprofit) {	//maxprofit값과 아이템 선택상황을 최신화합니다.
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

	cout << "< 최종 0-1knapsack의 선택된 아이템 >" << endl;
	for (int m = 1; m <= n; m++)
		cout << m << "번 아이템 : " << bestset[m]<<endl;

	cout << "\n"<<"최종 가방의 가치 : " << maxprofit << endl;

	cout << "0-1knapsack 실행동안 생긴 노드의 수 : " << checknode<<endl;
}