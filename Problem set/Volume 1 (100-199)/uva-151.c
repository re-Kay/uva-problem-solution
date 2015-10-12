#include <stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)==1 && n!=0){
		int m=1;
		while(1){
			int i, pos=0, list[105]={-1,0,};
			for (i=1;i<n-1;i++){
				int cnt=0;
				while (cnt<m) if (list[pos=(pos+1)%n]!=-1) cnt++;
				list[pos]=-1;
			}
			if (list[12]!=-1) break;
			m++;
		}
		printf("%d\n",m);
	}
	return 0;
}