#include <stdio.h>
int main(){
	int k, x, y;
	while (scanf("%d%d%d",&k,&x,&y)!=EOF){
		if (k==0 && x==0 & y==0) return 0;
		int cx=1024, cy=1024;
		int ans=0;
		do{
			if (cx-k<=x && x<=cx+k && cy-k<=y && y <=cy+k) ans ++;
			cx=(x>cx)?cx+k:cx-k;
			cy=(y>cy)?cy+k:cy-k;
		}while(k/=2>=1);
		printf("%3d\n",ans);
	}
	return 0;
}