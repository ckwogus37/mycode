#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

int w[6] = { -1,5,6,10,11,16 };		// weight 무게들의 전체집합
int include[6] = { 0 };				// 각 무게들이 subset에 포함되는지 아닌지를 0과 1로 표현합니다.
int n = 6;							// 전체 weight의 개수
int W = 21;							// 자신이 원하는 부분합

bool promising(int i,int weight, int total, int W) {		// 현재 보고있는 weight가 subset에 포함되는데 유망한지 확인하는 함수
	return(weight + total >= W) && (weight == W || weight + w[i + 1] <= W);	
}

void sumofsubset(int i, int weight, int total, int W) {		// 부분합을 만족하는 부분집합을 구하는 함수
	if (promising(i,weight, total,W)) {						// 부분집합에 포함되는지의 유망한지 확인하여 노드 확인 회수를 줄입니다.
		if (weight == W)									// 부분합을 만족시키는 부분집합이면
		{
			cout << "   부분집합 : ";
			cout << "{ ";
			for (int p = 1; p < n; p++)						// include배열을 확인하여 포함되어있는 원소를 찾습니다.
			{
				if (include[p] == 1)
					cout << w[p] <<" ";						// 부분합을 만족시키는 부분집합의 모든 원소들을 출력합니다.
			}
			cout << "}";
			cout << endl;
		}
	
		else {															// 아직 부분합을 만족시키지 않는다면
			include[i + 1] = 1;											// 다음 원소를 포함하며 
			sumofsubset(i + 1, weight + w[i + 1], total - w[i + 1], W);	// 계속하여 부분집합을 구합니다.
			include[i + 1] = 0;											// 다음 원소를 포함하지 않고
			sumofsubset(i + 1, weight, total - w[i + 1], W);			// 계속하여 부분집합을 구합니다.
		}
	}

}

void main() {

	int total = 0;					
	for (int u = 1; u < n; u++)			// 전체집합의 전체 원소의 합인 total을 구합니다.
		total += w[u];
	cout << endl;
	cout << "----부분합 W 를 만족시키는 부분집합들----"<<"\n"<<endl;
	cout << "   전체 집합 : { ";
	for (int k = 1; k < n; k++)
		cout << w[k]<<" ";
	cout << "}" << endl;

	cout << "   부분합 : " << W << endl;

	sumofsubset(0, 0, total, W);		// 부분합을 만족 시키는 부분집합을 구합니다.

}