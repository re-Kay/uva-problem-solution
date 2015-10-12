#include <stdio.h>
int main(){
	unsigned long oa,ob,a,b,i,n,cnt, max;
	while(scanf("%ld%ld",&oa,&ob)!=EOF){
		if (oa>ob) {a=ob;b=oa;} else {a=oa;b=ob;}
		max=0;
		for (i=a; i<=b; i++){
			n=i;
			cnt=1;
			while(n!=1){
				if (n&1) n>>1; else n=3*n+1;
				cnt++;
			}
			max = cnt >max ? cnt :max ;
		}
		printf("%ld %ld %ld\n", oa, ob, max);
	}
	return 0;
}