#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void DisplayMenu();
void bubbleSortMenu();
void radixCountSortMenu();
void countSortMenu();
void quickSortMenu_main();
void quickSortMenu();
void mergeSortMenu();
void insertSortMenu();
void bubbleSortMenu_main();
void bubbleSortMenu();
void BubbleSort(int* arr, int n);
void BubbleSort_sign(int* arr, int n);
void BubbleSort_last(int* arr, int n);
void BidirectionalBubbleSort(int* arr, int n);
void generateTestData();
void readFileData(int* arr1, int* arr2, int* arr3, int* arr4);
int JudgeInput();
int JudgeInput_unsigned();
int JudgeInput_012();
short JudgeChoice(int n);
int findMax(int* arr, int n);
void traverseArray(int* arr, int n);
int* creatArray(int* arr, int n);
void insertSort(int* arr1, int* arr2, int* arr3, int* arr4);
void mergeSort(int* arr1, int* arr2, int* arr3, int* arr4);
void countSort(int* arr1, int* arr2, int* arr3, int* arr4);
void radixCountSort(int* arr1, int* arr2, int* arr3, int* arr4);
void quickSort_main(int* arr1, int* arr2, int* arr3, int* arr4);
void quickSort(int* arr1, int* arr2, int* arr3, int* arr4);
void quickSort_Recursion_Partition(int* arr1, int* arr2, int* arr3, int* arr4, void (*sortMethod1)(int* a, int begin, int end));
void bubbleSort_main(int* arr1, int* arr2, int* arr3, int* arr4);
void bubbleSort(int* arr1, int* arr2, int* arr3, int* arr4, void (*sortMethod2)(int* arr, int n));
void colorSort();
int* creatArray_signed(int* arr, int n);

int main() {
	generateTestData();

	while (1) {
		DisplayMenu();
		short choice = JudgeChoice(9);
		if (choice == 9)
		{
			printf("��ӭ���ٴ�ʹ��, �ټ�!\n");
			break;
		}
		int* arr1 = (int*)malloc(10000 * sizeof(int));
		int* arr2 = (int*)malloc(50000 * sizeof(int));
		int* arr3 = (int*)malloc(200000 * sizeof(int));
		int* arr4 = (int*)malloc(100 * sizeof(int));
		readFileData(arr1, arr2, arr3, arr4);
		switch (choice) {
		case 1:
			insertSort(arr1, arr2, arr3, arr4);
			break;
		case 2:
			mergeSort(arr1, arr2, arr3, arr4);
			break;
		case 3:
			quickSort_main(arr1, arr2, arr3, arr4);
			break;
		case 4:
			countSort(arr1, arr2, arr3, arr4);
			break;
		case 5:
			radixCountSort(arr1, arr2, arr3, arr4);
			break;
		case 6:
			colorSort();
			break;
		case 7:
			bubbleSort_main(arr1, arr2, arr3, arr4);
			break;
		case 8:
		{
			printf("����������Ҫ���Ե����ݵ�����");
			int n = JudgeInput();
			printf("������K��ֵ��");
			int k;
			while ((scanf("%d", &k) != 1) || k < 1 || k > n) {
				while (getchar() != '\n');//������뻺����
				printf("�������KֵС��1��������ݵ���������������Ĳ�����������������������Ч��Kֵ~~\n");
			}
			int* arr = (int*)malloc(n * sizeof(int));
			arr = creatArray(arr, n);
			printf("��ʼѰ��~~\n");
			int kthNumber = FindKthNumber(arr, 0, n-1, k);
			printf("��%dС����Ϊ��%d\n", k, kthNumber);
			free(arr);
			break;
		}
		case 9:
			return;
		}
		free(arr1);
		free(arr2);
		free(arr3);
		free(arr4);
	}
}

void bubbleSort_main(int* arr11, int* arr22, int* arr33, int* arr44) {
	while (1) {
		int* arr1 = (int*)malloc(10000 * sizeof(int));
		int* arr2 = (int*)malloc(50000 * sizeof(int));
		int* arr3 = (int*)malloc(200000 * sizeof(int));
		int* arr4 = (int*)malloc(100 * sizeof(int));
		memcpy(arr1, arr11, 10000 * sizeof(int));
		memcpy(arr2, arr22, 50000 * sizeof(int));
		memcpy(arr3, arr33, 200000 * sizeof(int));
		memcpy(arr4, arr44, 100 * sizeof(int));
		bubbleSortMenu_main();
		short choice = JudgeChoice(5);
		switch (choice) {
		case 1:
			bubbleSort(arr1, arr2, arr3, arr4, BubbleSort);
			break;
		case 2:
			bubbleSort(arr1, arr2, arr3, arr4, BubbleSort_sign);
			break;
		case 3:
			bubbleSort(arr1, arr2, arr3, arr4, BubbleSort_last);
			break;
		case 4:
			bubbleSort(arr1, arr2, arr3, arr4, BidirectionalBubbleSort);
			break;
		case 5:
			return;
		}
		free(arr1);
		free(arr2);
		free(arr3);
		free(arr4);
	}
}

void bubbleSort(int* arr111, int* arr222, int* arr333, int* arr444, void (*sortMethod2)(int* arr, int n)) {
	while (1) {
		int* arr1 = (int*)malloc(10000 * sizeof(int));
		int* arr2 = (int*)malloc(50000 * sizeof(int));
		int* arr3 = (int*)malloc(200000 * sizeof(int));
		memcpy(arr1, arr111, 10000 * sizeof(int));
		memcpy(arr2, arr222, 50000 * sizeof(int));
		memcpy(arr3, arr333, 200000 * sizeof(int));
		bubbleSortMenu();
		short choice = JudgeChoice(4);
		switch (choice) {
		case 1:
		{
			int sizes[] = { 10000,50000,200000 };
			int* arrs[] = { arr1,arr2,arr3 };
			clock_t start, end;
			double cpu_time_used;

			for (int i = 0; i < 3; i++) {
				start = clock();
				sortMethod2(arrs[i], sizes[i]);
				end = clock();
				cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

				printf("Bubble sort with %d elements took %.15f seconds\n", sizes[i], cpu_time_used);
			}
			break;
		}
		case 2:
		{
			int k;
			clock_t start, end;
			double cpu_time_used;
			int iterations = 100000;

			// ���ж������ȡƽ��ֵ
			start = clock();
			for (k = 0; k < iterations; k++) {
				int* arr4 = (int*)malloc(100 * sizeof(int));
				memcpy(arr4, arr444, 100 * sizeof(int));
				sortMethod2(arr4, 100);
				free(arr4);
			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

			printf("Bubble sort with 100 elements 100000 times took %.15f seconds \n", cpu_time_used);

			break;
		}
		case 3:
		{
			printf("����������Ҫ���Ե����ݵ�����");
			int n = JudgeInput();
			int* arr = (int*)malloc(n * sizeof(int));
			arr = creatArray(arr, n);
			printf("��ʼ����~~\n");
			sortMethod2(arr, n);
			printf("�����Ľ��Ϊ��");
			traverseArray(arr, n);
			free(arr);
			break;
		}
		case 4:
			return;
		}
		free(arr1);
		free(arr2);
		free(arr3);
	}
}

void quickSort_main(int* arr11, int* arr22, int* arr33, int* arr44) {
	while (1) {
		int* arr1 = (int*)malloc(10000 * sizeof(int));
		int* arr2 = (int*)malloc(50000 * sizeof(int));
		int* arr3 = (int*)malloc(200000 * sizeof(int));
		int* arr4 = (int*)malloc(100 * sizeof(int));
		memcpy(arr1, arr11, 10000 * sizeof(int));
		memcpy(arr2, arr22, 50000 * sizeof(int));
		memcpy(arr3, arr33, 200000 * sizeof(int));
		memcpy(arr4, arr44, 100 * sizeof(int));
		quickSortMenu_main();
		short choice = JudgeChoice(4);
		switch (choice) {
		case 1:
			quickSort_Recursion_Partition(arr1, arr2, arr3, arr4, QuickSort_Recursion);
			break;
		case 2:
			quickSort(arr1, arr2, arr3, arr4);
			break;
		case 3:
			quickSort_Recursion_Partition(arr1, arr2, arr3, arr4, QuickSort_Partition);
			break;
		case 4:
			return;
		}
		free(arr1);
		free(arr2);
		free(arr3);
		free(arr4);
	}
}

void quickSort_Recursion_Partition(int* arr111, int* arr222, int* arr333, int* arr444, void (*sortMethod1)(int* a, int begin, int end)) {
	while (1) {
		int* arr1 = (int*)malloc(10000 * sizeof(int));
		int* arr2 = (int*)malloc(50000 * sizeof(int));
		int* arr3 = (int*)malloc(200000 * sizeof(int));
		memcpy(arr1, arr111, 10000 * sizeof(int));
		memcpy(arr2, arr222, 50000 * sizeof(int));
		memcpy(arr3, arr333, 200000 * sizeof(int));
		quickSortMenu();
		short choice = JudgeChoice(4);
		switch (choice) {
		case 1:
		{
			int sizes[] = { 10000,50000,200000 };
			int* arrs[] = { arr1,arr2,arr3 };
			clock_t start, end;
			double cpu_time_used;

			for (int i = 0; i < 3; i++) {
				start = clock();
				sortMethod1(arrs[i], 0, sizes[i]-1);
				end = clock();
				cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

				printf("Quick sort with %d elements took %.15f seconds\n", sizes[i], cpu_time_used);
			}
			break;
		}
		case 2:
		{
			int k;
			clock_t start, end;
			double cpu_time_used;
			int iterations = 100000;

			// ���ж������ȡƽ��ֵ
			start = clock();
			for (k = 0; k < iterations; k++) {
				int* arr4 = (int*)malloc(100 * sizeof(int));
				memcpy(arr4, arr444, 100 * sizeof(int));
				sortMethod1(arr4, 0, 99);
				free(arr4);
			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

			printf("Quick sort with 100 elements 100000 times took %.15f seconds \n", cpu_time_used);

			break;
		}
		case 3:
		{
			printf("����������Ҫ���Ե����ݵ�����");
			int n = JudgeInput();
			int* arr = (int*)malloc(n * sizeof(int));
			arr = creatArray(arr, n);
			printf("��ʼ����~~\n");
			sortMethod1(arr, 0, n - 1);
			printf("�����Ľ��Ϊ��");
			traverseArray(arr, n);
			free(arr);
			break;
		}
		case 4:
			return;
		}
		free(arr1);
		free(arr2);
		free(arr3);
	}
}

void quickSort(int* arr111, int* arr222, int* arr333, int* arr444) {
	while (1) {
		int* arr1 = (int*)malloc(10000 * sizeof(int));
		int* arr2 = (int*)malloc(50000 * sizeof(int));
		int* arr3 = (int*)malloc(200000 * sizeof(int));
		memcpy(arr1, arr111, 10000 * sizeof(int));
		memcpy(arr2, arr222, 50000 * sizeof(int));
		memcpy(arr3, arr333, 200000 * sizeof(int));
		quickSortMenu();
		short choice = JudgeChoice(4);
		switch (choice) {
		case 1:
		{
			int sizes[] = { 10000,50000,200000 };
			int* arrs[] = { arr1,arr2,arr3 };
			clock_t start, end;
			double cpu_time_used;

			for (int i = 0; i < 3; i++) {
				start = clock();
				QuickSort(arrs[i], sizes[i]);
				end = clock();
				cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

				printf("Quick sort with %d elements took %.15f seconds\n", sizes[i], cpu_time_used);
			}
			break;
		}
		case 2:
		{
			int k;
			clock_t start, end;
			double cpu_time_used;
			int iterations = 100000;

			// ���ж������ȡƽ��ֵ
			start = clock();
			for (k = 0; k < iterations; k++) {
				int* arr4 = (int*)malloc(100 * sizeof(int));
				memcpy(arr4, arr444, 100 * sizeof(int));
				QuickSort(arr4, 100);
				free(arr4);
			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

			printf("Quick sort with 100 elements 100000 times took %.15f seconds \n", cpu_time_used);

			break;
		}
		case 3:
		{
			printf("����������Ҫ���Ե����ݵ�����");
			int n = JudgeInput();
			int* arr = (int*)malloc(n * sizeof(int));
			arr = creatArray_signed(arr, n);
			printf("��ʼ����~~\n");
			QuickSort(arr, n);
			printf("�����Ľ��Ϊ��");
			traverseArray(arr, n);
			free(arr);
			break;
		}
		case 4:
			return;
		}
		free(arr1);
		free(arr2);
		free(arr3);
	}
}

void colorSort() {
	printf("����������Ҫ���Ե����ݵ�����");
	int n = JudgeInput();
	int* arr = (int*)malloc(n * sizeof(int));
	for (int j = 0; j < n; j++) {
		printf("\ninput -> data: ");
		arr[j] = JudgeInput_012();
	}
	printf("��ʼ����~~\n");
	ColorSort(arr, n);
	printf("�����Ľ��Ϊ��");
	traverseArray(arr, n);
	free(arr);

}

void radixCountSort(int* arr11, int* arr22, int* arr33, int* arr44) {
	while (1) {
		int* arr1 = (int*)malloc(10000 * sizeof(int));
		int* arr2 = (int*)malloc(50000 * sizeof(int));
		int* arr3 = (int*)malloc(200000 * sizeof(int));
		memcpy(arr1, arr11, 10000 * sizeof(int));
		memcpy(arr2, arr22, 50000 * sizeof(int));
		memcpy(arr3, arr33, 200000 * sizeof(int));
		radixCountSortMenu();
		short choice = JudgeChoice(4);
		switch (choice) {
		case 1:
		{
			int sizes[] = { 10000,50000,200000 };
			int* arrs[] = { arr1,arr2,arr3 };
			clock_t start, end;
			double cpu_time_used;

			for (int i = 0; i < 3; i++) {
				start = clock();
				RadixCountSort(arrs[i], sizes[i]);
				end = clock();
				cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

				printf("RadixCount sort with %d elements took %.15f seconds\n", sizes[i], cpu_time_used);
			}
			break;
		}
		case 2:
		{
			int k;
			clock_t start, end;
			double cpu_time_used;
			int iterations = 100000;

			// ���ж������ȡ
			start = clock();
			for (k = 0; k < iterations; k++) {
				int* arr4 = (int*)malloc(100 * sizeof(int));
				memcpy(arr4, arr44, 100 * sizeof(int));
				RadixCountSort(arr4, 100);
				free(arr4);
			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

			printf("RadixCount sort with 100 elements 100000 times took %.15f seconds \n", cpu_time_used);

			break;
		}
		case 3:
		{
			printf("����������Ҫ���Ե����ݵ�����");
			int n = JudgeInput();
			int* arr = (int*)malloc(n * sizeof(int));
			arr = creatArray_signed(arr, n);
			printf("��ʼ����~~\n");
			RadixCountSort(arr, n);
			printf("�����Ľ��Ϊ��");
			traverseArray(arr, n);
			free(arr);
			break;
		}
		case 4:
			return;
		}
		free(arr1);
		free(arr2);
		free(arr3);
	}
}

void countSort(int* arr11, int* arr22, int* arr33, int* arr44) {
	while (1) {
		int* arr1 = (int*)malloc(10000 * sizeof(int));
		int* arr2 = (int*)malloc(50000 * sizeof(int));
		int* arr3 = (int*)malloc(200000 * sizeof(int));
		int* arr4 = (int*)malloc(100 * sizeof(int));
		memcpy(arr1, arr11, 10000 * sizeof(int));
		memcpy(arr2, arr22, 50000 * sizeof(int));
		memcpy(arr3, arr33, 200000 * sizeof(int));
		memcpy(arr4, arr44, 100 * sizeof(int));
		countSortMenu();
		short choice = JudgeChoice(4);
		switch (choice) {
		case 1:
		{
			int sizes[] = { 10000,50000,200000 };
			int* arrs[] = { arr1,arr2,arr3 };
			clock_t start, end;
			double cpu_time_used;

			for (int i = 0; i < 3; i++) {
				int max = findMax(arrs[i], sizes[i]);
				start = clock();
				CountSort(arrs[i], sizes[i], max);
				end = clock();
				cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
				printf("Count sort with %d elements took %.15f seconds\n", sizes[i], cpu_time_used);
			}
			break;
		}
		case 2:
		{
			int k;
			clock_t start, end;
			double cpu_time_used;
			int iterations = 100000;

			// ���ж������
			start = clock();
			for (k = 0; k < iterations; k++) {
				int* arr4 = (int*)malloc(100 * sizeof(int));
				memcpy(arr4, arr44, 100 * sizeof(int));
				int max = findMax(arr4, 100);
				CountSort(arr4, 100, max);
				free(arr4);
			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

			printf("Count sort with 100 elements 100000 times took %.15f seconds \n", cpu_time_used);
			break;
		}
		case 3:
		{
			printf("����������Ҫ���Ե����ݵ�����");
			int n = JudgeInput();
			int* arr = (int*)malloc(n * sizeof(int));
			arr = creatArray_signed(arr, n);
			int max = findMax(arr, n);
			printf("��ʼ����~~\n");
			CountSort(arr, n, max);
			printf("�����Ľ��Ϊ��");
			traverseArray(arr, n);
			free(arr);
			break;
		}
		case 4:
			return;
		}
		free(arr1);
		free(arr2);
		free(arr3);
	}
}

void mergeSort(int* arr11, int* arr22, int* arr33, int* arr44) {
	while (1) {
		int* arr1 = (int*)malloc(10000 * sizeof(int));
		int* arr2 = (int*)malloc(50000 * sizeof(int));
		int* arr3 = (int*)malloc(200000 * sizeof(int));
		memcpy(arr1, arr11, 10000 * sizeof(int));
		memcpy(arr2, arr22, 50000 * sizeof(int));
		memcpy(arr3, arr33, 200000 * sizeof(int));
		mergeSortMenu();
		short choice = JudgeChoice(4);
		switch (choice) {
		case 1:
		{
			int sizes[] = { 10000,50000,200000 };
			int* arrs[] = { arr1,arr2,arr3 };
			clock_t start, end;
			double cpu_time_used;

			for (int i = 0; i < 3; i++) {
				start = clock();
				int* temp = (int*)malloc(sizes[i] * sizeof(int));
				MergeSort(arrs[i], 0, sizes[i] - 1, temp);
				free(temp);
				end = clock();
				cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
				printf("Merge sort with %d elements took %.15f seconds\n", sizes[i], cpu_time_used);
			}
			break;
		}
		case 2:
		{
			clock_t start, end;
			double cpu_time_used;
			int iterations = 100000;

			// ���ж������
			start = clock();
			for (int k = 0; k < iterations; k++) {
				int* arr4 = (int*)malloc(100 * sizeof(int));
				memcpy(arr4, arr44, 100 * sizeof(int));
				int* temp = (int*)malloc(100 * sizeof(int));
				MergeSort(arr4, 0, 99, temp);
				free(temp);
				free(arr4);
			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC / iterations;

			printf("Merge sort with 100 elements 100000 times took %.15f seconds \n", cpu_time_used);
			break;
		}
		case 3:
		{
			printf("����������Ҫ���Ե����ݵ�����");
			int n = JudgeInput();
			int* arr = (int*)malloc(n * sizeof(int));
			arr = creatArray(arr, n);
			printf("��ʼ����~~\n");
			int* temp = (int*)malloc(n * sizeof(int));
			MergeSort(arr, 0, n - 1, temp);
			free(temp);
			printf("�����Ľ��Ϊ��");
			traverseArray(arr, n);
			free(arr);
			break;
		}
		case 4:
			return;
		}
		free(arr1);
		free(arr2);
		free(arr3);
	}
}

void insertSort(int* arr11, int* arr22, int* arr33, int* arr44) {
	while (1) {
		int* arr1 = (int*)malloc(10000 * sizeof(int));
		int* arr2 = (int*)malloc(50000 * sizeof(int));
		int* arr3 = (int*)malloc(200000 * sizeof(int));
		memcpy(arr1, arr11, 10000 * sizeof(int));
		memcpy(arr2, arr22, 50000 * sizeof(int));
		memcpy(arr3, arr33, 200000 * sizeof(int));
		insertSortMenu();
		short choice = JudgeChoice(4);
		switch (choice) {
		case 1:
		{
			int sizes[] = { 10000,50000,200000 };
			int* arrs[] = { arr1,arr2,arr3 };
			clock_t start, end;
			double cpu_time_used;

			for (int i = 0; i < 3; i++) {
				start = clock();
				InsertSort(arrs[i], sizes[i]);
				end = clock();
				cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

				printf("Insert sort with %d elements took %.15f seconds\n", sizes[i], cpu_time_used);
			}
			break;
		}
		case 2:
		{
			int k;
			clock_t start, end;
			double cpu_time_used;
			int iterations = 100000;

			// ���ж������
			start = clock();
			for (k = 0; k < iterations; k++) {
				int* arr4 = (int*)malloc(100 * sizeof(int));
				memcpy(arr4, arr44, 100 * sizeof(int));
				InsertSort(arr4, 100);
				free(arr4);
			}
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC / iterations;

			printf("Insert sort with 100 elements 100000 times took %.15f seconds \n", cpu_time_used);
			break;
		}
		case 3:
		{
			printf("����������Ҫ���Ե����ݵ�����");
			int n = JudgeInput();
			int* arr = (int*)malloc(n * sizeof(int));
			arr = creatArray(arr, n);
			printf("��ʼ����~~\n");
			InsertSort(arr, n);
			printf("�����Ľ��Ϊ��");
			traverseArray(arr, n);
			free(arr);
			break;
		}
		case 4:
			return;
		}
		free(arr1);
		free(arr2);
		free(arr3);
	}
}

void generateTestData() {
	int i, j;
	FILE* fp1;
	FILE* fp2;
	FILE* fp3;
	FILE* fp4;

	srand(time(NULL));

	int* arr1 = (int*)malloc(10000 * sizeof(int));
	for (j = 0; j < 10000; j++) {
		arr1[j] = rand() % 200000;
	}
	fp1 = fopen("data10000.dat", "w");
	for (i = 0; i < 10000; i++) {
		fprintf(fp1, "%d ", arr1[i]);
	}
	fclose(fp1);
	free(arr1);

	int* arr2 = (int*)malloc(50000 * sizeof(int));
	for (j = 0; j < 50000; j++) {
		arr2[j] = rand() % 200000;
	}
	fp2 = fopen("data50000.dat", "w");
	for (i = 0; i < 50000; i++) {
		fprintf(fp2, "%d ", arr2[i]);
	}
	fclose(fp2);
	free(arr2);

	int* arr3 = (int*)malloc(200000 * sizeof(int));
	for (j = 0; j < 200000; j++) {
		arr3[j] = rand() % 200000;
	}
	fp3 = fopen("data200000.dat", "w");
	for (i = 0; i < 200000; i++) {
		fprintf(fp3, "%d ", arr3[i]);
	}
	fclose(fp3);
	free(arr3);

	int* arr4 = (int*)malloc(100 * sizeof(int));
	for (j = 0; j < 100; j++) {
		arr4[j] = rand() % 200000;
	}
	fp4 = fopen("data100.dat", "w");
	for (i = 0; i < 100; i++) {
		fprintf(fp4, "%d ", arr4[i]);
	}
	fclose(fp4);
	free(arr4);

}

void readFileData(int* arr1, int* arr2, int* arr3, int* arr4) {
	int i;
	FILE* fp1;
	FILE* fp2;
	FILE* fp3;
	FILE* fp4;
	int sizes[] = { 10000,50000,200000,100 };

	fp1 = fopen("data10000.dat", "r");
	for (i = 0; i < sizes[0]; i++) {
		fscanf(fp1, "%d", &arr1[i]);
	}
	fclose(fp1);

	fp2 = fopen("data50000.dat", "r");
	for (i = 0; i < sizes[1]; i++) {
		fscanf(fp2, "%d", &arr2[i]);
	}
	fclose(fp2);

	fp3 = fopen("data200000.dat", "r");
	for (i = 0; i < sizes[2]; i++) {
		fscanf(fp3, "%d", &arr3[i]);
	}
	fclose(fp3);

	fp4 = fopen("data100.dat", "r");
	for (i = 0; i < sizes[3]; i++) {
		fscanf(fp4, "%d", &arr4[i]);
	}
	fclose(fp4);
}

void bubbleSortMenu_main() {
	printf("\n");
	printf("*******************************************************************\n");
	printf("   1.ð��������ͨ��\n");
	printf("*******************************************************************\n");
	printf("   2.ð�������Ż���1����ӱ�־λ��\n");
	printf("*******************************************************************\n");
	printf("   3.ð�������Ż���2����¼���һ�ν�����λ�ã�\n");
	printf("*******************************************************************\n");
	printf("   4.˫��ð������\n");
	printf("*******************************************************************\n");
	printf("   5.exit\n");
	printf(" -------------------------------------------------------------\n");
	printf("��ѡ������Ҫ�Ĳ���(1~5)��\n");
}

void bubbleSortMenu() {
	printf("\n");
	printf("*******************************************************************\n");
	printf("   1.���ð���������ڲ�ͬ�Ĵ��������µ���ʱ\n");
	printf("*******************************************************************\n");
	printf("   2.���ð���������ڴ���С�������µ�������ʱ\n");
	printf("*******************************************************************\n");
	printf("   3.�������ݽ����������\n");
	printf("*******************************************************************\n");
	printf("   4.exit\n");
	printf(" ------------------------------------------------------------------\n");
	printf("��ѡ������Ҫ�Ĳ���(1~4)��\n");
}

void radixCountSortMenu() {
	printf("\n");
	printf("*******************************************************************\n");
	printf("   1.��������������ڲ�ͬ�Ĵ��������µ���ʱ\n");
	printf("*******************************************************************\n");
	printf("   2.��������������ڴ���С�������µ�������ʱ\n");
	printf("*******************************************************************\n");
	printf("   3.�������ݽ����������\n");
	printf("*******************************************************************\n");
	printf("   4.exit\n");
	printf(" ------------------------------------------------------------------\n");
	printf("��ѡ������Ҫ�Ĳ���(1~4)��\n");
}

void countSortMenu() {
	printf("\n");
	printf("*******************************************************************\n");
	printf("   1.��������������ڲ�ͬ�Ĵ��������µ���ʱ\n");
	printf("*******************************************************************\n");
	printf("   2.��������������ڴ���С�������µ�������ʱ\n");
	printf("*******************************************************************\n");
	printf("   3.�������ݽ����������\n");
	printf("*******************************************************************\n");
	printf("   4.exit\n");
	printf(" ------------------------------------------------------------------\n");
	printf("��ѡ������Ҫ�Ĳ���(1~4)��\n");
}

void quickSortMenu_main() {
	printf("\n");
	printf("*******************************************************************\n");
	printf("   1.����������ͨ�ݹ��\n");
	printf("*******************************************************************\n");
	printf("   2.��������ǵݹ��\n");
	printf("*******************************************************************\n");
	printf("   3.���������������Ż���\n");
	printf("*******************************************************************\n");
	printf("   4.exit\n");
	printf(" ------------------------------------------------------------------\n");
	printf("��ѡ������Ҫ�Ĳ���(1~4)��\n");
}

void quickSortMenu() {
	printf("\n");
	printf("*******************************************************************\n");
	printf("   1.��������������ڲ�ͬ�Ĵ��������µ���ʱ\n");
	printf("*******************************************************************\n");
	printf("   2.��������������ڴ���С�������µ�������ʱ\n");
	printf("*******************************************************************\n");
	printf("   3.�������ݽ����������\n");
	printf("*******************************************************************\n");
	printf("   4.exit\n");
	printf(" ------------------------------------------------------------------\n");
	printf("��ѡ������Ҫ�Ĳ���(1~4)��\n");
}

void mergeSortMenu() {
	printf("\n");
	printf("*******************************************************************\n");
	printf("   1.����ϲ��������ڲ�ͬ�Ĵ��������µ���ʱ\n");
	printf("*******************************************************************\n");
	printf("   2.����ϲ��������ڴ���С�������µ�������ʱ\n");
	printf("*******************************************************************\n");
	printf("   3.�������ݽ����������\n");
	printf("*******************************************************************\n");
	printf("   4.exit\n");
	printf(" ------------------------------------------------------------------\n");
	printf("��ѡ������Ҫ�Ĳ���(1~4)��\n");
}

void insertSortMenu() {
	printf("\n");
	printf("*******************************************************************\n");
	printf("   1.��������������ڲ�ͬ�Ĵ��������µ���ʱ\n");
	printf("*******************************************************************\n");
	printf("   2.��������������ڴ���С�������µ�������ʱ\n");
	printf("*******************************************************************\n");
	printf("   3.�������ݽ����������\n");
	printf("*******************************************************************\n");
	printf("   4.exit\n");
	printf(" ------------------------------------------------------------------\n");
	printf("��ѡ������Ҫ�Ĳ���(1~4)��\n");
}

void DisplayMenu() {
	printf("\n");
	printf("***********************************************************************************\n");
	printf("   1.��������                             2.�鲢����\n");
	printf("***********************************************************************************\n");
	printf("   3.��������                             4.��������\n");
	printf("***********************************************************************************\n");
	printf("   5.������������                         6.ʹ����ɫ�����ֻ��Ԫ��0��1��2����������\n");
	printf("***********************************************************************************\n");
	printf("   7.ð������                             8.��һ�������������ҵ���KС����\n");
	printf("***********************************************************************************\n");
	printf("   9.exit\n");
	printf(" ----------------------------------------------------------------------------------\n");
	printf("��ѡ������Ҫ�Ĳ���(1~9)��\n");
}

/*
  ��ͨ��
*/
void BubbleSort(int* arr, int n) {
	int i, j, tmp;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

/*
  ��ӱ�־λ����һ��������û�з�������ʱ��
  ˵���Ѿ��ź��򣬿�����ǰ��������
*/
void BubbleSort_sign(int* arr, int n) {
	int i, j, tmp;
	int flag;
	for (i = 0; i < n - 1; i++) {
		flag = 1;
		for (j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;
			}
		}
		if (flag) {
			break;
		}
	}
}

/*
   ��¼���һ�ν�����λ�ã�����һ������ʱ��
   ֻ��Ҫ�Ƚϵ���λ�ü��ɣ���Ϊ��λ��֮��
   ��Ԫ���Ѿ�����
*/
void BubbleSort_last(int* arr, int n) {
	int j, tmp;
	int last = n - 1;// ���һ�ν�����λ��
	while (last > 0) {
		int k = last;
		last = 0;// ÿ�ο�ʼ����ǰ�������һ�ν�����λ����Ϊ0
		for (j = 0; j < k; j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				last = j;// ��¼���һ�ν�����λ��
			}
		}
	}
}

/*
  ˫��ð������������ͬʱ����������
  ������������򣬴Ӷ���������Ĵ���
*/
void BidirectionalBubbleSort(int* arr, int n) {
	int left = 0, right = n - 1;
	while (left < right) {
		for (int i = left; i < right; i++) {
			if (arr[i] > arr[i + 1]) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
		right--;
		for (int i = right; i > left; i--) {
			if (arr[i] < arr[i - 1]) {
				int temp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = temp;
			}
		}
		left++;
	}
}

int JudgeInput() {
	int ele;
	while (scanf("%d", &ele) != 1 || ele < 0)
	{
		while (getchar() != '\n');
		printf("\n������������.\n");
	}
	return ele;
}

int JudgeInput_unsigned() {
	int ele;
	while (scanf("%d", &ele) != 1)
	{
		while (getchar() != '\n');
		printf("\n����������.\n");
	}
	return ele;
}

int JudgeInput_012() {
	int ele;
	while (1)
	{
		if (scanf("%d", &ele) == 1 && ((ele == 1) || (ele == 2) || (ele == 0)))
			return ele;
		else {
			while (getchar() != '\n');
			printf("\n������0,1,2.\n");
		}
	}
	
}

short JudgeChoice(int n) {
	short choice;
	while ((scanf("%hd", &choice) != 1) || choice < 1 || choice > n) {
		while (getchar() != '\n');//������뻺����
		printf("������Ϸ�������~~\n");
		printf("�����������(1~%d): ", n);
	}
	return choice;
}

void traverseArray(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d\t", arr[i]);
	}
}

int findMax(int* arr, int n) {
	int max = arr[0];
	for (int j = 1; j < n; j++) {
		if (arr[j] > max) {
			max = arr[j];
		}
	}
	return max;
}

int* creatArray(int* arr, int n) {
	for (int j = 0; j < n; j++) {
		printf("\ninput -> data: ");
		arr[j] = JudgeInput_unsigned();
	}
	return arr;
}

int* creatArray_signed(int* arr, int n) {
	for (int j = 0; j < n; j++) {
		printf("\ninput -> data: ");
		arr[j] = JudgeInput();
	}
	return arr;
}