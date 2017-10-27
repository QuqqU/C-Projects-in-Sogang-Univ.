
/*
 *
 *	Title : Mini Paint
 *	Date : 28.Oct.2017 FRI
 *	Author : K.U.Jung.
 *
 *	~ C-programming 1st project
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>

//print the image.
void P(int h, int w, char** a){
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++)
			printf("%c", a[i][j]);
		puts("");
	}
}
//input two integers, and return smaller one.
int min(int a, int b) {
	return a<b?a:b;
}
//swap two integer variables.
void swp(int* a, int* b){
	*a^=*b;*b^=*a;*a^=*b;
}
//swap two character variables.
void swap(char* a, char* b){
	*a^=*b;*b^=*a;*a^=*b;
}
//if flag=1 flip the image right and left, else(flage=0) flip it upside down.
void flip(int height, int width, int flag, char** img){
	if(flag)
		for(int i=0;i<height;i++)
			for(int j=0;j<width/2;j++)
				swap(&img[i][j], &img[i][width-j-1]);
	else
		for(int j=0;j<width; j++)
			for(int i=0;i<height/2;i++)
				swap(&img[i][j], &img[height-i-1][j]);
}
//find which cell should be printed, using DFS.
void dfs(char origin, int* cnt, int* xx, int* yy, int** vis, int x, int y, char color, char** img, int h, int w){
	vis[x][y]=1; (*cnt)++; img[x][y]=color;
	for(int i=0;i<4;i++)
		if(0<=x+xx[i] && x+xx[i]<h && 0<=y+yy[i] && y+yy[i]<w && vis[x+xx[i]][y+yy[i]]==0 && img[x+xx[i]][y+yy[i]]==origin)
			dfs(origin,cnt,xx,yy,vis,x+xx[i],y+yy[i],color,img,h,w);
}
//fill the image with certain color on certain area.
int fill(int x, int y, char color, char** img,int h, int w){
	int* dx; dx = (int*)malloc(sizeof(int)*10); dx[0] = 0; dx[1] = 1; dx[2] = 0; dx[3] = -1;
	int* dy; dy = (int*)malloc(sizeof(int)*10); dy[0] = 1; dy[1] = 0; dy[2] = -1; dy[3] = 0;
	int** vis;vis = (int**)calloc(h,sizeof(int*));for(int i=0;i<h;i++) *(vis+i) = (int*)calloc(w,sizeof(int));
	int cnt = 0; if(img[x][y]!=color) dfs(img[x][y],&cnt,dx,dy,vis,x,y,color,img,h,w);
	for(int i=0;i<h;i++) free(*(vis+i)); free(vis);free(dx);free(dy);
	return cnt;
}
//rotae the image, if angle=0 turn it 90 degrees clock wise, angle=1 180 degrees, and angle=2 270 degrees.
char** rotate(int* height, int* width, int angle, char** img){
	int h = *height;
	char** buf; buf=(char**)calloc(sizeof(char*), *height); for(int i=0;i<*height;i++) buf[i]=(char*)calloc(sizeof(char), *width);
	for(int i=0;i<*height;i++) for(int j=0;j<*width;j++) buf[i][j]=img[i][j];
	switch(angle){
		case 0:
			img = (char**)realloc(img,sizeof(char*)*(*width));
			if(*height < *width) for(int i=*height;i<*width;i++) img[i] = NULL;
			for(int i=0;i<*width;i++) img[i]=(char*)realloc(img[i],sizeof(char)*(*height));
			for(int i=0;i<*height;i++) for(int j=*width-1;j>=0;j--) img[j][*height-i-1] = buf[i][j];
			swp(height,width);
			break;
		case 1:
			flip(*height, *width, 0, img);flip(*height, *width, 1, img);
			break;
		case 2:
			img = (char**)realloc(img,sizeof(char*)*(*width));
			if(*height < *width) for(int i=*height;i<*width;i++) img[i] = NULL;
			for(int i=0;i<*width;i++) img[i]=(char*)realloc(img[i],sizeof(char)*(*height));
			for(int i=0;i<*height;i++) for(int j=*width-1;j>=0;j--) img[j][*height-i-1] = buf[i][j];
			swp(height,width);flip(*height,*width,0,img);flip(*height,*width,1,img);
			break;
		default :
			puts("Error : Query 2 Rotate needs only 0,1 or 2 argument.");
			break;
	}
	for(int i=0;i<h;i++) free(*(buf+i)); free(buf);
	return img;
}
//copy certain area on the image.
char* copy(int x1, int y1, int c_h, int c_w, int height, int width, char** img){
	char* temp = NULL; temp = (char*)malloc(sizeof(char)*c_h*c_w*2); int idx = 0;
	for(int i=y1;i<min(height,y1+c_h);i++){
		for(int j=x1;j<min(width,x1+c_w);j++)
			temp[idx++] = img[i][j];
		temp[idx++] = '\0';
	}
	return temp;
}
//paste copied image to the origin image.
void paste(int x2, int y2, int height, int width, char** img, char* temp){
	int idx = 0;
	for(int i=y2;i<height;i++){
		for(int j=x2;j<width;j++){
			if(temp[idx]=='\0') break;
			img[i][j] = temp[idx++];
		}
		while(temp[idx]!='\0') idx++;
		idx++;
	}
	free(temp);
}
//resize the image. if arg1=0 make it twice, else(arg1=1) make it half.
char** resize(int arg1, int* height, int* width, char** img){
	if(arg1 == 0){
		if(*height * 2 > 4096 || *width * 2 > 4096) {puts("Size Error"); return img;}
		char** buf; buf = (char**)malloc(sizeof(char*)*(*height)); for(int i=0;i<*height;i++) buf[i]=(char*)malloc(sizeof(char)*(*width));
		for(int i=0;i<*height;i++) for(int j=0;j<*width;j++) buf[i][j]=img[i][j];
		img = (char**)realloc(img,sizeof(char*)*(*height)*2);
		for(int i=*height;i<*height*2;i++) img[i] = NULL;
		for(int i=0;i<*height*2;i++) img[i]=(char*)realloc(img[i],sizeof(char)*(*width*2));
		for(int i=0;i<*height;i++)
			for(int j=0;j<*width;j++)
				img[2*i+1][2*j+1]=img[2*i][2*j+1]=img[2*i+1][2*j]=img[2*i][2*j]=buf[i][j];
		for(int i=0;i<*height;i++) free(*(buf+i)); free(buf);
		(*height)*=2;(*width)*=2;
	}
	else if(arg1 == 1){
		if(*height/2==0||*width/2==0) {puts("Size Error"); return img;}
		char** buf; buf = (char**)malloc(sizeof(char*)*(*height)); for(int i=0;i<*height;i++) buf[i]=(char*)malloc(sizeof(char)*(*width));
		for(int i=0;i<*height;i++) for(int j=0;j<*width;j++) buf[i][j]=img[i][j];
		img = (char**)realloc(img,sizeof(char*)*(*height/2));
		for(int i=0;i<*height/2;i++) img[i]=(char*)realloc(img[i],sizeof(char)*(*width/2));
		for(int i=0;i<*height/2;i++)
			for(int j=0;j<*width/2;j++)
				img[i][j]=(buf[2*i][2*j]+buf[2*i+1][2*j]+buf[2*i][2*j+1]+buf[2*i+1][2*j+1])/4;
		for(int i=0;i<*height;i++) free(*(buf+i)); free(buf);
		(*height)/=2;(*width)/=2;
	}
	else puts("Error : Query 1 needs only 0 or 1.");
	return img;
}



int main(){
	char** map = NULL;
	printf("Input testcase : "); int T; scanf("%d",&T);
	while(T--){
		//input element variables, and make a map(image).
		printf("Input height, width : "); int h, w; scanf("%d %d", &h, &w);
		map = (char**)malloc(sizeof(char*)*h); for(int i=0;i<h;i++) *(map+i) = (char*)malloc(sizeof(char)*w);
		puts("Input the image :"); for(int i=0;i<h;i++) for(int j=0;j<w;j++) scanf(" %c", *(map+i)+j);
		//input the number of queries.
		printf("Input number of query : "); int Q; scanf("%d", &Q);
		while(Q--){
			//input kind of query.
			printf("Input query : "); int q; scanf("%d", &q); puts("");
			switch(q){
				case 1: //resize the map.
					puts("Resize");
					printf("Input 0 or 1 : "); int a1; scanf("%d", &a1);
					map = resize(a1,&h,&w,map);
					printf("Result, resize height : %d, width : %d\n", h, w);
					puts("Result Image");puts("");P(h,w,map);
					break;
				case 2: //rotate the map.
					puts("Rotate");
					printf("Input 0 or 1 or 2 : "); int a2; scanf("%d", &a2);
					map = rotate(&h,&w,a2,map);
					printf("Result_rotate height : %d, width : %d\n", h, w);
					puts("Result Image");puts("");P(h,w,map);
					break;
				case 3: //flip the map
					puts("Flip");
					printf("Input 0 or 1 : "); int a3; scanf("%d", &a3);
					flip(h,w,a3,map);
					puts("Result Image");puts("");P(h,w,map);
					break;
				case 4: //copy certain area and paste it on the map.
					puts("Copy and Paste");
					printf("x1, y1, c_h, c_w, x2, y2 : "); int x1,y1,c_h,c_w,x2,y2; scanf("%d %d %d %d %d %d",&x1,&y1,&c_h,&c_w,&x2,&y2);
					if(c_h < 0 || c_w < 0 || ((x1+c_w<0) && (y1+c_h<0)) || ((x1>w) && (y1>h))) puts("Error : input is invalid");
					else paste(x2, y2, h, w, map, copy(x1,y1,c_h,c_w,h,w,map));
					puts("Result Image");puts("");P(h,w,map);
					break;
				case 5: //fill color on the certain area of the map.
					puts("Fill");
					printf("Input : "); int a5,b5; char c5; scanf(" %d %d %c", &a5, &b5, &c5);
					if(0<=a5 && a5<h && 0<=b5 && b5<w) printf("Number of colored pixels = %d\n", fill(a5,b5,c5,map,h,w));
					else puts("Error : input is invalid");
					puts("Result Image");puts("");P(h,w,map);
					break;
				default : //input query does not exist.
					puts("Error : input opertation does not exist");
					break;
			}
		}
		//free the map.
		for(int i=0;i<h;i++) free(*(map+i)); free(map);
	}
	return 0;
}


