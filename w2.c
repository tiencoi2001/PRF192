#include <stdio.h>
#include <math.h>
#include <stdbool.h>

float ps(int ts,int ms){
	return (float)ts/ms;
}

int checkPrime(int needCheckNumber){
	int i; 
	if(needCheckNumber==0 || needCheckNumber==1){
		return 1;
	}
	for( i = 2; i <= sqrt(needCheckNumber); i++){
		if(needCheckNumber%i==0){
			return 1;
		}
	}
	return 0;
}


int main (){
	int n, S1, S2, d, i, j; float S3;
	int m, min, max, lcm, gcd, h ;
// Q1
	printf("Q1");
    printf("\nEnter n = ");
	scanf("%d", &n);
	while (true){	
    	if(n <= 5){
    		printf("n must be > 5, please re-enter");
    	    printf("\nRe-enter n = ");
    	    scanf("%d", &n);
		}
		else break;
	}
    S1 = 0; S2 = 1; S3 = 0;
	for (i = 1; i<=n; i++)	{
		S1 = S1 + i;
		S2 = S2 * i;
		S3 = S3 + ps(1,i);
	}
	printf("S1 = %d\n", S1);
	printf("S2 = %d\n", S2);
	printf("S3 = %.4f\n", S3);
	printf("Enter n = ");
	scanf("%d", &n);
    if(n < 2){
        printf("\n%d is not a prime number",n);
    }
	d = 0;
    for(j = 2; j <= sqrt(n); j++){
        if(n % j == 0){
            d++;
        }
    }
    if(d == 0){
        printf("%d is a prime number",n);
    }else{
        printf("%d is not prime number",n);
    }
    
    
    
// Q2
	printf("\nQ2");
	printf("\nEnter m = ");	
	scanf("%d",&m);
	printf("Enter n = ");	
	scanf("%d",&n);
	if(m > n){
		min = n; max = m;
	}else{
		min = m; max = n;
	}
	
	printf("Common prime dividers: ");
	for (i = 1; i < min; i++){
		if(m % i == 0 && n % i == 0){
			if(checkPrime(i) == 0){
				printf("%d ", i);
			}
		}
	}

	for (i = 1; i <= min; i++){
		if(m % i == 0 && n % i == 0){
			gcd = i;
		}
	}
	printf("\nGCD(%d, %d) = %d", m, n, gcd);

	lcm = m*n;
	for (j = max; j < lcm; j +=max){
		if(j % m == 0 && j % n == 0){
			lcm = j;
		}
	}
	printf("\nLCM(%d, %d) = %d",m,n,lcm);
   	return 0;
}
