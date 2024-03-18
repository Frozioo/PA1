// Trey Larson

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

     // declared variables
     FILE *inputFile;
     FILE *outputFile;
     FILE *print;
     char integers;
     int numbers;

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
     
     // printing out the integers in the inputFile
     print = fopen(argv[1], "r");
     printf("The integers in file %s:\n", argv[1]);

     while((integers = fgetc(print)) != EOF) {
          printf("%c", integers);
     }

     // creation of the output file
     outputFile = fopen(argv[2], "w");
     printf("\n");
     printf("The integers in file %s:\n", argv[2]);
     
     do {
          numbers = fgetc(inputFile);
          if(feof(inputFile)) {
               break;
          }
          printf("%c", numbers);
          fputc(numbers, outputFile);
     } while(1);
     
     // can't forget to close opened files
     fclose(inputFile);
     fclose(outputFile);
     fclose(print);

     return 0;
}