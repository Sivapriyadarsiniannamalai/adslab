#include<stdio.h>
#include<conio.h>


void input();
void setunion();
void intersection();
void difference();
void output(int c[]);


int a[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
int b[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int main() {
    int ch, wish;
    clrscr();
    do {
	printf("\nMENU\n");
	printf("1. Input\n2. Union\n3. Intersection\n4. Difference\n");
	printf("Enter your choice: ");
	scanf("%d", &ch);

	switch (ch) {
	    case 1: input(); break;
	    case 2: setunion(); break;
	    case 3: intersection(); break;
	    case 4: difference(); break;
	    default: printf("Wrong choice");
	}

	printf("\nDo you wish to continue? (1 for yes / 0 for no): ");
	scanf("%d", &wish);
    } while (wish == 1);

    getch();
    return 0;
}

void input() {
    int n, e, i;

    printf("Enter the size of first set: ");
    scanf("%d", &n);
    printf("Enter the elements (1 to 9 only):\n");
    for (i = 1; i <= n; i++) {
	scanf("%d", &e);
	if (e >= 1 && e <= 9) {
	    a[e] = 1;
	} else {
            printf("Invalid element, only numbers 1-9 are allowed.\n");
        }
    }

    printf("Enter the size of second set: ");
    scanf("%d", &n);
    printf("Enter the elements (1 to 9 only):\n");
    for (i = 1; i <= n; i++) {
	scanf("%d", &e);
	if (e >= 1 && e <= 9) {
	    b[e] = 1;
	} else {
	    printf("Invalid element, only numbers 1-9 are allowed.\n");
	}
    }

    printf("\nFirst set: ");
    for (i = 1; i <= 9; i++) {
	printf("%d ", a[i]);
    }

    printf("\nSecond set: ");
    for (i = 1; i <= 9; i++) {
	printf("%d ", b[i]);
    }
}

void output(int c[]) {
    int i;
    printf("\nResulting set: ");
    for (i = 1; i <= 9; i++) {
	if (c[i] != 0) {
	    printf("%d ", i);
	}
    }
    printf("\n");
}

void setunion() {
    int i, c[10];
    for (i = 1; i <= 9; i++) {
	c[i] = a[i] | b[i];
    }
    printf("\nUnion: ");
    for (i = 1; i <= 9; i++) {
	printf("%d ", c[i]);
    }
    output(c);
}

void intersection() {
    int i, c[10];
    for (i = 1; i <= 9; i++) {
        c[i] = a[i] & b[i];
    }
    printf("\nIntersection: ");
    for (i = 1; i <= 9; i++) {
        printf("%d ", c[i]);
    }
    output(c);  
}

void difference() {
    int i, c[10];
    for (i = 1; i <= 9; i++) {
        c[i] = (a[i] == 1 && b[i] == 0) ? 1 : 0;
    }
    printf("\nDifference (A - B): ");
    for (i = 1; i <= 9; i++) {
        printf("%d ", c[i]);
    }

    output(c);
}
