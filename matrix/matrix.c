/* matrix.c */

#include <stdio.h>
#include <stdlib.h>

void input_value(int **mat, int row, int col);
void print_matrix(int **mat, int row, int col);

main(int argc, char* argv[])
{
	if (argc < 2) {
		printf("Usage: matrix aNumber bNumber\n");
		exit(1);
	}
	
	int row = atoi(argv[1]);
	int col = atoi(argv[2]);
	int i, j;
	
	// create matrix
	int **mat1 = (int**) malloc (sizeof(int*) * row);
	int **mat2 = (int**) malloc (sizeof(int*) * row);
	int **result = (int**) malloc (sizeof(int*) * row);
	
	for (i=0; i<row; i++){
		mat1[i] = (int*) malloc (sizeof(int) * col);
		mat2[i] = (int*) malloc (sizeof(int) * col);
		result[i] = (int*) malloc (sizeof(int) * col);
	}
	
	// data input
	printf("=== input mat1 data ===\n");
	input_value(mat1, row, col);
	printf("=== input mat2 data ===\n");
	input_value(mat2, row, col);
	
	// sum matrix
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			result[i][j] = mat1[i][j] + mat2[i][j];
		}
	}

	// print matrix
	printf("=== print mat1 data ===\n");
	print_matrix(mat1, row, col);
	printf("=== print mat2 data ===\n");
	print_matrix(mat2, row, col);
	printf("=== print result data ===\n");
	print_matrix(result, row, col);
	
	// free matrix
	for (i=0; i<row; i++){
		free(mat1[i]);
		free(mat2[i]);
		free(result[i]);
	}
	free(mat1);
	free(mat2);
	free(result);
}

void input_value(int **mat, int row, int col)
{
	int i, j;
	
	for (i=0; i<row; i++){
		for (j=0; j<col; j++){
			printf("input [%d][%d] : ", i, j);
			scanf("%d", &mat[i][j]);
		}
	}
}

void print_matrix(int **mat, int row, int col)
{
	int i, j;

	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}
