#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

void DisplayKnapsack(int itemnumber, int weight, int mrray[][6], int irray[][2]) {	// Kanpsack 결과를 통해 선택된 아이템을 출력합니다.
	if (itemnumber == 0 || weight == 0)
		return;
	if (mrray[itemnumber][weight] == 1)	// 계산된 아이템을 확인합니다.
	{
		cout << itemnumber << " ";
		cout << "(" << irray[itemnumber][0] << ", " << irray[itemnumber][1] << ")" << endl;
		DisplayKnapsack(itemnumber - 1, weight - irray[itemnumber][0], mrray, irray);
	}
	else DisplayKnapsack(itemnumber - 1, weight, mrray, irray);	// 선택된 아이템을 찾기위함 입니다.

}



void main() {

	int Brray[6][6];			// B array 입니다.
	int mrray[6][6] = { 0 };	// m array 입니다.
	int irray[6][2] = { {0,0},{3,2},{4,3},{2,2},{5,4},{1,2} };	// PPT에 있는 아이템으로 설정하였습니다.

	int itemnumber = 5, weight=5;	// 아이템수와 최종 무게 W 입니다.

	for (int j = 0; j <= weight; j++)	// 기본 설정을 합니다.
		Brray[0][j] = 0;

	for (int i = 1; i<= itemnumber; i++)
	{
		Brray[i][0] = 0;	// 기본 설정을 합니다. 뒤의 값들이 있는 아이템들을 계산하기 위함입니다.
		for (int jw = 1; jw <= weight; jw++)
		{
			if (irray[i][0] <= jw)	// 만약 무게가 남는다면 아이템을 추가할지 확인합니다.
			{
				if (Brray[i - 1][jw - irray[i][0]] + irray[i][1] > Brray[i - 1][jw])	// 가중치를 추가하여 비교합니다.
				{
					Brray[i][jw] = Brray[i - 1][jw - irray[i][0]]+irray[i][1];
					mrray[i][jw] = 1;		// 가중치가 더 높게 나오면 아이템을 선택합니다.
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

	cout << "< B array >" << endl;			// 최종 계산된 B array를 출력합니다.
	for (int a = 0; a <= itemnumber; a++)
	{
		for (int b = 0; b <= itemnumber; b++)
		{
			cout << "  " << Brray[a][b];
		}
		cout << endl;
	}
	cout << "< m array >"<< endl;			// 최종 계산된 m array를 출력합니다.
	for (int a = 0; a <= itemnumber; a++)
	{
		for (int b = 0; b <= itemnumber; b++)
		{
			cout << "  "<<mrray[a][b];
		}
		cout << endl;
	}
	cout << "-------------------------" << endl;
	cout << "\n" << "최종 선택 아이템" <<endl ;
	cout <<"\n"<< "   w, v" << endl;

	DisplayKnapsack(itemnumber, weight, mrray,irray); // i와 j가 각각 n과 W인 시점부터 선택된 아이템들을 확인하여 출력합니다.

}