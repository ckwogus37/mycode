#include<math.h>
#include<iostream>

using namespace std;

int n = 4;	// 노드의 총 개수
int m = 3;	// 색의 수
int vcolor[5] = { 0 };	
int W[5][5] = { {0,0,0,0,0}, {0,0,1,1,1},{0,1,0,1,0},{0,1,1,0,1},{0,1,0,1,0} }; // 각 노드들의 인접상황 (노드는 1번부터 4번 노드로 했습니다)
int checknode = 0;		// 색칠을 하면서 생긴 노드들이 총 몇개인지 확인합니다.

bool promising(int i) {		// 노드의 색이 조건을 충족시키는지 유망성 확인
	int j = 1;
	bool checkok = true;
	while (j < i && checkok) {		// 현재 노드와 이전까지 색칠해온 모든 노드들을 비교
		if(W[i][j] && vcolor[i] == vcolor[j])	// 두 노드가 인접해 있으면서 색이 같다면
			checkok = false;			// 유망하지 않음
		j++;
	}
	return checkok;
}

void m_coloring(int i) {
	int color;

	if (promising(i))
	{
		if (i == n)		// 제일 마지막 노드가 올바른 색을 가졌을 경우 모든 노드의 색을 출력
		{
			for (int k = 1; k <= n; k++)
				cout << vcolor[k] << " ";
			cout << endl;
			
		}
		else
		{
			for (color = 1; color <= m; color++) {		// 현재 노드를 기준으로 다음노드에 모든 색을 색칠해보며 조건을 충족시키는지 비교
				vcolor[i+1] = color;
				checknode++;
				m_coloring(i + 1);

			}
		}
	}

}

void main() {
	cout << "< 각 노드에 들어갈 수 있는 색 패턴 >" << endl;

	m_coloring(0);			// 맨 처음 노드부터 색칠 시작
	cout << endl;
	int timecomplexity = (pow(m, n + 1) - 1) / (m - 1);
	cout << "Backtracking을 통해 생성된 노드의 수 : " << checknode << endl;		// Backtracking을 통해 기존에 걸리던 시간보다 훨씬 줄어든 시간을 출력
	cout << "Graph Coloring의 시간 복잡도 T(4,3)에 따른 상태공간트리의 전체 Node의 수 = " <<timecomplexity << endl;
	
}