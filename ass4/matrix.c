//Tyler Watson 260867260

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define ROWS 5
#define COLS 5



void fillMatrix(int matrix[ROWS][COLS]) { 
	srand(time(NULL)); //start at different seed every time
	int random = 0;
	for(int i=0; i<ROWS; i++) { //iterate through rows
		for(int j=0; j<COLS; j++) { //iterate through columns
			random = rand() % 100 + 1; //obtain random number
			matrix[i][j] = random; //put number into matrix
		}
	}

}

void printMatrix(int matrix[ROWS][COLS]) {
	for(int i=0; i<ROWS; i++) { //iterate through rows
                for(int j=0; j<COLS; j++) { //iterate through columns
			int val = matrix[i][j]; //store matrix value into val
                        printf("%5d", val); //print val with a width of 5
                }
		printf("\n"); //new line after row is completed
        }
	printf("\n"); //new line after entire matrix
}

void transposeMatrix(int matrix[ROWS][COLS]) {
	int tmp; 
	for(int i=0; i<ROWS; i++) { //iterate through rows
		for(int j=i; j<COLS; j++) { //iterate through columns
			tmp  = *(*(matrix + i)+j); //temp value get value at location matrix[i][j]
			//printf("*(*(matrix + %d)+%d) before: %d\n",i, j,  *(*(matrix + i) + j));
			//printf("*(*(matrix + %d)+%d) before: %d\n",j, i, *(*(matrix + j)+i));
		        *(*(matrix + i) + j) = *(*(matrix + j)+i); //using pointers set value at matrix[i][j] to value at matrix[j][i]
			*(*(matrix + j) + i) = tmp; //set value at matrix [j][i] to temp value
			//printf("*(*(matrix + %d)+%d) after: %d\n",i, j,  *(*(matrix + i) + j));
                        //printf("*(*(matrix + %d)+%d) after: %d\n",j, i, *(*(matrix + j)+i));
		
		}
	}
}

void multiplyMatrix(int m1[2][COLS], int m2[ROWS][COLS], int resultMatrix[ROWS][COLS]) {
	int val;
	for(int i=0; i<ROWS; i++) { //iterate through rows
		if(i<2) { //for each row of m1
			for(int k=0; k<COLS; k++) { //iterate though columns
				val=0;
				for(int j=0; j<COLS; j++) { //iterate through columns to perform multiplication
					//printf("i: %d, j: %d, k: %d, val: %d\n",i,j,k,val);
					val += m1[i][j]*m2[j][k]; //perform multiplication and compute total
				}
				resultMatrix[i][k]=val; //store total in new matrix
			}
		}
		else { //fill in the rest of the matrix with 0s
			for(int j=0; j<COLS; j++) {
				resultMatrix[i][j] = 0;
			}
		}
	}

}

int main(int argc, char* argv[]) {
	int matrix[ROWS][COLS];
	fillMatrix(matrix);
	printMatrix(matrix);
	transposeMatrix(matrix);
	printMatrix(matrix);
	int matrix2[2][COLS]={0,1,2,3,4,5,6,7,8,9};
	int matrixResult[ROWS][COLS];
	multiplyMatrix(matrix2, matrix, matrixResult);
	printMatrix(matrixResult);
	return 0;
	sleep(1);
}
