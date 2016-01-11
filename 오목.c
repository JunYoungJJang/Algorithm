#include <stdio.h>

int main(void)
{
	int pan[19][19];
	int i, j, x, y;

	int black[400][2], bcnt=0;   // x좌표, y좌표
	int white[400][2], wcnt=0;
	
	for(i=0; i<19; i++) {
		for(j=0; j<19; j++) {
			scanf("%d ", &pan[i][j]);

			if(pan[i][j] == 1) {
				black[bcnt][0] = i;
				black[bcnt++][1] = j;
			} 
			else if(pan[i][j] == 2) {
				white[wcnt][0] = i;
				white[wcnt++][1] = j;
			}
		}
	}
	// 데이터 입력

	for(i=0; i<bcnt; i++) {   // 껌정돌 검사
		x = black[i][0];
		y = black[i][1];

		for(j=0; (y>=0 && y<19) && pan[x][y]==1; j++) {
			y++;
		}   // 가로

		y = black[i][1] - 1;
		for( ; (y>=0 && y<19) && pan[x][y]==1; j++) {
			y--;
		}
		if(j==5) {
			goto BLACK_WIN;
		}

		x = black[i][0];
		y = black[i][1];
		for(j=0; (x>=0 && x<19) && (y>=0 && y<19) && pan[x][y]==1; j++) {
			x++;
			y++;
		}   // 대각선 아래
		
		x = black[i][0] - 1;
		y = black[i][1] - 1;
		for( ; (x>=0 && y<19) && (y>=0 && y<19) && pan[x][y]==1; j++) {
			x--;
			y--;
		}
		if(j==5) {
			goto BLACK_WIN;
		}
	}

	for(i=0; i<bcnt; i++) {
		x = black[i][0];
                y = black[i][1];

                for(j=0; (x>=0 && x<19) && pan[x][y]==1; j++) {
                        x++;
                }   // 세로

                x = black[i][0] - 1;
                for( ; (x>=0 && x<19) && pan[x][y]==1; j++) {
                        x--;
                }
                if(j==5) {
                        goto BLACK_WIN;
                }

		x = black[i][0];
                y = black[i][1];

                for(j=0; (x>=0 && x<19) && (y>=0 && y<19) && pan[x][y]==1; j++) {
                        x--;
                        y++;
                }   // 대각선 위

                x = black[i][0] + 1;
                y = black[i][1] - 1;

                for( ; (x>=0 && x<19) && (y>=0 && y<19) && pan[x][y]==1; j++) {
                        x++;
                        y--;
                }
                if(j==5) {
                        goto BLACK_WIN;
                }
	}

	for(i=0; i<wcnt; i++) {   // 흰돌 검사
		x = white[i][0]; 
		y = white[i][1];

		for(j=0; (y>=0 && y<19) && pan[x][y]==2; j++) {   // 가로 검사
			y++;
		}
		
		y = white[i][1] - 1;
		for( ; (y>=0 && y<19) && pan[x][y]==2; j++) {
			y--;
		}

		if(j==5) {
			goto WHITE_WIN;
		}

                x = white[i][0];
                y = white[i][1];

                for(j=0; (x>=0 && x<19) && (y>=0 && y<19) && pan[x][y]==2; j++) {
                        x++;
                        y++;
                }   // 대각선 아래

		x = white[i][0] - 1;
		y = white[i][1] - 1;
		for( ; (x>=0 && x<19) && (y>=0 && y<19) && pan[x][y]==2; j++) {
			x--;
			y--;
		}
	
                if(j==5) {
                        goto WHITE_WIN;
        	}
	}

	for(i=0; i<wcnt; i++) {
		x = white[i][0];
                y = white[i][1];

                for(j=0; (x>=0 && x<19) && pan[x][y]==2; j++) {
                        x++;
                }   // 세로

                x = white[i][0] - 1;
                for( ; (x>=0 && x<19) && pan[x][y]==2; j++) {
                        x--;
                }
                if(j==5) {
                        goto WHITE_WIN;
                }

		x = white[i][0];
                y = white[i][1];

                for(j=0; (x>=0 && x<19) && (y>=0 && y<19) && pan[x][y]==2; j++) {
                        x--;
                        y++;
                }   // 대각선 위

                x = white[i][0] + 1;
                y = white[i][1] - 1;

                for( ; (x>=0 && x<19) && (y>=0 && y<19) && pan[x][y]==2; j++) {
                        x++;
                        y--;
                }
                if(j==5) {
                        goto WHITE_WIN;
                }
	}
	
	goto DRAW;

BLACK_WIN :
        printf("1 \n");
        printf("%d %d \n", black[i][0]+1, black[i][1]+1);

        goto EXIT;

WHITE_WIN :
        printf("2 \n");
        printf("%d %d \n", white[i][0]+1, white[i][1]+1);

        goto EXIT;

DRAW :
	printf("0 \n");

EXIT :
	return 0;
}
