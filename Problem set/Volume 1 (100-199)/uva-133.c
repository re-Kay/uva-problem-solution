#include <stdio.h>
struct LinkedList{
	int box;
	int next;
	int back;
} a[30];

void init(int n){
	int i;
	a[0].box=1;
	a[0].next=1;
	a[0].back=n-1;
	for (i=1;i<n-1;i++){
		a[i].box=i+1;
		a[i].next=i+1;
		a[i].back=i-1;
	}
	a[n-1].box=n;
	a[n-1].next=0;
	a[n-1].back=n-2;
	if (n==1) a[0].next=a[0].back=0;
}

int main(){
	int n,k,m;
	while(scanf("%d%d%d",&n,&k,&m)==3){
		if (k==0&&m==0&n==0) return 0;
		init(n);
		int posCCW=0, posCW=n-1, output=0;
		while (1){
			int back_cnt=0, next_cnt=0;
			while (++next_cnt<k)  posCCW=a[posCCW].next;
			while (++back_cnt<m)  posCW=a[posCW].back;
			if (posCCW!=posCW){
				printf("%3d%3d",a[posCCW].box,a[posCW].box);
				output+=2;
				a[a[posCCW].back].next=a[posCCW].next;
				a[a[posCCW].next].back=a[posCCW].back;
				a[a[posCW].back].next=a[posCW].next;
				a[a[posCW].next].back=a[posCW].back;
				posCCW=a[a[posCCW].back].next;
				posCW=a[a[posCW].next].back;
			}else{
				printf("%3d",a[posCCW].box);
				output+=1;
				posCCW=a[a[posCCW].back].next=a[posCCW].next;
				posCW=a[a[posCW].next].back=a[posCW].back;
			}
			if (output>=n)break;
			if (output!=0) printf(","); 
		}
		printf("\n");
	}
	return 0;
}