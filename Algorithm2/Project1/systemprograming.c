#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node
{
	long long num;
	struct node* link;
};
void freenode(struct node* NODE) {
	struct node* freedom;
	while (freedom != NULL) {
		freedom = NODE;
		NODE = NODE->link;
		free(freedom);
	}
}


int main() {
	int numcheck = 0;	//중복된 수를 연결 리스트에 저장하지 않습니다.
	int stop = 1;		// 모든 수를 연결 리스트에 저장하면 반복문을 정지합니다.
	int count5000 = 0;		// 5000이상의 data의 수를 셉니다.
	int countnode = 0;
	long long inputnum;
	struct node* start = NULL;
	struct node* duplication = NULL;
	struct node* end = NULL;
	struct node* node;
	FILE* input = fopen("input.txt", "r");

	for (int i = 0; i < 100000; i++) {
		fscanf(input, "%lld", &inputnum);
		while (1)
		{
			if (duplication != NULL)
				if (duplication->num == inputnum)
					numcheck = 1;
				else
					duplication = duplication->link;
			else break;
		}
		if (numcheck == 1)		//중복의 수를 발견했다면 다시 파일에서 숫자를 읽어옵니다.
		{
			numcheck = 0;
			inputnum = 0;
			continue;
		}

		if (inputnum > 5000)	// 5000 초과의 값일 경우 카운트합니다.
			count5000++;

		node = (struct node*)malloc(sizeof(struct node));

		countnode++;
		if (node)
		{
			node->num = inputnum;
			node->link = NULL;
		}

		if (start == NULL)
			start = node;
		else end->link = node;

		end = node;
		duplication = start;


	}
	printf("The total number of nodes: %d\n", countnode);
	printf("More than 5000 values: %d\n", count5000);

	freenode(start);
	fclose(input);
	return 0;


}