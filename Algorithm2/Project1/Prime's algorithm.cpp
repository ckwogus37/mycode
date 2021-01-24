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

co_pre *inform = new co_pre[7];	//cost���� ���ϱ� ���� ����ü�迭�Դϴ�.

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

class edge {	//�� vertex�� edge�� cost�� �����ϴ� class�� �����մϴ�.
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

	for (int j = 1; j <= 6; j++)	//�⺻ �ɼ��� �������ݴϴ�.
	{
		inform[j].key = j;			//������ ������ȣ�� �ǹ��մϴ�.
		inform[j].costv = MAX_COST;	//cost(v)
		inform[j].prev = NULL;		//pre(v)
		inform[j].H = j;			//�ʱ� priority queue
	}	
	inform[1].costv = 0;			//ù ��° ������ cost�� 0���� ����
	inform[1].H = 0;				//ù ��° ������ H�� ����
	int minver = 1;					//ù ��° ������ �������� �˰����� �����մϴ�.
	MST[0] = minver;
	//---------------------------------------------------------------------------------------------------------- �⺻����
	cout << minver << "\n";
	int last = -20;		//���� ������ ��
	while (last != 0 )	// last�� ���������� �� ����ü�� H�� ������ ��.
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
			minver = pq.top().key;	//�ּ� cost���� ������ �ǹ��մϴ�.
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
	cout << "MST�� �� cost�� : "<< MSTcost<<"\n";

	

}