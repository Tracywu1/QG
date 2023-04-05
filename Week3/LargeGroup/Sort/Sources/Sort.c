#include "Sort.h"
#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 *  @name        : void InsertSort(int *a,int n);
 *  @description : ���������㷨
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void InsertSort(int* a, int n) {
	int i, j, temp;

	for (i = 1; i < n; i++) {
		temp = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > temp) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int* a, int begin, int mid, int end, int* temp) {
	int i = begin, j = mid + 1, k = 0;
	while (i <= mid && j <= end) {
		if (a[i] <= a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
		}
	}
	while (i <= mid) {
		temp[k++] = a[i++];
	}
	while (j <= end) {
		temp[k++] = a[j++];
	}
	for (int m = 0; m < k; m++) {
		a[begin + m] = temp[m];
	}
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int* a, int begin, int end, int* temp) {
	if (begin >= end) {
		return;
	}
	int mid = begin + (end - begin) / 2;
	MergeSort(a, begin, mid, temp);
	MergeSort(a, mid + 1, end, temp);
	MergeArray(a, begin, mid, end, temp);
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int* a, int begin, int end) {
	int i, j, pivot, temp;
	if (begin < end) {
		pivot = begin;
		i = begin;
		j = end;
		while (i < j) {
			while (a[i] <= a[pivot] && i < end)
				i++;
			while (a[j] > a[pivot])
				j--;
			if (i < j) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		temp = a[pivot];
		a[pivot] = a[j];
		a[j] = temp;
		QuickSort_Recursion(a, begin, j - 1);
		QuickSort_Recursion(a, j + 1, end);
	}
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int* a, int size) {
	int left = 0;
	int right = size - 1;
	int* stack= (int*)malloc(size * sizeof(int));
	int top = -1;
	stack[++top] = left;
	stack[++top] = right;

	while (top >= 0) {
		right = stack[top--];
		left = stack[top--];
		int mid = (left + right) / 2;
		if (a[left] > a[mid])
			swap(&a[left], &a[mid]);
		if (a[left] > a[right])
			swap(&a[left], &a[right]);
		if (a[mid] > a[right])
			swap(&a[mid], &a[right]);
		int pivot = a[mid];
		swap(&a[mid], &a[right - 1]);

		int i = left;
		int j = right - 1;
		while (1) {
			while (a[++i] < pivot);
			while (a[--j] > pivot);
			if (i < j)
				swap(&a[i], &a[j]);
			else
				break;
		}
		swap(&a[i], &a[right - 1]);

		if (i - left >= 2) {
			stack[++top] = left;
			stack[++top] = i - 1;
		}
		if (right - i >= 2) {
			stack[++top] = i + 1;
			stack[++top] = right;
		}
	}
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int medianOfThree(int* a, int begin, int end) {
	int mid = begin + (end - begin) / 2;
	if (a[begin] > a[end])
		swap(&a[begin], &a[end]);
	if (a[mid] > a[end])
		swap(&a[mid], &a[end]);
	if (a[begin] > a[mid])
		swap(&a[begin], &a[mid]);
	return a[mid];
}

int Partition(int* a, int begin, int end) {
	int pivot = medianOfThree(a, begin, end);
	int i = begin - 1;
	int j = end + 1;
	while (1) {
		do {
			i++;
		} while (a[i] < pivot);
		do {
			j--;
		} while (a[j] > pivot);
		if (i >= j)
			return j;
		swap(&a[i], &a[j]);
	}
}

void QuickSort_Partition(int* a, int begin, int end) {
	if (end - begin + 1 <= 10) {
		InsertSort(a, end - begin + 1);
		return;
	}
	int pivot = Partition(a, begin, end);
	QuickSort_Partition(a, begin, pivot);
	QuickSort_Partition(a, pivot + 1, end);
}



/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int* a, int size, int max) {
	int* count = calloc(max + 1, sizeof(int)); // �����������

   // ͳ��Ԫ�ظ���
	for (int i = 0; i < size; i++) {
		count[a[i]]++;
	}

	// �����ۼ�
	for (int i = 1; i <= max; i++) {
		count[i] += count[i - 1];
	}

	// ��Ԫ�ط�������������
	int* sorted_arr = malloc(size * sizeof(int));
	for (int i = size - 1; i >= 0; i--) {
		sorted_arr[--count[a[i]]] = a[i];
	}

	// ���������鸴�ƻ�ԭ����
	for (int i = 0; i < size; i++) {
		a[i] = sorted_arr[i];
	}

	// �ͷ��ڴ�
	free(sorted_arr);
	free(count);
}

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int* a, int size) {
	int* output = (int*)malloc(size * sizeof(int));
	int max = a[0];
	for (int i = 1; i < size; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}

	for (int exp = 1; max / exp > 0; exp *= 10) {
		int count[10] = { 0 };
		for (int i = 0; i < size; i++) {
			int digit = (a[i] / exp) % 10;
			count[digit]++;
		}

		for (int i = 1; i < 10; i++) {
			count[i] += count[i - 1];
		}

		for (int i = size - 1; i >= 0; i--) {
			int digit = (a[i] / exp) % 10;
			output[count[digit] - 1] = a[i];
			count[digit]--;
		}

		for (int i = 0; i < size; i++) {
			a[i] = output[i];
		}
	}

	free(output);
}


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int* a, int size)
{
	int left = 0, mid = 0, right = size - 1;
	while (mid <= right) {
		switch (a[mid]) {
		case 0: // ��ɫ����
			swap(&a[left], &a[mid]);
			left++;
			mid++;
			break;
		case 1: // ��ɫ����
			mid++;
			break;
		case 2: // ��ɫ����
			swap(&a[mid], &a[right]);
			right--;
			break;
		default:
			break;
		}
	}
}


/**
 *  @name        : int quick_select(int arr[], int left, int right, int k)
 *  @description : ��һ�������������ҵ���KС����
 *  @param       : ����ָ��a���������begin�������յ�end, kֵ
 */
int FindKthNumber(int* a, int begin, int end, int k) {
	if (begin == end) {
		return a[begin];  // ֻ��һ��Ԫ�أ�ֱ�ӷ���
	}

	int pivot_index = Partition(a, begin, end);
	int pivot_rank = pivot_index - begin + 1;  // ��Ԫ���������е��������� 1 ��ʼ��

	if (k == pivot_rank) {
		return a[pivot_index];
	}
	else if (k < pivot_rank) {
		return FindKthNumber(a, begin, pivot_index - 1, k);
	}
	else {
		return FindKthNumber(a, pivot_index + 1, end, k - pivot_rank);
	}
}