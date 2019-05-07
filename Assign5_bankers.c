
#include <stdio.h>

void MaxInstance(int maxInstance[20], int m)
{
	int i;
	for(i = 0; i < m; i++){
		printf("Enter Maximum Instances for R%d: ", i + 1);
		scanf("%d", &maxInstance[i]);
	}
}

void MaxRequired(int max[20][20], int n, int m)
{
	int i,j;
	for(i = 0; i < n; i++){
		printf("Enter for P%d: \n", i + 1);
		for( j = 0; j < m; j++){
			printf("Enter Max Instances required of R%d: ", j + 1);
			scanf("%d", &max[i][j]);
		}
		printf("\n");
	}
}

void Allocated(int alloc[20][20], int n, int m, int maxInstance[20], int avail[20], int need[20][20], int max[20][20])
{
	int i, j;
	for( i = 0; i < m; i++){
		avail[i] = 0;
	}
	for( i = 0; i < n; i++){
		printf("Enter for P%d: \n", i + 1);
		for( j = 0; j < m; j++){
			printf("Enter Allocated Instances of R%d: ", j + 1);
			scanf("%d", &alloc[i][j]);
			avail[j] = avail[j] + alloc[i][j];
			need[i][j] = max[i][j] - alloc[i][j];
		}
		printf("\n");
	}
	for( i = 0; i < m; i++){
		avail[i] = maxInstance[i] - avail[i];
	}

}

void Display(int n, int m, int a[20][20])
{
	int i, j;
	for(i = 0; i < m; i++){
		printf("\tR%d", i+1);
	}
	printf("\n");
	for(i = 0; i < n; i++){
		printf("P%d", i + 1);
		for( j = 0; j < m; j++){
			printf("\t%d", a[i][j]);
		}
		printf("\n");
	}
}

int Safety(int n, int m, int avail[20], int alloc[20][20], int need[20][20])
{
	int i, j, flag = 1, flag2 = 1, temp, temp2 = 0;
	int finish[n], work[m], sequence[n];

	for(i = 0; i < m; i++){
		work[i] = avail[i];
	}
	for(i = 0; i < n; i++){
		finish[i] = 1;
	}
	while(1){
		flag = 0;
		for(i = 0; i < n; i++){
			if(finish[i] == 1){
				for(j = 0; j < m; j++){
					if(need[i][j] > work[j]){
						break;
					}
					if(j == m - 1){
						for(j = 0; j < m; j++){
							work[j] = work[j] + alloc[i][j];
						}
						flag = 1;
						sequence[temp2] = i;
						temp2++;
						finish[i] = 0;
					}
				}
			}
		}
		if(flag == 0)
			break;
	}
	if(temp2 == n){
		printf("Safe State\n");
		printf("Safe State Sequence:\n");
		for(i = 0; i < n; i++){
			printf("P%d\t", sequence[i]);
		}
		printf("\n");
		return 0;
	}
	else{
		printf("Unsafe State\n");
	}
	return 1;
}

int ResourceReq(int n, int m, int avail[20], int alloc[20][20], int need[20][20]){
	int request[m];
	int i, j, p, safe;
	printf("Enter Process Id: ");
	scanf("%d", &p);
	for(i = 0; i < m; i++){
		printf("Enter Instances Requires of R%d for P%d: ", i + 1, p);
		scanf("%d", &request[i]);
		if(request[i] > need[p - 1][i]){
			printf("Process Has Exceeded its Maximum Claim\n");
			return 1;
		}
	}
	for(i = 0; i < m; i++){
		if(request[i] > avail[i]){
			printf("Process In Wait State\n");
			return 1;
		}
	}
	for(i = 0; i < m; i++){
		avail[i] = avail[i] - request[i];
		alloc[p - 1][i] = alloc[p - 1][i] + request[i];
		need[p - 1][i] = need[p - 1][i] - request[i];
	}
	safe = Safety( n, m, avail, alloc, need);
	if(safe == 0){
		return 0;
	}
	else{
		printf("Reverting Allocated Resources\n");
		for(i = 0; i < m; i++){
			avail[i] = avail[i] + request[i];
			alloc[p - 1][i] = alloc[p - 1][j] - request[i];
			need[p - 1][j] = need[p - 1][j] + request[j];
		}
	}
	return 1;
}

int main()
{
	int m, n;
	int i, j, safe, a;
	int maxInstance[20], avail[20], alloc[20][20], max[20][20], need[20][20];
	printf("Enter Total Number of Process: ");
	scanf("%d", &n);
	printf("Enter Total Number of Resources: ");
	scanf("%d", &m);
	MaxInstance(maxInstance, m);
	MaxRequired(max, n, m);
	Allocated(alloc, n, m, maxInstance, avail, need, max);
	printf("Maximum  Instances\n");
	for(i = 0; i < m; i++){
		printf("R%d\t%d\n", i+1, maxInstance[i]);
	}
	printf("Available Instances\n");
	for(i = 0; i < m; i++){
		printf("R%d\t%d\n", i+1, avail[i]);
	}
	printf("\n");
	printf("Allocated: \n");
	Display(n, m, alloc);
	printf("\n");
	printf("Max Required: \n");
	Display(n, m, max);
	printf("\n");
	printf("Need: \n");
	Display(n, m, need);
	printf("\n");
	Safety( n, m, avail, alloc, need);
	int ch = 1;
	while(ch == 1){
		printf("\n");
		printf("Request Resources\n 1. Yes\n 2. No\n Enter Your Choice: ");
		scanf("%d", &ch);
		if(ch == 1){
			a = ResourceReq(n, m, avail, alloc, need);
			if(a == 0){
				printf("Resources Allocated\n");
				printf("\n");
				printf("Allocated: \n");
				Display(n, m, alloc);
				printf("\n");
				printf("Max Required: \n");
				Display(n, m, max);
				printf("\n");
				printf("Need: \n");
				Display(n, m, need);
				printf("\n");
				printf("Available Instances\n");
				for(i = 0; i < m; i++){
				printf("R%d\t%d\n", i+1, avail[i]);
				}
			}
			else
			printf("Resources Not Allocated\n");
		}
	}
	return 0;
}


// 5 3 10 5 7 7 5 3 3 2 2 9 0 2 2 2 2 4 3 3 0 1 0 2 0 0 3 0 2 2 1 1 0 0 2
