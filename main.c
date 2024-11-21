#include "max.h"
#include "sum.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>

void randomArray(int seed, int numElements, int **array);

int main() {
	int size, threads, seed, task, output;
	int *array;
	char print;

	struct timeval start_wall, end_wall;
	struct rusage start_usage, end_usage;
	double wall_time, user_time, sys_time;

	printf("# of elements in list?: ");
	scanf(" %d", &size);
	printf("# of threads: ");
	scanf(" %d", &threads);
	printf("seed: ");
	scanf(" %d", &seed);
	printf("Max (1) or Sum (2): ");
	scanf(" %d", &task);
	printf("Print Results? (y/n): ");
	scanf(" %c", &print);

	randomArray(seed, size, &array);

	gettimeofday(&start_wall, NULL);
	getrusage(RUSAGE_SELF, &start_usage);

	switch (task) {
	case 1:
		output = max(array, size, threads);
		break;
	case 2:
		output = sum(array, size, threads);
		break;
	default:
		output = -1;
		break;
	}

	gettimeofday(&end_wall, NULL);
	getrusage(RUSAGE_SELF, &end_usage);

    wall_time = (end_wall.tv_sec - start_wall.tv_sec) + 
                (end_wall.tv_usec - start_wall.tv_usec) / 1e6;
    user_time = (end_usage.ru_utime.tv_sec - start_usage.ru_utime.tv_sec) + 
                (end_usage.ru_utime.tv_usec - start_usage.ru_utime.tv_usec) / 1e6;
    sys_time = (end_usage.ru_stime.tv_sec - start_usage.ru_stime.tv_sec) + 
               (end_usage.ru_stime.tv_usec - start_usage.ru_stime.tv_usec) / 1e6;


	if (print == 'Y' || print == 'y') {
		printf("Output: %d\n", output);
	}

    printf("Wall Clock Time: %f seconds\n", wall_time);
    printf("User Time: %f seconds\n", user_time);
    printf("System Time: %f seconds\n", sys_time);

	free(array);
	return 0;
}

void randomArray(int seed, int numElements, int **array) {
	int i;
	*array = (int *)calloc(numElements, sizeof(int));
	srand(seed);
	for (i = 0; i < numElements; i++) {
		(*array)[i] = rand();
	}
}

/*
	TODO: Report - Run experiments where you explore the impact of threads while computing the maximum
	value and the sum. Create a table where you increase the number of threads and the data sets. Your
	goal is to see whether using additional threads improves performance. Provide a short (one paragraph)
	explanation of your results. You will NOT be penalize if you don’t see any improvement while using
	threads. Just try to explain why. Write your report in a pdf file named report.pdf.
*/