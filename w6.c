#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

void menu(void);
int input(float a[]);
void display(float a[], int n);
void bubblesort (float a[], int size);
int find (float search, float a[], int size, int pos[]);
int count, i;

int main() {
	float a[100], x;
	int choice, pos[100], rc, n = 0, i;
	char ch;
	
	while (1) {
		while (1) {
			system("cls");
			menu();
			printf("                     Enter your selection (0 -> 4): ");
			fflush(stdin); 
			ch = '\0';
			scanf("%d%c", &choice, &ch);
			printf("\n");
			if (choice >= 0 && choice <= 4 && ch == '\n') {
				break;
			}
			printf("                     Your selection is incorrect\n");
			printf("\n");
			printf("           Press any key to continue...\n");
	      	getch();
		}
		
		
		if (choice == 0) {
			break;
		}
		switch (choice) {
			case 1: {
				n = input(a);
				break;
			}
			case 2: {
				if (n == 0) printf("           Please enter number first.\n");
				else {
					bubblesort(a, n);
					printf("           Successful.\n");
					display(a, n);	
				}
				break;
			}
			case 3: {
				if (n == 0) printf("           Please enter number first.\n");
				else {
				 	while (1) {
					 	printf("           Enter the value x to be searched: ");
					 	fflush(stdin);
					 	ch = '\0';
					 	scanf("%f%c", &x, &ch);
					 	if (ch == '\n') {
					 		break;
						}
						printf("           Invalid input, please re-enter!\n\n");
					}
					for (i = 0; i < n; i++){
						if (a[i] == x){
							count = 0;
							break;
						} else {
							count = 1;
						}
					}
					if (count == 0){
						rc = find(x, a, n, pos);
						printf("           Found %.2f at position:", x);
						for (i = 0; i<rc; i++) printf(" %d", pos[i]);
						} else if (count == 1){
						printf("           %.2f is not found.\n", x);
					}
				}
				break;
			}
			case 4: {
				if (n == 0) printf("           Please enter number first.\n");
				else display(a, n);
				break;
			}
		}
		printf("\n");
		printf("           Press any key to continue...\n");
      	getch();
	}
	return (0);
}

void menu(void) {
	printf("                     +---------------------------------------+\n");
	printf("                     |         Array of real numbers         |\n");
	printf("                     +---------------------------------------+\n");
	printf("                     | 1. Enter the list of float numbers    |\n");
	printf("                     | 2. Sort the list in inceasing order   |\n");
	printf("                     | 3. Search the value x in the list     |\n");
	printf("                     | 4. Display the list                   |\n");
	printf("                     | 0. Exit                               |\n");
	printf("                     +---------------------------------------+\n\n");
}

int input(float a[]) { 
 	int n, x;
 	char ch[100], c;
 	
 	while (1) {
	 	printf("           Input the size of array n = ");
	 	fflush(stdin);
	 	c = '\0';
	 	scanf("%d%c", &n, &c);
	 	if (n>0 && c == '\n') {
	 		break;
		}
		printf("           Invalid input, please re-enter!\n\n");
	}
	
	while (1) {
		printf("           Enter %d float number: ", n);
		c = '\0';
		for ( i = 0; i<n; i++) {
			scanf("%f", &a[i]);
			if (i == (n-1)) {
				c = getchar();
			}
		}
		if (c == '\n') {
			break;
		}
		printf("           Invalid input, please re-enter!\n\n");
		fflush(stdin);	 	
	}

	return (n);
}

void display(float a[], int n) {
	printf("           Position: ");
	for ( i = 0; i<n; i++) {
		printf("%-9d", i);
	}
	printf("\n           Value:    ");
	for ( i = 0; i<n; i++) {
		printf("%-9.2f", a[i]);
	}
	printf("\n");
}

void bubblesort (float a[], int size) {
	int i, j;
	float temp;
	
	for (i = size - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (a[j] > a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

int find (float search, float a[], int size, int pos[]) {
	int j = 0, i;
	
	for ( i = 0; i < size; i++) {
		if (search == a[i]) {
			pos[j] = i;
			j++;
		}
	}
	return j;
}
