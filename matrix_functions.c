/* NAME: ALOK BHAWANKAR
   ROLL NO.: 203143
   DIV: A
   BATCH: A3
   */
#include<stdio.h>

void display(int r, int c, int mat[][c]);

int compact(int r, int c, int mat[][c], int arr[][3]);

void sTrans(int cnt, int mat[][3], int arr[][3]);

void fTrans(int cnt, int mat[][3], int arr[][3]);

int main(){

	//make matrix
	int r,c;
	printf("enter number of rows and columns : ");
	scanf("%d %d", &r, &c);
	int mat[r][c];

	//take input of values into matrix
	printf("\nEnter values : \n");
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			scanf("%d", &mat[i][j]);
		}
	}

	//display matrix
	printf("\nThe matrix is : \n");
	display(r, c, mat);

	//convert to compact form
	int cMat[r*c+1][3];
	int cnt = compact(r, c, mat, cMat) + 1;

	//display compact form
	printf("\nThe compact form is : \n");
	display(cnt, 3, cMat);

	//perform fast transpose
	int fTransMat[cnt][3];

	fTrans(cnt, cMat, fTransMat);

	//display fast transpose result
	printf("\nThe result of fast transpose is : \n");
	display(cnt, 3, fTransMat);

	//perform simple transpose
	int sTransMat[cnt][3];
	sTrans(cnt, cMat, sTransMat);

	//display simple transpose result
	printf("\nThe result of simple transpose is : \n");
	display(cnt, 3, sTransMat);

}

void display(int r, int c, int mat[][c]){

	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}

}

int compact(int r, int c, int mat[][c], int arr[][3]){
	arr[0][0] = r;
	arr[0][1] = c;

	int cnt = 0;

	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){

			if(mat[i][j] != 0)
			{
				arr[++cnt][0] = mat[i][0];
				arr[cnt][1] = mat[j][0];
				arr[cnt][2] = mat[i][j];
			}

		}
	}

	arr[0][2] = cnt;

	return cnt;
}

void sTrans(int cnt, int mat[][3], int arr[][3]){

	int n = 1;
	arr[0][0] = mat[0][0];
	arr[0][1] = mat[0][1];
	arr[0][2] = mat[0][2];

	for(int i=0; i< mat[0][1]; i++){

		for(int j=1; j<cnt; j++){

			if(mat[j][1] == i){
				arr[n][0] = mat[j][1];
				arr[n][1] = mat[j][0];
				arr[n++][2] = mat[j][2];
			}
		}

	}

}

void fTrans(int cnt, int mat[][3], int arr[][3]){

	arr[0][0] = mat[0][1];
	arr[0][1] = mat[0][0];
	arr[0][2] = mat[0][2];

	int pos[mat[0][1]][2];

	for(int i=1; i<cnt; i++){
		pos[mat[i][0]][0]++;
	}

	pos[0][1] = 1;

	for(int i=1; i<mat[0][1]; i++){
		pos[i][1] = pos[i-1][0] + pos[i-1][1];

	}

	int row=0;

	for(int i=1; i<cnt; i++){

		row = pos[mat[i][1]][1];

		arr[row][0] = mat[i][1];
		arr[row][1] = mat[i][0];
		arr[row][2] = mat[i][2];

		pos[mat[i][1]][1]++;

	}

}
/* OUTPUT
enter number of rows and columns : 3 3

Enter values : 
0
1
0
2
2
0
6
0
7

The matrix is : 
0 1 0 
2 2 0 
6 0 7 

The compact form is : 
3 3 5 
0 2 1 
2 0 2 
2 2 2 
6 0 6 
6 6 7 
*/


