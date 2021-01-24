#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

void DisplayKnapsack(int itemnumber, int weight, int mrray[][6], int irray[][2]) {	// Kanpsack ����� ���� ���õ� �������� ����մϴ�.
	if (itemnumber == 0 || weight == 0)
		return;
	if (mrray[itemnumber][weight] == 1)	// ���� �������� Ȯ���մϴ�.
	{
		cout << itemnumber << " ";
		cout << "(" << irray[itemnumber][0] << ", " << irray[itemnumber][1] << ")" << endl;
		DisplayKnapsack(itemnumber - 1, weight - irray[itemnumber][0], mrray, irray);
	}
	else DisplayKnapsack(itemnumber - 1, weight, mrray, irray);	// ���õ� �������� ã������ �Դϴ�.

}



void main() {

	int Brray[6][6];			// B array �Դϴ�.
	int mrray[6][6] = { 0 };	// m array �Դϴ�.
	int irray[6][2] = { {0,0},{3,2},{4,3},{2,2},{5,4},{1,2} };	// PPT�� �ִ� ���������� �����Ͽ����ϴ�.

	int itemnumber = 5, weight=5;	// �����ۼ��� ���� ���� W �Դϴ�.

	for (int j = 0; j <= weight; j++)	// �⺻ ������ �մϴ�.
		Brray[0][j] = 0;

	for (int i = 1; i<= itemnumber; i++)
	{
		Brray[i][0] = 0;	// �⺻ ������ �մϴ�. ���� ������ �ִ� �����۵��� ����ϱ� �����Դϴ�.
		for (int jw = 1; jw <= weight; jw++)
		{
			if (irray[i][0] <= jw)	// ���� ���԰� ���´ٸ� �������� �߰����� Ȯ���մϴ�.
			{
				if (Brray[i - 1][jw - irray[i][0]] + irray[i][1] > Brray[i - 1][jw])	// ����ġ�� �߰��Ͽ� ���մϴ�.
				{
					Brray[i][jw] = Brray[i - 1][jw - irray[i][0]]+irray[i][1];
					mrray[i][jw] = 1;		// ����ġ�� �� ���� ������ �������� �����մϴ�.
				}
				else
				{
					Brray[i][jw] = Brray[i - 1][jw];
					mrray[i][jw] = 0;
				}
					
			}
			else {
				Brray[i][jw] = Brray[i - 1][jw];
				mrray[i][jw] = 0;
			}
		}
	}

	cout << "< B array >" << endl;			// ���� ���� B array�� ����մϴ�.
	for (int a = 0; a <= itemnumber; a++)
	{
		for (int b = 0; b <= itemnumber; b++)
		{
			cout << "  " << Brray[a][b];
		}
		cout << endl;
	}
	cout << "< m array >"<< endl;			// ���� ���� m array�� ����մϴ�.
	for (int a = 0; a <= itemnumber; a++)
	{
		for (int b = 0; b <= itemnumber; b++)
		{
			cout << "  "<<mrray[a][b];
		}
		cout << endl;
	}
	cout << "-------------------------" << endl;
	cout << "\n" << "���� ���� ������" <<endl ;
	cout <<"\n"<< "   w, v" << endl;

	DisplayKnapsack(itemnumber, weight, mrray,irray); // i�� j�� ���� n�� W�� �������� ���õ� �����۵��� Ȯ���Ͽ� ����մϴ�.

}