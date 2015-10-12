#include <stdio.h>
#include <math.h>

int main(){
	double i=1;
	printf("#include <stdio.h>\n");
	printf("int main() {\n");
	while (i++ <70000000){
			double j= sqrt(i*(i+1)/2.0);
			if (ceil(j) == j) printf("\tprintf(\"%%10d%%10d\\n\", %.0lf, %.0lf);\n",j ,i);
	}
	printf("\treturn 0;\n");
	printf("}");
	return 0;
}