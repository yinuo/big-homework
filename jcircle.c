#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} *list;

int main(int argc, const char *argv[])
{
    if(argc < 3){
    printf("请重新输入\n");
    return 0;
    }
	int m = atoi(argv[1]);
	int n = atoi(argv[2]);
	createlist(m, n);
	return 0;
}

createlist(int m, int n)
{
	int i, count;
	list head, item, parent;
	head = (list) malloc(sizeof(struct node) * m);
	if (!head)
		printf("malloc error");
	item = head;
	for (i = 0; i < m; i++) {
		item->data = i + 1;
		if (i == m - 1) {
			item->next = head;
//			parent = item;
		} else {
			item->next = item + 1;
		}
		item++;
	}

	item = head;

	for (i = 0; i < m; i++) {
		count = 0;
		while (++count < n) {
			parent = item;
			item = item->next;
		}
		printf("%5d %5d:out", i + 1, item->data);
		if ((i + 1) % 5 == 0)
			printf("\n");
		parent->next = item->next;
		item = parent->next;
	}
	if (head)
		free(head);
}
