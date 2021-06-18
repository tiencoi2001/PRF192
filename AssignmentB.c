#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX_book 100
#define SPACE_menu 30 
typedef enum {false, true} bool;

struct bookstore {
	char code[11]; 
	char title[31];
	int quantity;
	double price;
	double value;
} bkinstck[MAX_book];
double total;

void print_space(int x);
bool dupcheck_code(char code[11], int k);
void input_code(int x);
bool dupcheck_title(char title[31], int k);
void input_title(int x);
void input_quantity(int x);
void input_price(int x);
void value(int x);
void value_total(int k);
void enterlist(int *k);
void display_header(void);
void display_1row(int x); 
void display_full(int k);
void swap(int a, int b);
void sortASC(int k);
int loadf(int *line, int *k);
void loadfile(int *k);
void fstmax(int k);
void display_fheader(void);
bool find(int k, int pos[], int *j);
void edit_code(int x, int k);
void edit_title(int x, int k);
void edit_quantity(int x);
void edit_price(int x);
void findnedit(int k, int pos[], int j);
void delele_book(int x, int *k);
void findndelete(int *k, int pos[], int j);
void menu(void);
int main() {
	int pos[MAX_book];
	int choice;
	char ch; 
	int k = 0;
	int j = 0;
	
	while (1) {
		while (1) {
			system("cls");
			menu();
			printf("\n");
			print_space(SPACE_menu);
		    printf("Enter your selection (0 -> 7): ");
			fflush(stdin); 
			ch = '\0';
			scanf("%d%c", &choice, &ch);
			if (choice >= 0 && choice <= 7 && ch == '\n') {
				break;
			}
			print_space(SPACE_menu);
			printf("Your selection is incorrect\n");
			printf("\n\n");
			printf("Press any key to continue...");
	      	getch();
		}
		printf("\n");
		
		if (choice == 0) {
			break;
		}

		switch (choice) {
			case 1: {
				enterlist(&k);
				break;
			}
			case 2: {
				if (k == 0) {
					print_space(SPACE_menu);
					printf("Please input data first.\n");
				}
				else display_full(k);
				break;
			}
			case 3: {
				if (k == 0) {
					print_space(SPACE_menu);
					printf("Please input data first.\n");
				}
				else sortASC(k);
				break;
			}
			case 4: {
				loadfile(&k);
				break;
			}
			case 5: {
				if (k == 0) {
					print_space(SPACE_menu);
					printf("Please input data first.\n");
				}
				else fstmax(k);
				break;
			}
			case 6: {
				if (k == 0) {
					print_space(SPACE_menu);
					printf("Please input data first.\n");
				}
				else findnedit(k, pos, j);
				break;
			}
			case 7: {
				if (k == 0) {
					print_space(SPACE_menu);
					printf("Please input data first.\n");
				}
				else findndelete(&k, pos, j);
				break;
			}
		}
		printf("\n");
		printf("Press any key to continue...");
      	getch();
	}

	return (0);
}

void print_space(int x) {
	int i;
	
	for (i = 1; i <= x; i++) {
		printf(" ");
	}
}

bool dupcheck_code(char code[11], int k) {
	int i;
	
	for (i = 0; i < k; i++) {
		if (strcmp(bkinstck[i].code, code) == 0) {
			return(true);
		}
	}
	return(false);
}

void input_code(int x) {
	char code[11];
	
	while (1) {
		print_space(SPACE_menu/2);
		printf(" Enter code (enter STOP to stop): "); 
		fflush(stdin);
		strcpy(code, "");
		scanf("%10[^\n]", code);
		if (strlen(code) > 0) {
			if (dupcheck_code(code, x) == true) {
				print_space(SPACE_menu/2);
				printf(" The code %s already exists, please re-enter!\n", code);
			}
			else {
				strcpy(bkinstck[x].code, code);
				break;
			}
		}
		else {
			print_space(SPACE_menu/2);
			printf(" Invalid code, please re-enter!\n");
		}
	}
}

bool dupcheck_title(char title[31], int k) {
	int i;
	
	for (i = 0; i<k; i++) { 
		if (strcmp(bkinstck[i].title, title) == 0) {
			return(true);
		}
	}
	return(false);
}

void input_title(int x) {
	char title[31];
	
	while (1) {
		print_space(SPACE_menu/2);
		printf(" Enter title: "); 
		fflush(stdin);
		strcpy(title, "");
		scanf("%30[^\n]", title);
		if (strlen(title) > 0) {
			if (dupcheck_title(title, x) == true) {
				print_space(SPACE_menu/2);
				printf(" The title %s already exists, please re-enter!\n", title);
			}
			else {
				strcpy(bkinstck[x].title, title);
				break;
			}
		}
		else {
			print_space(SPACE_menu/2);
			printf(" Invalid title, please re-enter!\n");
		}
	}
}

void input_quantity(int x) {
	char ch;
	
	while (1) {
		print_space(SPACE_menu/2);
		printf(" Enter quantity: "); 
		fflush(stdin);
		ch = '\0';
		scanf("%d%c", &bkinstck[x].quantity, &ch);
		if ((bkinstck[x].quantity > 0) && (ch == '\n')) {
			break;
		}
		else {
			print_space(SPACE_menu/2);
			printf(" Invalid quantity, please re-enter!\n");
		}
	}
}

void input_price(int x) {
	char ch;
	
	while (1) {
		print_space(SPACE_menu/2);
		printf(" Enter price: "); 
		fflush(stdin);
		ch = '\0';
		scanf("%lf%c", &bkinstck[x].price, &ch);
		if ((bkinstck[x].price > 0) && (ch == '\n')) {
			break;
		}
		else {
			print_space(SPACE_menu/2);
			printf(" Invalid price, please re-enter!\n");
		}
	}
}

void value(int x) {
	bkinstck[x].value = bkinstck[x].quantity * bkinstck[x].price;
}

void value_total(int k) {
	int i;
	
	total = 0;
	for (i = 0; i<k; i++) {
		total += bkinstck[i].value;
	}
}

void enterlist(int *k) {
	int book = 1;
	char stop[5] = "STOP";
	char c;
	int n, i;

	print_space(SPACE_menu/2);
	printf("Enter number of books: ");
    
    while (scanf("%d%c", &n, &c) != 2 || c != '\n' ){
    	 
    	fflush(stdin);
    	printf("Number of books must be a integer, please re-enter!\n");
    	printf("Enter number of books: ");
	}
	
	for (i = 0; i < n; i++) {
			print_space(SPACE_menu/2);
			printf("Book %d:\n", book);
			input_code(*k);
			if 	(strcmp(bkinstck[*k].code, stop) == 0) {
			     break;
			}
			input_title(*k);
			input_quantity(*k);
			input_price(*k);
			value(*k);
			book++;
			(*k)++;
		}
	value_total(*k);
}

void display_header(void) {
	print_space(SPACE_menu/2);
	printf("+------------+--------------------------------+----------+------------+------------+\n");
	print_space(SPACE_menu/2);
	printf("| %-10s | %-30s | %8s | %10s | %10s |\n", "Code", "Title", "Quantity", "Price", "Value");
	print_space(SPACE_menu/2);
	printf("+------------+--------------------------------+----------+------------+------------+\n");
}

void display_1row(int x) {
	printf("| %-10s | %-30s | %8d | %10.1lf | %10.1lf |\n", bkinstck[x].code, bkinstck[x].title, bkinstck[x].quantity, bkinstck[x].price, bkinstck[x].value);
}

void display_full(int k) {
	int i;
	
	display_header();
	for (i = 0; i < k; i++) {
		print_space(SPACE_menu/2);
		display_1row(i);
	}
	print_space(SPACE_menu/2);
	printf("+------------+--------------------------------+----------+------------+------------+\n");
	
	print_space(SPACE_menu/2);
	printf("|                                                          Total value: %-10.1lf |\n", total);
	print_space(SPACE_menu/2);
	printf("+----------------------------------------------------------------------------------+\n");
}

void swap(int a, int b) {
	char temp_code[11]; 
	char temp_title[31];
	int temp_quantity;
	double temp_price;
	double temp_value;
	
	strcpy(temp_code, bkinstck[a].code);
	strcpy(bkinstck[a].code, bkinstck[b].code);
	strcpy(bkinstck[b].code, temp_code);
	
	strcpy(temp_title, bkinstck[a].title);
	strcpy(bkinstck[a].title, bkinstck[b].title);
	strcpy(bkinstck[b].title, temp_title);
	
	temp_quantity = bkinstck[a].quantity;
	bkinstck[a].quantity = bkinstck[b].quantity;
	bkinstck[b].quantity = temp_quantity;
	
	temp_price = bkinstck[a].price;
	bkinstck[a].price = bkinstck[b].price;
	bkinstck[b].price = temp_price;
	
	temp_value = bkinstck[a].value;
	bkinstck[a].value = bkinstck[b].value;
	bkinstck[b].value = temp_value;	
}

void sortASC(int k) {
	int i, j;
	
	if(k == 1 ){
		print_space(SPACE_menu);
		printf("ONLY 1 book, don't need sort.");
	}else{
	for (i = k - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (strcmp(bkinstck[j].code, bkinstck[j+1].code) > 0) {
				swap(j, j+1);
			}
		}
	}
	print_space(SPACE_menu/2);
	printf("Successfull.\n");
	}
}

int loadf(int *line, int *k) {
	FILE *fp;
	char header[3][72], last[72], tcode[11], ttitle[31], temp[100];
	int val, tquantity;
	double tprice;
	
	*line = 1; val = 0;
	fp = fopen("bookstore.txt", "r");
	if (fp == NULL) {
		fclose(fp);
		return 1;
	}
	else {
		if (fscanf(fp, "%s", temp) == EOF) {
			fclose(fp);
			return 2;
		}
		else rewind(fp);
		while (!feof(fp)) {
			val = 0;
			val = fscanf(fp, "%71[^\n]\n", header[0]);
			if (val == EOF || (strcmp(header[0], "+------------+--------------------------------+----------+------------+") != 0)) {
				fclose(fp);
				return 3;
			}
			else {
				(*line)++; val = 0;
				val = fscanf(fp, "%71[^\n]\n", header[1]); 
				if (val == EOF || strcmp(header[1], "| Code       | Title                          | Quantity |      Price |") != 0) {
					fclose(fp);
					return 3;
				}
				else {
					(*line)++; val = 0;
					val = fscanf(fp, "%71[^\n]\n", header[2]);
					if (val == EOF || strcmp(header[2], "+------------+--------------------------------+----------+------------+") != 0) {
						fclose(fp);
						return 3;
					}
					else {
						(*line)++;
						while (1) {
							val = 0;
							val = fscanf(fp, "| %10[^ |] | %30[^ |] | %8d | %10lf |\n", tcode, ttitle, &tquantity, &tprice);

							if (val == 4) {
								if (strlen(tcode) > 0 && strlen(tcode) <= 10 && dupcheck_code(tcode, *k) == true) {
									fclose(fp);
									return 4;
								}
								else if (strlen(ttitle) > 0 && strlen(ttitle) <= 30 && dupcheck_title(ttitle, *k) == true) {
									fclose(fp);
									return 5;	
								}
								else if (tquantity < 0) {
									fclose(fp);
									return 6;
								}
								else if (tprice < 0) {
									fclose(fp);
									return 7;
								}
								else {
									strcpy(bkinstck[*k].code, tcode);
									strcpy(bkinstck[*k].title, ttitle);
									bkinstck[*k].quantity = tquantity;
									bkinstck[*k].price = tprice;				
									(*k)++;
								}
							}
							else {
								val = 0;
								val = fscanf(fp, "%s", last);
								if (val == EOF || strcmp(last, "+------------+--------------------------------+----------+------------+") != 0) {
									fclose(fp);
									return 3;
								}
								else {
									fclose(fp);
									return 0;
								}
							}
							(*line)++;
						}
					}
				}
			}
		}
	}
}

void loadfile(int *k) {
	int errcode, line = 0;
	int frstk = *k, i;

	print_space(SPACE_menu/2);
	printf("Load data from file bookstore.txt:\n");
	errcode = loadf(&line, k);
	for (i = frstk; i < *k; i++) {
		value(i);
	}
	value_total(*k);
	
	if (errcode == 0) {
		print_space(SPACE_menu/2);
		printf("Load successfully %d books from file bookstore.txt!\n", *k - frstk);
	}

	switch (errcode) {
		case 1: {
			print_space(SPACE_menu/2);
			printf("[Error] file does not exists!\n");
			break;
		}
		case 2: {
			print_space(SPACE_menu/2);
			printf("[Error] file empty!\n");
			break;
		}
		case 3: {
			if (line > 3) {
				print_space(SPACE_menu/2);
				printf("Load successfully %d books with: ", *k - frstk);
			}
			printf("[Error] Invalid format (line %d).\n", line);
			break;
		}
		case 4: {
			if (line > 3) {
				print_space(SPACE_menu/2);
				printf("Load successfully %d books with: ", *k - frstk);
			}
			printf("[Error] Code duplicated (line %d).\n", line);
			break;
		}
		case 5: {
			if (line > 3) {
				print_space(SPACE_menu/2);
				printf("Load successfully %d books with: ", *k - frstk);
			}
			printf("[Error] Title duplicated (line %d).\n", line);
			break;
		}
		case 6: {
			if (line > 3) {
				print_space(SPACE_menu/2);
				printf("Load successfully %d books with: ", *k - frstk);
			}
			printf("[Error] Invalid quantity  (line %d).\n", line);
			break;
		}
		case 7: {
			if (line > 3) {
				print_space(SPACE_menu/2);
				printf("Load successfully %d books with: ", *k - frstk);
			}
			printf("[Error] Invalid price  (line %d).\n", line);
			break;
		}
	}
}

void fstmax(int k) {
	double max;
	int pos, i;
	
	max = bkinstck[0].price; pos = 0;
	for (i = 1; i<k; i++) {
		if (max < bkinstck[i].price) {
			max = bkinstck[i].price;
			pos = i;
		}	
	}
	print_space(SPACE_menu/2);
	printf("Here is the (first) max price:\n");
	display_header();
	print_space(SPACE_menu/2);
	display_1row(pos);
	print_space(SPACE_menu/2);
	printf("+------------+--------------------------------+----------+------------+------------+\n");
}

void display_fheader(void) {
	print_space(SPACE_menu/2);
	printf("+--------+------------+--------------------------------+----------+------------+------------+\n");
	print_space(SPACE_menu/2);
	printf("| %-6s | %-10s | %-30s | %8s | %10s | %10s |\n", "Number", "Code", "Title", "Quantity", "Price", "Value");
	print_space(SPACE_menu/2);
	printf("+--------+------------+--------------------------------+----------+------------+------------+\n");
}

bool find(int k, int pos[], int *j) {
	char code[11], *b, temp[11];
	bool check;
	int i;
	
	while (1) {
		print_space(SPACE_menu/2);
		printf("Enter code you want to find: ");
		fflush(stdin);
		gets(code);
		if ((strlen(code) > 0) && (strlen(code) <= 10)) {
			break;
		}
		else {
			print_space(SPACE_menu/2);
			printf("Invalid code, please re-enter!\n");
		}
	}
	
	*j = 0;
	for (i = 0; i < k; i++) {
		strcpy(temp, bkinstck[i].code);
		b = strstr(temp, code);
		if (b != NULL) { 
			pos[*j] = i;
			(*j)++;
			strcpy(b, "\0");
		}
	}
	
	if (*j > 0) {
		print_space(SPACE_menu/2);
		printf("Here is the list which matched with '%s':\n", code);
		display_fheader();
		for (i = 0; i < *j; i++) {
			print_space(SPACE_menu/2);
			printf("| %-6d ", i);
			display_1row(pos[i]);
		}
		print_space(SPACE_menu/2);
		printf("+--------+------------+--------------------------------+----------+------------+------------+\n");
		printf("\n");
		check = true;		
	}
	else {
		print_space(SPACE_menu/2);
		printf("None of these book are match with code '%s'.\n", code);
		check = false;		
	}
	
	return(check);
}

void edit_code(int x, int k) {
	char code[11];
	
	while (1) {
		print_space(SPACE_menu/2);
		printf(" Enter code: "); 
		fflush(stdin);
		gets(code);
		if ((strlen(code) > 0) && (strlen(code) <= 10)) {
			if (strcmp(code, "-1") == 0) {
				break;
			}		
			else if (dupcheck_code(code, k) == true) {
				print_space(SPACE_menu/2);
				printf(" The code %s already exists, please re-enter!\n", code);
			}
			else {
				strcpy(bkinstck[x].code, code);
				break;
			}
		}
		else {
			print_space(SPACE_menu/2);
			printf(" Invalid code, please re-enter!\n");
		}
	}
}

void edit_title(int x, int k) {
	char title[31];
	
	while (1) {
		print_space(SPACE_menu/2);
		printf(" Enter title: "); 
		fflush(stdin);
		gets(title);
		if ((strlen(title) > 0) && (strlen(title) <= 30)) {
			if (strcmp(title, "-1") == 0) {
				break;
			}		
			else if (dupcheck_title(title, k) == true) {
				print_space(SPACE_menu/2);
				printf(" The title %s already exists, please re-enter!\n", title);
			}
			else {
				strcpy(bkinstck[x].title, title);
				break;
			}
		}
		else {
			print_space(SPACE_menu/2);
			printf(" Invalid title, please re-enter!\n");
		}
	}
}

void edit_quantity(int x) {
	char ch;
	int quantity;
	
	while (1) {
		print_space(SPACE_menu/2);
		printf(" Enter quantity: "); 
		fflush(stdin);
		ch = '\0';
		scanf("%d%c", &quantity, &ch);
		if ((quantity == -1) && (ch == '\n')) {
			break;
		}
		else if ((quantity > 0) && (ch == '\n')) {
			bkinstck[x].quantity = quantity;
			break;
		}
		else {
			print_space(SPACE_menu/2);
			printf(" Invalid quantity, please re-enter!\n");
		}
	}
}

void edit_price(int x) {
	char ch;
	double price;
	
	while (1) {
		print_space(SPACE_menu/2);
		printf(" Enter price: "); 
		fflush(stdin);
		ch = '\0';
		scanf("%lf%c", &price, &ch);
		if ((price == -1) && (ch == '\n')) {
			break;
		}
		else if ((price > 0) && (ch == '\n')) {
			bkinstck[x].price = price;
			break;
		}
		else {
			print_space(SPACE_menu/2);
			printf(" Invalid price, please re-enter!\n");
		}
	}
}

void findnedit(int k, int pos[], int j) {
	int choice;
	char ch, confirm;
	bool check;
	
	check = find(k, pos, &j);
	if (check == true) {
		do {
			while (1) {
				print_space(SPACE_menu/2);
				printf("Enter number (0-%d): ", j-1);
				fflush(stdin); ch = '\0';
				scanf("%d%c", &choice, &ch);
				if ((choice >= 0) && (choice < j) && (ch == '\n')) {
					break;
				}
				else {
					print_space(SPACE_menu/2);
					printf("Your selection is incorrect!\n"); 
				}
			}
			
			do {
				print_space(SPACE_menu/2);
				printf("Do you want to edit line number %d <y/n>? ", choice);
				fflush(stdin);
				scanf("%c", &confirm);
				if ((confirm != 'n') && (confirm != 'y')) {
					print_space(SPACE_menu/2);
					printf("Your selection is incorrect!\n"); 
				}
			} while ((confirm != 'n') && (confirm != 'y'));	
			printf("\n");
		} while (confirm == 'n');
		
		print_space(SPACE_menu/2);
		printf("Enter your new information, if you want to keep it, enter -1 \n");
			
		edit_code(pos[choice], k);
		edit_title(pos[choice], k);
		edit_quantity(pos[choice]);
		edit_price(pos[choice]);
		value(pos[choice]);
		value_total(k);
		
		print_space(SPACE_menu/2);
		printf("Your book after edit:\n");
		display_header();
		print_space(SPACE_menu/2);
		display_1row(pos[choice]);
		print_space(SPACE_menu/2);
		printf("+------------+--------------------------------+----------+------------+------------+\n");
		printf("\n");
	}	
}

void delele_book(int x, int *k) {
	int i;
	
	for (i = x; i <= *k-2; i++) {
		strcpy(bkinstck[i].code, bkinstck[i+1].code);
		strcpy(bkinstck[i].title, bkinstck[i+1].title);
		bkinstck[i].quantity = bkinstck[i+1].quantity;
		bkinstck[i].price = bkinstck[i+1].price;
		bkinstck[i].value = bkinstck[i+1].value;
	}
	--*k;
}

void findndelete(int *k, int pos[], int j) {
	int choice;
	char ch, confirm;
	bool check;
	
	check = find(*k, pos, &j);
	if (check == true) {
		do {
			while (1) {
				print_space(SPACE_menu/2);
				printf("Enter number (0-%d): ", j-1);
				fflush(stdin); ch = '\0';
				scanf("%d%c", &choice, &ch);
				if ((choice >= 0) && (choice < j) && (ch == '\n')) {
					break;
				}
				else {
					print_space(SPACE_menu/2);
					printf("Your selection is incorrect!\n"); 
				}
			}
			
			do {
				print_space(SPACE_menu/2);
				printf("Do you want to delete line number %d <y/n>? ", choice);
				fflush(stdin);
				scanf("%c", &confirm);
				if ((confirm != 'n') && (confirm != 'y')) {
					print_space(SPACE_menu/2);
					printf("Your selection is incorrect!\n"); 
				}
			} while ((confirm != 'n') && (confirm != 'y'));
			printf("\n");
		} while (confirm == 'n');
		
		delele_book(pos[choice], k);
		value_total(*k);
		print_space(SPACE_menu/2);
		printf("Successfull.\n");
	}	
}

void menu(void) {
	print_space(SPACE_menu);
	printf(".---------------------------------------.\n");
	print_space(SPACE_menu);
	printf("|             BOOK IN STOCK             |\n");
	print_space(SPACE_menu);
	printf(":---------------------------------------:\n");
	print_space(SPACE_menu);
	printf("|  1. Enter the list of books           |\n");
	print_space(SPACE_menu);
	printf("|  2. Display the list of books         |\n");
	print_space(SPACE_menu);
	printf("|  3. Sort the list of books by code    |\n");
	print_space(SPACE_menu);
	printf("|  4. Load data from file               |\n");
	print_space(SPACE_menu);
	printf("|  5. Find the (first) max price        |\n");
	print_space(SPACE_menu);
	printf("|  6. Find by code and edit the book    |\n");
	print_space(SPACE_menu);
	printf("|  7. Find by code and delete the book  |\n");
	print_space(SPACE_menu);
	printf("|  0. Exit                              |\n");
	print_space(SPACE_menu);
	printf(":_______________________________________:\n");
}
