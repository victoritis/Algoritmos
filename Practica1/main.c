#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include <stdbool.h>

double microsegundos() {
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0 )
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}

int fib1(int n){
	if(n < 2)
		return n;
	else
		return (fib1(n-1) + fib1(n-2));
}


int fib2(int n){
	int i=1, j=0, k=1;
	for(; k<=n; k++){
		j= i+j;
		i= j-i;
	}
return j;
}

int fib3(int n) {
	int i = 1, j =0, k = 0, h = 1, t;
	while ( n > 0 ) {
		if ((n % 2) != 0) {
			t = j * h;
			j = (i * h) + (j * k) + t;
			i = (i * k) + t;
		}
		t = h * h;
		h = (2 * k * h) + t;
		k = (k * k) + t;
		n = n / 2;
	}
return j;
}

void test(){
	int n;
	printf("n\t\tfib1(n)\t\tfib2(n)\t\tfib3(n)\n");
	for(n=0;n<10;n++)
		printf("%d\t\t%d\t\t%d\t\t%d\n", n+1, fib1(n), fib2(n), fib3(n));
}

void print_f1(){
    int j, i; double t1, t2, t, x, y, z;
    bool error;

    printf("\nFibonacci_1\n");
    printf("\t\tn\t\tT\t\tCota\t\tCotaSub\t\tCotaSob\t\t<500\n");
    for (i = 2; i <= 32; i = 2 * i) {
        error=false;
        t1 = microsegundos();
        fib1(i);
        t2 = microsegundos();
        t = t2 - t1;
        if (t < 500) {
            t1 = microsegundos();
            for (j = 0; j <= 10000; j++)
                fib1(i);
            t2 = microsegundos();
            t = (t2 - t1) / 10000;
            error = true;
        }
        x = t / (pow(1.1, i));
        y = t / (pow(((1 + sqrt(5)) / 2), i));
        z = t / (pow(2, i));
        printf("%17d%17.3f%20.6f%18.6f%15.6f", i, t, x, y, z);
        if(error == true)
            printf("\t\t*\n");
        else
            printf("\n");
    }
}

void printf2(){
    int j, i; double t1, t2, t, x, y, z;
    bool error;

    printf("\nFibonacci_2\n");
    printf("\t\tn\t\tT\t\tCota\t\tCotaSub\t\tCotaSob\t\t<500\n");
    for (i = 1000; i <= 10000000; i = 10 * i) {
        error=false;
        t1 = microsegundos();
        fib2(i);
        t2 = microsegundos();
        t = t2 - t1;
        if (t < 500) {
            t1 = microsegundos();
            for (j = 0; j <= 1000; j++)
                fib2(i);
            t2 = microsegundos();
            t = (t2 - t1) / 1000;
            error = true;
        }
        x = t / (pow(i, 0.8));
        y = t /  i;
        z = t / (i * log(i));
        printf("%17d%17.3f%20.6f%18.6f%15.6f", i, t, x, y, z);
        if(error == true)
            printf("\t\t*\n");
        else
            printf("\n");
    }
}

void printf3(){
    int j, i; double t1, t2, t, x, y, z;
    bool error;

    printf("\nFibonacci_3\n");
    printf("\t\tn\t\tT\t\tCota\t\tCotaSub\t\tCotaSob\t\t<500\n");
    for (i = 1000; i <= 10000000; i = 10 * i) {
        error=false;
        t1 = microsegundos();
        fib3(i);
        t2 = microsegundos();
        t = t2 - t1;
        if (t < 500) {
            t1 = microsegundos();
            for (j = 0; j <= 1000; j++)
                fib3(i);
            t2 = microsegundos();
            t = (t2 - t1) / 1000;
            error = true;
        }
        x = t / (sqrt(log(i)));
        y = t /  log(i);
        z = t / (pow(i, 0.5));
        printf("%17d%17.3f%20.6f%18.6f%15.6f", i, t, x, y, z);
        if(error == true)
            printf("\t\t*\n");
        else
            printf("\n");
    }
}

int main() {
    test();
    print_f1();
    printf2();
    printf3();
    return 0;
}

