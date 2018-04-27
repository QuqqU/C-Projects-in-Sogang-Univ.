#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <termios.h>
#include <sys/time.h>
#include <unistd.h>

/* game over flag & board state */
int game_over, b[4][4];
FILE *fp;

void init() {
	int i, j;
	game_over = 0;
	for (i = 0; i<4; i++)
		for (j = 0; j<4; j++)
			b[i][j] = 0;
}


void rotate(int b[4][4]) {//보드판 시계방향으로 90도회전 setboard함수에서 사용
						  /* user code */
	int buf[4][4];

	int right = 3;
	for (int i = 0; i<4; i++) {
		int a = 0;
		for (int j = 0; j<4; j++) {
			buf[a++][right] = b[i][j];
		}
		right--;
	}
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			b[i][j] = buf[i][j];
}//ok

int set_board(int dir, int b[4][4]) { // 방향 , 보드판 // 주어진 상하좌우 입력맞게 보드이동 // 올바른 이동이면 1리턴 아니면 0리턴
	int buf[4][4];
	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
			buf[i][j] = b[i][j];

	for (int i = 0; i<dir; i++) {
		rotate(b);
	}

	for (int line = 0; line < 4; line++) {
		for(int x = 0 ; x< 3; x++){
			for (int q = 2; q >= 0; q--) {
				if (b[line][q] == 0) continue;
				if (b[line][q + 1] == 0) {
					b[line][q + 1] = b[line][q];
					b[line][q] = 0;
				}
			}
		}

		for(int q = 2; q>=0; q--)
			if(b[line][q+1]==b[line][q]){
				b[line][q+1] *= 2;
				b[line][q] =0;
			}

		for(int x = 0; x< 3; x++)
			for(int q = 2; q>= 0; q--) {
				if(b[line][q]==0) continue;
				if(b[line][q+1]==0){
					b[line][q+1] = b[line][q];
					b[line][q] = 0;
				}	
			}

	}

	for (int y = 0; y< 4 - dir; y++)
	rotate(b);
	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
			if (b[i][j] != buf[i][j]) return 1;
	return 0;
}

int is_game_over() { // game over 이면 1 리턴 아니면 0 이런
					 /* user code */
	int i, j, t = 0;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 3; j++) {
			if (b[i][j] == b[i][j + 1]) t = 1;
			if (b[j][i] == b[j + 1][i]) t = 1;
		}
	}
	for (i = 0; i < 4; i++) 
		for (j = 0; j < 4; j++) 
			if (b[i][j] == 0) t = 1;
		
	
	/* if game over return 0, else then return 1 */
	if (t == 1) return 0;
	else return 1;
}

void draw_board(int tot, int command) {//함수 호출 시마다 4*4화면 새롭게그리고/ 전체 생성된 tot의 개수가 4*4에 나타난 숫자의 합과 일치하는지 확인
	int ttot = 0, i, j, k, c[8][8], score;//4*4판 변화마다 output.txt에 점수 키 판 정보 출력
										  /* console clear */
	system("clear");

	score = 0;
	/* user code */
	for (i = 0; i <= 3; i++) {
		for (j = 0; j <= 3; j++) {
			if (score < b[i][j]) score = b[i][j];
			ttot += b[i][j];
		}
	}
	if (ttot != tot) printf("error!!!");
	/* calculate score & check sum of all block equasls variable tot */



	printf("    Score : %d\n", score);
	fprintf(fp, "%d %d\n", score, command);

	for (i = 0; i<4; i++) {
		for (j = 0; j<4; j++) {
			c[i][j] = 32;
			for (k = 0; k<50; k++) {
				if (b[i][j] == (1 << k)) {
					c[i][j] = 32 + (k % 6);
					break;
				}
			}

		}
	}
	for (i = 0; i<4; i++) {
		for (j = 0; j<4; j++)
			fprintf(fp, "%d ", b[i][j]);
		fprintf(fp, "\n");
	}

	for (i = 0; i<4; i++) {
		puts("");
		puts("");
		for (j = 0; j<4; j++)
			printf("\033[%dm%5d\033[0m", c[i][j], b[i][j]);
		puts("");
		puts("");
	}
}

int make_two_or_four() { // 임의의 빈 공간에 2/4생성 임의의 빈공간없을 경우 0  아니라면 생성한 2/4/리턴
						 /* user code */
	int x, y, t = 0, i, j;//2생성확률 2/3 4는 1/3
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (b[i][j] == 0) t = 1;
		}
	}
	if (t == 0) return 0;
	srand(time(NULL));
	if (rand() % 3 == 0) t = 4;
	else t = 2;
	/* return 2 or 4 that makes in this times */
	while (1) {
		x = rand() % 4; y = rand() % 4;
		if (b[x][y] == 0) {
			b[x][y] = t;
			return t;
		}
	}
	/* if can not make two or four, then return 0 */
}


int getch(void)
{
	char   ch;
	int   error;
	static struct termios Otty, Ntty;

	fflush(stdout);
	tcgetattr(0, &Otty);
	Ntty = Otty;
	Ntty.c_iflag = 0;
	Ntty.c_oflag = 0;
	Ntty.c_lflag &= ~ICANON;
#if 1
	Ntty.c_lflag &= ~ECHO;
#else
	Ntty.c_lflag |= ECHO;
#endif
	Ntty.c_cc[VMIN] = 0;
	Ntty.c_cc[VTIME] = 1;

#if 1
#define FLAG TCSAFLUSH
#else
#define FLAG TCSANOW
#endif

	if (0 == (error = tcsetattr(0, FLAG, &Ntty)))
	{
		error = read(0, &ch, 1);
		error += tcsetattr(0, FLAG, &Otty);
	}

	return (error == 1 ? (int)ch : -1);
}


int GetCommand() {
	int ch = getch();

	switch (ch)
	{
	case 'd':
	case 'D': return 0;
	case 'w':
	case 'W': return 1;
	case 'a':
	case 'A': return 2;
	case 's':
	case 'S': return 3;
	default: return -1;
	}

	return -1;
}


int main() {
	int command = -1;
	fp = fopen("output.txt", "w");
	init();
	srand(time(NULL));

	int tot = 0;

	/* make init board */
	tot += make_two_or_four();
	tot += make_two_or_four();
	/* user code */

	draw_board(tot, -1);


	do {
		command = GetCommand();

		if (command != -1) {
			if (set_board(command, b)) {

				tot += make_two_or_four();

				draw_board(tot, command);
			}
		game_over = is_game_over();
		}
		
	} while (!game_over);

	system("clear");
	printf("game over!\n");
	fclose(fp);
}
