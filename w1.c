#include <stdio.h>
#include <math.h>
int main()
{
 float a, b, c, x, S1, d, S2, p=0;
 int o[100]; int n, i, j; float max, min;
// Q1 
 printf("Q1\n");
 printf("a = "); scanf("%f", &a);
 printf("b = "); scanf("%f", &b);
 printf("c = "); scanf("%f", &c);
 printf("x = "); scanf("%f", &x);
 
 S1 = a*x*x+b*x+c; printf("S1 = %f\n",S1);
 d = b*b-4*a*c;
 if (d > 0){
 	S2 = sqrt(b*b-4*a*c);
  	printf("S2 = %f\n",S2);
 }else {
 	printf("S2 = 0\n");
 }
 
 printf("a = "); 
 scanf("%f",&a);
 printf("b = "); 
 scanf("%f",&b);
 printf("c = "); 
 scanf("%f",&c);
  
	if((a<b+c) && (b<a+c) && (c<b+a)) {
	  p = (a+b+c)/2; 
	  printf("perimeter = %f\n",p*2);
	  S1 = sqrt(p*(p-a)*(p-b)*(p-c));
	  printf("area = %f\n", S1);
	} 
else printf("a b c are not side of a triangle\n");

// Q2
	printf("\nQ2\n");
    printf("Enter n = ");
    
	do{
        scanf("%d", &n);
        if(n <= 0){
            printf("\nRe-enter n = ");
        }
    }
	
	while(n <= 0);
    for(i = 1; i <= n; i++){
        printf("\nEnter a[%d] = ",i);
        scanf("%d", &o[i]);
    }
    
    int tg;
    for(i = 1; i < n ; i++){
        for(j = i + 1; j <= n; j++){
            if(o[i] > o[j]){
                tg = o[i];
                o[i] = o[j];
                o[j] = tg;        
            }
        }
    }
    
    min = o[1]; printf("\nMin = %f  ",min);
    max = o[n]; printf("Max = %f  \n",max);

	for( i = 1; i <= n; i++){
        printf("%5d", o[i]);
    }
    return 0;
}
