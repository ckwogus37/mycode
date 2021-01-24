#include<iostream>
#include<vector>

using namespace std;

class edge {	//�� vertex�� edge�� cost�� �����ϴ� class�� �����մϴ�.
public:
	int vertex[2];
	int cost;
	edge(int a, int b, int lo) {
		vertex[0] = a;
		vertex[1] = b;
		cost = lo;
	}
};
int find(int root[], int x) {	//vertex�� root node�� �����ɴϴ�.
	if (root[x] == x)
		return x;
	else find(root, root[x]);	//��������� root node�� ã���ϴ�.
}
int unionvertex(int root[], int x, int y) {
	int a = find(root, x);
	int b = find(root, y);
	root[a] = b; //�� root�� �����ݴϴ�.
	return b;
}

int main() {
	int n = 6;
	int m = 9;
	int parent[7] = { 0 };
	int sum = 0;
	int T[10] = { 0 };
	int t = 0;
	int countedge = 0;
	vector<edge> v;

	v.push_back(edge(1, 3, 1)); //edge�� cost���� ó������ ������������ �����Ͽ����ϴ�.
	v.push_back(edge(3, 4, 2));
	v.push_back(edge(1, 4, 3));
	v.push_back(edge(1, 2, 4));
	v.push_back(edge(2, 3, 4));
	v.push_back(edge(2, 4, 4));
	v.push_back(edge(6, 3, 4));
	v.push_back(edge(5, 6, 5));
	v.push_back(edge(4, 6, 6));

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for (int j = 0; j < v.size(); j++)
	{
		if (countedge == n - 1) //Tree�� ���ǿ� ���� ������ ���� �����Ǹ� �˰����� �����ϴ�.
			break;
		if (find(parent, v[j].vertex[0]) != find(parent, v[j].vertex[1])) {
			sum += v[j].cost;

			if (t < 10)
			{
				T[t] = v[j].vertex[0]; //�ϼ��� Kruskal�� edge���� ����
				T[t + 1] = v[j].vertex[1];
			}
			unionvertex(parent, v[j].vertex[0], v[j].vertex[1]);
			countedge++;
			t += 2;

		}

	}
	cout << "Minimum Spanning Tree \n";
	for (int p = 0; p < 9; p += 2)
	{
		cout << "[" << T[p] << ", " << T[p + 1] << "]\n";
	}
	cout << "�׷����� Minimum Spanning Tree�� �� cost�� �� : " << sum << "\n";
}
