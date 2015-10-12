#include <stdio.h>
int main(){
	int map[10002]={0,};
	int i, l, h, r, max_r=0, min_l=10001;
	while (scanf("%d%d%d", &l,&h,&r)==3){
		for (i=l;i<r;i++) if (map[i]<h) map[i]=h;
		if (max_r<r) max_r=r;
		if (min_l>l) min_l=l;
	}
	int pos=min_l;
	for (i=min_l+1;i<=max_r;i++)
		if (map[i]!=map[pos]){
			printf("%d %d ", pos, map[pos]);
			pos=i;
		}
	printf("%d %d\n",max_r, 0);
	return 0;
}