#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {
	int h, no;
	struct _NODE *prev, *next;
} Node;

int main(void) {
	int n, i, j, sum=0, cnt=0;
	Node *head, *temp, *max, *prev;
	Node *h[100];

	max = head = temp = (Node*)malloc(sizeof(Node));
	head->prev = NULL;
	head->h = 0;

	scanf("%d", &n);
	for(i=0; i<n; i++) {
		temp->next = (Node*)malloc(sizeof(Node));
		temp = temp->next;
		temp->no = i+1;
		scanf("%d", &(temp->h));
		if(temp->h > max->h) {
			max = temp;
		}

		temp->next = NULL;
		temp->prev = prev;

		prev = temp;
	}
	h[cnt++] = head->next;
	h[cnt++] = max->next;

	if(max->prev) {
		max->prev->next = NULL;
	}
	if(max->next) {
		max->next->prev = NULL;
	}
	head->next->prev = NULL;

	sum += (n - max->no);
	free(head);
	free(max);

	while(cnt) {
		if(h[cnt-1]->next == NULL) {
			cnt--;
			continue;
		}

		max = h[--cnt];
		for(temp=max->next; temp; temp=temp->next) {
			if(max->h < temp->h) {
				max = temp;
			}
		}

		for(temp=max->next; temp; temp=temp->next) {
			sum++;
		}

		if(max->prev) {
			cnt++;
			max->prev->next = NULL;
		}
		if(max->next) {
			h[cnt++] = max->next;
			max->next->prev = NULL;
		}
	
		free(max);
	}

	printf("%d \n", sum);   // Print Result

	return 0;
}
