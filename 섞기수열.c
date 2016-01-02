#include <stdio.h>

int main(void)
{
	int i, j, index, n, r, cnt=0;
	int arr[20000] = {0,};
	int visited[20000] = {0,};
	int min_table[10000] = {0,};   // 최소 공배수 구할 수열
	int max, temp;

	scanf("%d", &n);
	for(i=0; i<n; i++) {   // 입력
		scanf("%d", &arr[i]);
	}

	for(i=0; i<n; i++) {
		if(visited[i]) {   // 이미 루틴의 길이 확인함
			continue;
		}
		
		index = i, r = 0;
		do {
			visited[index] = 1;   // 방문 완료
			index = arr[index]-1;   // 다음 수열
			r++;
		} while(index != i);
		
		min_table[cnt++] = r;
	}

	// 궤적(최소 공배수 구하기)
	max = -1;
	for(i=0; i<cnt; i++) {   // 1. 테이블에서 가장 큰 값 구함
		if(max < min_table[i]) {
			max = min_table[i];
		}
	} 

	for(i=1; ; i++) {
		temp = 1;
		for(j=0; j<cnt; j++) {
			if((max*i) % min_table[j]) {
				temp = 0;
				break;
			}
		}

		if(temp) {
			break;
		}
	}

	printf("%d \n", max*i);
	return 0;
}

