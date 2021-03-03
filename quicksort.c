#include <stdio.h>
#include <time.h>

void quicksort(int *a, int left, int right){
	if(left == right) return;
	int part = right - 1;
	int plan = 0;
	int temp;
	while(plan < part){
		if(a[plan] <= a[part]){
			plan++;
			continue;
		}
		temp = a[plan];
		a[plan] = a[part - 1];
		a[part - 1] = a[part];
		a[part] = temp;
		part--;
	}
	quicksort(a, left, part);
	quicksort(a, part + 1, right);
}

void bubblesort(int *a, int N){
	int temp;
	for(int i = 0; i < N - 1; i++){
		for(int j = 0; j < N - i - 1; j++){
			if(a[j] > a[j + 1]){
				temp = a[j]; a[j] = a[j + 1]; a[j + 1] = temp;
			}
		}
	}		
}

int main(){
	srand(time(NULL));
	int N;
	scanf("%i", &N);
	int arr1[N];
	int arr2[N];
	for(int i = 0; i < N; i++){
		arr2[i] = arr1[i] = rand();
		//printf("%i ", arr1[i]);
	}
	//printf("\n");
	double start = clock();
	quicksort(arr1, 0, N);
	printf("%.4lf ", (clock() - start) / CLOCKS_PER_SEC);
	
	start = clock();
	bubblesort(arr2, N);
	printf("%.4lf", (clock() - start) / CLOCKS_PER_SEC);
}