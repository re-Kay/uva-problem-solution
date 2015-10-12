#include <stdio.h>
int main(){
	int a[9];
	while (scanf("%d%d%d%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8])==9){
		int sum, tsum, pos;
		sum = a[3]+a[6]+a[2]+a[8]+a[1]+a[4];
		pos = 0;
		tsum = a[3]+a[6]+a[1]+a[7]+a[2]+a[5];
		if(sum>tsum) {sum = tsum; pos=1;}
		tsum = a[5]+a[8]+a[0]+a[6]+a[1]+a[4];
		if(sum>tsum) {sum = tsum; pos=2;}
		tsum = a[5]+a[8]+a[1]+a[7]+a[0]+a[3];
		if(sum>tsum) {sum = tsum; pos=3;}
		tsum = a[4]+a[7]+a[0]+a[6]+a[2]+a[5];
		if(sum>tsum) {sum = tsum; pos=4;}
		tsum = a[4]+a[7]+a[2]+a[8]+a[0]+a[3];
		if(sum>tsum) {sum = tsum; pos=5;}
		if (pos==0) printf("BCG");
		if (pos==1) printf("BGC");
		if (pos==2) printf("CBG");
		if (pos==3) printf("CGB");
		if (pos==4) printf("GBC");
		if (pos==5) printf("GCB");
		printf(" %d\n", sum);
	}
	return 0;
}