#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

void input(int *num, int *den);
void display(int num, int den);
void simplify(int *num, int *den);
int roots(double a, double b, double c, double *x1, double *x2);

int main() {
	int n, d, qe;
	double a, b, c, x1, x2;
	char ch, ch1, ch2, choice, choice1;
	
    printf("Q1:\n\n");
    
	do {
		printf("   1. Input fraction\n\n");
		input(&n, &d);
		
		printf("\n   2. Simplify fraction\n\n");
		display(n, d);
		printf("   =\n");
		if (n == 0){
			printf("   0\n");
		} else{
			if (n != 0 && n % d == 0){
				printf("   %d\n", n / d);
			} else{
				simplify(&n, &d);
				display(n, d);
			}
		}
		
		do {
			fflush(stdin);
			printf("   Another run <y/n>? ");
			scanf("%c", &choice);
			if (choice != 'n' && choice != 'y') {
				printf("   Invalid!\n");
			}
		} while (choice != 'n' && choice != 'y');
		
		if (choice == 'n') {
			break; 
		}
		printf("\n");
	} while (1);
	
	printf("\n--------------------------------------------------------\nQ2:\n");
	
	do {
		printf("\n   1. Input coefficients of quadratic equation\n");
		while (1) {
    		printf("   Enter a, b, c: ");
    		fflush(stdin);
    		a = 0; ch = '\0'; ch1 = '\0'; ch2 = '\0';
			scanf("%lf%c%lf%c%lf%c", &a, &ch, &b, &ch1, &c, &ch2);
			if (a != 0 && ch == ' ' && ch1 == ' ' && ch2 == '\n') {
				break;
			}
			else {
				printf("   Invalid input, please re-enter!\n");
			}
		}
		
		printf("\n   2. Solve the equation\n\n");
		qe = roots(a, b, c, &x1, &x2); 
		if (qe == 0) {
			printf("   There are no real roots\n\n");
		}
		else if (qe == 1) {
			printf("   There is one real root: x0 = %lf\n\n", x1);
		}
		else {
			printf("   There are 2 real roots: x1 = %lf, x2 = %lf\n\n", x1, x2);
		}
		
		do {
			fflush(stdin);
			printf("   Another run <y/n>? ");
			scanf("%c", &choice1);
			if (choice1 != 'n' && choice1 != 'y') {
				printf("   Invalid choice. Try again.\n");
			}
		} while (choice1 != 'n' && choice1 != 'y');
		
		if (choice1 == 'n') break;
	} while (1);

	return(0);
}

void input(int *num, int *den) {
	char ch;
	
	while (1)
	{
		printf("   Enter numerator: ");
		fflush(stdin);
		scanf("%d%c", num, &ch);
		if (ch == '\n') {
			break;
		}
		else {
			printf("   Invalid numerator, please re-enter!\n");
		}
	}
	
	ch = '\0';
	while (1) {
		printf("   Enter denominator: ");
		fflush(stdin);
		scanf("%d%c", den, &ch);
		if (*den != 0 && ch == '\n') {
			break;
		}
		else {
			printf("   Invalid denominator, please re-enter!\n");
		}
	}
}

void display(int num, int den) {
	
	printf("   %d/%d\n", num, den);
}

int GCD(int a, int b){
	
	while (a!=0) {
		if (a == b) {
			break;
		}
		else {
			if (a>b) {
				a = a-b;
			}
			else {
				b = b-a;
			}
		}
	}
	return a;
}

void simplify(int *num, int *den) {
	int a = GCD( abs(*num), abs(*den));
	
	*num /= a;
	*den /= a;
}

int roots(double a, double b, double c, double *x1, double *x2) {
	double d;
	
	d = pow(b,2) - 4*a*c;
	if (d<0) {
		return(0);
	}
	else if (d == 0) {
		*x1 = -b/(2*a);
		return(1);
	}
	else {
		*x1 = (-b + sqrt(d)) /(2*a);
		*x2 = (-b - sqrt(d)) /(2*a);
		return(2);
	}
}
