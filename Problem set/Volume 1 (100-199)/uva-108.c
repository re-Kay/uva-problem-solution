#include <stdio.h>
int main(){
	int n;
	while (scanf("%d",&n)!=EOF){
		int i,j,k,max=-128,a[102][102];
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				scanf("%d",&a[i][j]);	
		for (k=n-1;k>=0;k--){
			for (j=0;j<n;j++)
				for (i=k+1;i<n;i++)
					a[i][j]+=a[k][j];
			for (i=k;i<n;i++){
				int sum=a[i][0];
				for (j=1;j<n;j++){
					sum+=a[i][j];
					if (sum<a[i][j])sum=a[i][j];
					if (max<sum) max=sum;
				}
			}
		}	
		printf("%d\n",max);
	}
	return 0;
}