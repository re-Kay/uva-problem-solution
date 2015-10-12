#include <stdio.h>
int a[40];
void flip(int x){
	for (i=0;i<(x+1)/2;i++){
		int temp=a[i];
		a[i]=a[x-i];
		a[x-i]=temp;
	}
}
int main(){
	while (scanf("%d", &a[0]) != EOF) {
		int i, n = 1, shifted=-1;									
		if (getchar() != '\n')  						
            while (scanf("%d", &a[n++]))  
                if (getchar() == '\n')  break;	
		for (i=0;i<n;i++) 
			printf("%d ",a[i]);
		printf ("\n");
		while(++shifted<n-1){
			int maxPos=0;
			for (i=1;i<n-shifted;i++)
				if(a[maxPos]<a[i]) maxPos=i;
			if (maxPos!=n-1-shifted){
				if (maxPos!=0){
					printf("%d ", n-maxPos);
					flip(maxPos);
				}
				flip(n-1-shifted);
			}
		}
		printf("%d\n",0);
	}
	return 0;
}