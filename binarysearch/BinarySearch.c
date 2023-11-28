#include <stdio.h>
#include "BinarySearch.h"
/*----------------------------------------------------------------
Function name	: binarySearch() - �̺а˻� �Լ�
Parameters		: ary - ������ �˻� ��� �迭
				  size - �˻���� �������� ���� 
				  key - �˻��� ������
Returns			: �˻� ���� �� ã�� ������ index
				    �˻� ���� �� -1 ����
----------------------------------------------------------------*/
int binarySearch(int ary[], int size, int key) {

	int a;
	int b;
	a = 0;
	b = size-1;

	int mid;

	while (size >= 0) {
		mid = (a + b) / 2;
		if (ary[mid] == key)
		{
			return mid;
		}
		if (ary[mid] < key) {
			a = mid+1;
			size /= 2;
		}
		else if (ary[mid] > key) {
			b = mid-1;
			size /= 2;
		}
	}
	
	return -1;
}

int binarySearchrecur(int ary[],int size, int key, int start, int end) {

	int mid;

	mid = (start + end) / 2;

	if (size == 0){
		return -1;
	}

	if (ary[mid] < key) {
		return binarySearchrecur(ary, size/2, key, mid+1, end);
	}
	else if (ary[mid] > key) {
		return binarySearchrecur(ary, size/2, key, start, mid-1);
	}
	else {
		return mid;
	}

}
