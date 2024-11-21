#include "max.h"
#include "sum.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	/*
		code here handles the shell input.
		 - creates array of random integer values
		 - takes command line arguments and passes to max and sum
		 - outputs the result of max and sum
		 - will handle displaying wall clock time, the user time and the system/kernel time
	*/
	int size, threads, seed, task;
	char print;
	
	printf("# of elements in list?: ");
	scanf(" %d", &size);
	printf("# of threads: ");
	scanf(" %d", &threads);
	printf("seed: ");
	scanf(" %d", &seed);
	printf("Max (1) or Sum (2): ");
	scanf(" %d", &task);
	printf("Print Results? (Y/N): ");
	scanf(" %c", &print);
}

/*
	TODO: Report - Run experiments where you explore the impact of threads while computing the maximum
	value and the sum. Create a table where you increase the number of threads and the data sets. Your
	goal is to see whether using additional threads improves performance. Provide a short (one paragraph)
	explanation of your results. You will NOT be penalize if you don’t see any improvement while using
	threads. Just try to explain why. Write your report in a pdf file named report.pdf.
*/