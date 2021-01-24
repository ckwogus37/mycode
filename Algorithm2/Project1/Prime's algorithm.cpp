#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;
#define MAX_COST 10000;

struct co_pre {
	int key;
	int costv;
	co_pre* prev;
	int H;
};
typedef struct co_pre co_pre;

co_pre *inform = new co_pre[7];	//cost값을 비교하기 위한 구조체배열입니다.

struct compare {
	bool operator()(co_pre &I, co_pre &C) {
			return I.costv > C.costv;
	}
};
priority_queue<co_pre, vector <co_pre>, compare> pq;

void prim(struct co_pre* inform,int n) {
	for (int i = 1; i <= n; i++)
	{
		if (inform[i].H == 0) {
			inform[i].costv = MAX_COST;
			pq.push(inform[i]);
		}
		else {
		pq.push(inform[i]);
		}
	}

}

class edge {	//두 vertex와 edge의 cost를 저장하는 class를 선언합니다.
public:
	int ver[2];
	int cost;
	edge(int a, int b, int val) {
		ver[0] = a;
		ver[1] = b;
		cost = val;
	}
};


int main() {
	int n = 6;
	int m = 9;
	int MST[6] = { 0 };
	int mstver = 1;
	int MSTcost=0;
	vector<edge> v;

	v.push_back(edge(1, 3, 1));//0
	v.push_back(edge(3, 4, 2));//1
	v.push_back(edge(1, 4, 3));//2
	v.push_back(edge(1, 2, 4));//3
	v.push_back(edge(2, 3, 4));//4
	v.push_back(edge(2, 4, 4));//5
	v.push_back(edge(6, 3, 4));//6
	v.push_back(edge(5, 6, 5));//7
	v.push_back(edge(4, 6, 6));//8

	for (int j = 1; j <= 6; j++)	//기본 옵션을 설정해줍니다.
	{
		inform[j].key = j;			//각각의 정점번호를 의미합니다.
		inform[j].costv = MAX_COST;	//cost(v)
		inform[j].prev = NULL;		//pre(v)
		inform[j].H = j;			//초기 priority queue
	}	
	inform[1].costv = 0;			//첫 번째 정점의 cost를 0으로 설정
	inform[1].H = 0;				//첫 번째 정점의 H를 제거
	int minver = 1;					//첫 번째 정점을 기준으로 알고리즘을 진행합니다.
	MST[0] = minver;
	//---------------------------------------------------------------------------------------------------------- 기본세팅
	cout << minver << "\n";
	int last = -20;		//현재 임의의 값
	while (last != 0 )	// last는 최종적으로 각 구조체의 H의 값들의 합.
	{
	
		for (int i = 0; i < 9; i++) {
			if (v[i].ver[0] == minver)
			{
				if (inform[v[i].ver[1]].H != 0)
				{
					if (inform[(v[i].ver[1])].costv >= v[i].cost)
					{
						inform[(v[i].ver[1])].costv = v[i].cost;
						inform[(v[i].ver[1])].prev = &inform[minver];
					}
				}
			}
			else if (v[i].ver[1] == minver)
			{
				if (inform[v[i].ver[0]].H != 0) 
				{
					if (inform[(v[i].ver[0])].costv >= v[i].cost)
					{
						inform[(v[i].ver[0])].costv = v[i].cost;
						inform[(v[i].ver[0])].prev = &inform[minver];
					}
				}
			}
		}
			prim(inform, n);
			minver = pq.top().key;	//최소 cost값의 정점을 의미합니다.
			MSTcost += pq.top().costv;
			MST[mstver] = minver;
			mstver++;
			cout << minver<<"\n";
			inform[minver].H = 0;
			last += minver;
			while (!pq.empty())
			{
				pq.pop();
			}
	}
	cout << "----------------Greed Algorithm---------------------------\n";
	for (int i = 0; i < 5; i++) 
		cout << "[" << MST[i] << ", " << MST[i + 1] << "]\n";
	cout << "\n";
	cout << "MST의 총 cost값 : "<< MSTcost<<"\n";

	

}