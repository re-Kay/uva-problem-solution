#include <stdio.h>
int b[32][5]=  {{0,1,2,3,4},
				{5,1,2,3,4},
				{5,0,2,3,4},
				{5,0,1,3,4},
				{5,0,1,2,4},
				{5,0,1,2,3},
				{5,6,0,1,2},
				{5,6,0,1,3},
				{5,6,0,1,4},
				{5,6,0,2,3},
				{5,6,0,2,4},
				{5,6,0,3,4},
				{5,6,1,2,3},
				{5,6,1,2,4},
				{5,6,1,3,4},
				{5,6,2,3,4},
				{5,6,7,0,1},
				{5,6,7,0,2},
				{5,6,7,0,3},
				{5,6,7,0,4},
				{5,6,7,1,2},
				{5,6,7,1,3},
				{5,6,7,1,4},
				{5,6,7,2,3},
				{5,6,7,2,4},
				{5,6,7,3,4},
				{5,6,7,8,0},
				{5,6,7,8,1},
				{5,6,7,8,2},
				{5,6,7,8,3},
				{5,6,7,8,4},
				{5,6,7,8,9}};
int checkFlush(int a, int b, int c, int d, int e){
	 return ((a/100==b/100) && (b/100==c/100) && (c/100==d/100) && (d/100==e/100));
}

int checkStraight(int a, int b, int c, int d, int e){
	int x[5]={a,b,c,d,e};
	int i,j;
	for (i=0;i<4;i++)
		for (j=0;j<4-i;j++)
			if (x[j]>x[j+1]){
				int temp =x[j];
				x[j]=x[j+1];
				x[j+1]=temp;
			}
	if (x[0]==1 && x[1]==10 && x[2]==11 && x[3]==12 && x[4]==13) return 1;
	for (i=0;i<4;i++)
		if (x[i]+1!=x[i+1])
			return 0;
	return 1;
}

int checkFourOfKind(int a, int b, int c, int d){
	return ((a==b) && (b==c) && (c==d));
}

int checkPair(int a, int b){
	return (a==b);
}

int analysis(int a, int b, int c, int d, int e){
	int isFlush = checkFlush(a,b,c,d,e);
	a%=100; b%=100; c%=100; d%=100; e%=100;
	int isStraight = checkStraight(a,b,c,d,e);
	int isFourOfKind = checkFourOfKind(a,b,c,d) + checkFourOfKind(a,b,c,e) + checkFourOfKind(a,b,d,e) + checkFourOfKind(a,e,c,d)+ checkFourOfKind(e,b,c,d);
	if ((isFlush) && (isStraight)) return 1;
	if (isFourOfKind) return 2;
	if (isFlush) return 4;
	if (isStraight) return 5;
	int numPair = checkPair(a,b) + checkPair(a,c) + checkPair(a,d) + checkPair(a,e) + checkPair(b,c) + checkPair(b,d) + checkPair(b,e) + checkPair(c,d) + checkPair(c,e) + checkPair(d,e);
	if (numPair == 4) return 3;
	if (numPair == 3) return 6;
	if (numPair == 2) return 7;
	if (numPair == 1) return 8;
	return 9;
}



int main(){
	char s[100];
	while (fgets(s,100,stdin)!=NULL){
		int a[10]={0,};
		int i;
		char ca,cb;
		for (i=0;i<10;i++){
			ca=s[3*i];
			cb=s[3*i+1];
			if (cb=='C') a[i]+=100;
			if (cb=='D') a[i]+=200;
			if (cb=='H') a[i]+=300;
			if (cb=='S') a[i]+=400;
			if (ca=='T') a[i]+=10;
			else if (ca=='J') a[i]+=11;
			else if (ca=='Q') a[i]+=12;
			else if (ca=='K') a[i]+=13;
			else if (ca=='A') a[i]+=1;
			else a[i]+=ca-'0';
		}

		int ans=10;
		for (i=0;i<32;i++){
			int t = analysis(a[b[i][0]],a[b[i][1]],a[b[i][2]],a[b[i][3]],a[b[i][4]]);
			ans = (ans>t)?t:ans;
		}

		printf("Hand: ");
		for (i=0;i<14;i++)
			printf("%c",s[i]);
		printf(" Deck: ");
		for (i=15;i<29;i++)
			printf("%c",s[i]);
		printf(" Best hand: ");
		if (ans == 1) printf("straight-flush");
		if (ans == 2) printf("four-of-a-kind");
		if (ans == 3) printf("full-house");
		if (ans == 4) printf("flaush");
		if (ans == 5) printf("straight");
		if (ans == 6) printf("three-of-a-kind");
		if (ans == 7) printf("two-pairs");
		if (ans == 8) printf("one-pair");
		if (ans == 9) printf("highest-card");
		printf("\n");
	}
	return 0;
}