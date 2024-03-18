// Trey Larson

#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp);

int main(int argc, char* argv[]) {
     
     FILE *inputFile; 
     FILE *outputFile; 
     int integers;
    
     inputFile = fopen(argv[1], "r");
     
     // argument checks

	if (argv[1] == NULL) {
		printf("Please provide the input and output text file names as: %s name1.txt name2.txt\n", argv[0]);
		exit(0);
	}

	if (argv[2] == NULL) {
		printf("Please provide the input and output text file names as: %s name1.txt name2.txt\n", argv[0]);
		exit(0);
	}
     // if more than three file arguments
     if (argv[3] != NULL) {
          printf("Please don't put more than two files!");
          exit(0);
     }

     if (inputFile == NULL) {
     printf("Input file %s cannot be opened.\n", argv[1]);
     printf("Please create the input file!");
     exit(0);
     }

     int *arr = NULL;
     int index = 0;
    
     while (fscanf(inputFile, "%d", &integers) == 1) {
        arr = (int*)realloc(arr, (index + 1) * sizeof(int));
        arr[index++] = integers;
     }

     fclose(inputFile);

     // sorting the array
     for (int i = 0; i < index - 1; i++) {
        for (int j = i + 1; j < index; j++) {
          if (arr[i] > arr[j]) {
               swap(&arr[i], &arr[j]);
          }
        }
     }

     printf("The integers in file %s after sorting:\n", argv[1]);
     for (int i = 0; i < index; i++) {
        printf("%d", arr[i]);
        if (i != index - 1) {
          printf(" ");
        }
     }
     printf("\n");

     outputFile = fopen(argv[2], "w");

     // output the sorted array into the output file
     for (int i = 0; i < index; i++) {
        fprintf(outputFile, "%d", arr[i]);
        if (i != index - 1) {
          fprintf(outputFile, " ");
        }
     }
     
     // make sure to use close and free to avoid memory leaks
     fclose(inputFile);
     fclose(outputFile);
     free(arr);
    
     return 0;
}
// swap method for the selection sort
void swap(int *xp, int *yp) {
     int temp = *xp;
     *xp = *yp;
     *yp = temp;
}