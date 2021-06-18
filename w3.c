#include <stdio.h>
#include <math.h>

int CheckInteger(){	
	int number; char c;
	int check = 0;		
	do{
		fflush(stdin);
		printf("Please enter an integer: ");		
	}while(scanf("%d%c", &number, &c) != 2 || c != '\n');		
	return number;
}
int main() {
// Q1
	float a, b, c, d;
	int i, m, s, n, g;
	int o[32];
	
	printf("Q1\n");
	n = CheckInteger();
   	printf("%n", &n);	
	printf("%d in binary number format is: ", n);
	
	for (i = 0; n > 0; i++) {
		o[i] = n % 2;
		n = n/2;
	}
	
	for(i = i - 1; i >= 0; i--) {
		printf("%d", o[i]);
	}
	
	printf("\nEnter n = ");
	scanf("%d", &n);
	
	g = n; s = 0;
	while (g > 0) {
		m = g % 10;
		s = s + m;
		g = g / 10;
	}
	printf("The sum of all digits in %d is %d\n ", n, s);
	
	g = n; s = 0;
	while (g > 0) {
		d = g % 10;
		s = s*10 + d;
		g = g / 10;
	}
	
	printf("\nThe reverse number of %d is %d", n, s);
	 
// Q2
	printf("\nQ2");
	printf("\na*x^2 + b*x + c\n");
	printf("Enter a = ");
	scanf("%f", &a);
	printf("Enter b = ");
	scanf("%f", &b);
	printf("Enter c = ");
	scanf("%f", &c);
	
	if(a==0){
        if(b==0){
                if(c==0)
                    printf("The equation has countless solutions");
                else
                    printf("The equation has no solution");
        }
        else
            printf("The equation has only solution is: %f",-c/b);
    }
    else{
		d = b*b - 4*a*c;
		if 	(d < 0) {
			printf("The equation has no solution");
		}
		else if (d == 0) {
			printf("x1 = x2 = %f",-b/(2*a));
		}	
		else{
			printf("x1 = %f ,x2 = %f", (( -b + sqrt(d)) / (2*a) ), (( -b -sqrt(d)) / (2*a)));
		} 
	}
	
// Q3
	printf("\nQ3");
	printf("\nEnter m = ");
	scanf("%d", &m);
	printf("Enter n = ");
	scanf("%d", &n);
	
	while (n < m){
		printf("Re-enter m = ");
		scanf("%d", &m);
		printf("Re-enter n = ");
		scanf("%d", &n);
		if(n<m){
			printf("Re-enter m & n (m>n) \n");
		}
	}
	printf("Palindromic numbers:\n");
	
	for (i = m; i <= n; i++){
		g = i;
		s = 0;
		while (g > 0) {
			m = g % 10;
			s = s*10 + m;
			g = g/10;
			
			if (s == i){
			printf("%d ", i);
			}
		}
	}
return 0;
}
