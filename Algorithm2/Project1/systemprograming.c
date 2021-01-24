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
	int numcheck = 0;	//�ߺ��� ���� ���� ����Ʈ�� �������� �ʽ��ϴ�.
	int stop = 1;		// ��� ���� ���� ����Ʈ�� �����ϸ� �ݺ����� �����մϴ�.
	int count5000 = 0;		// 5000�̻��� data�� ���� ���ϴ�.
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
		if (numcheck == 1)		//�ߺ��� ���� �߰��ߴٸ� �ٽ� ���Ͽ��� ���ڸ� �о�ɴϴ�.
		{
			numcheck = 0;
			inputnum = 0;
			continue;
		}

		if (inputnum > 5000)	// 5000 �ʰ��� ���� ��� ī��Ʈ�մϴ�.
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