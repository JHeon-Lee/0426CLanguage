#include <stdio.h>

/*
	Call by value vs Call by reference
	값을 전달 vs 주소값을 전달
*/

void doublePointer();
void swapNum(int num1, int num2);
void swapPtr(int* ptr1, int* ptr2);
void swapPtr1(int** ptr1, int** ptr2);
void MaxAndMin(/*매개변수*/); // homework

int main()
{
	//doublePointer();

#pragma region Swap
	{
		int num1 = 10;
		int num2 = 20;

		int* ptr1 = &num1;
		int* ptr2 = &num2;

		int** pptr1 = &ptr1;
		int** pptr2 = &ptr2;

		swapNum(num1, num2); // Call by value
		printf("함수 밖 num1 : %d, num2 : %d\n\n", num1, num2); // 안바뀜

		swapPtr(ptr1, ptr2); // Call by reference
		printf("함수 밖 num1 : %d, num2 : %d\n", num1, num2);
		printf("함수 밖 ptr1 : %d, ptr2 : %d\n\n", *ptr1, *ptr2);

		swapPtr1(pptr1, pptr2);
		printf("함수 밖 num1 : %d, num2 : %d\n", num1, num2);
		printf("함수 밖 ptr1 : %d, ptr2 : %d\n\n", *ptr1, *ptr2);
		//printf("함수 밖 ptr1 : %d, ptr2 : %d\n", **ptr1, **ptr2);
	}
#pragma endregion

	/*{
		int* maxPtr = 0;
		int* minPtr = 0;
		int arr[5];
		for (int i = 0; i < 5; i++)
		{
			printf("정수 입력 %d : ", i + 1);
			scanf_s("%d", &arr[i]);
		}

		MaxAndMin();
		printf("최대 : %d, 최소 : %d\n", *maxPtr, *minPtr);
	}*/

#pragma region 배열포인터 vs 포인터배열
	{
		// 포인터 배열
		int a = 10, b = 20, c = 30;
		int* pArr[3] = { &a,&b,&c }; // 괄호 먼저 연산 후 포인터

		printf("%d\n", *pArr[0]);
		printf("%d\n", *pArr[1]);
		printf("%d\n", *pArr[2]);

		// 배열 포인터 - 괄호의 유무
		int arr1[3] = { 0,1,2 };
		int arr2[2][3] = {
			{0,1,2},
			{3,4,5}
		};
		int arr3[3][3] = {
			{0,1,2},
			{3,4,5},
			{6,7,8}
		};

		int(*ptrArr)[3] = arr1;

		for (int j = 0; j < 3; j++)
			printf("%d ", ptrArr[0][j]);
		printf("\n\n");

		ptrArr = arr2;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				printf("%d ", ptrArr[i][j]);
			}
			printf("\n");
		}
		printf("\n\n");

		ptrArr = arr3;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				printf("%d ", ptrArr[i][j]);
			}
			printf("\n");
		}
		printf("\n\n");
	}
#pragma endregion

	return 0;
}

void doublePointer()
{
	double num = 3.14;
	double* ptr = &num;
	double** dptr = &ptr;

	printf("&dptr = 0x%p\n", &dptr);
	printf("&ptr = 0x%p\n", &ptr);
	printf("&num = 0x%p\n\n", &num);

	printf("&ptr : 0x%p\n", &ptr);
	printf("&ptr : 0x%p\n\n", dptr);

	printf("&num : 0x%p\n", &num);
	printf("&num : 0x%p\n", ptr);
	printf("&num : 0x%p\n\n", *dptr);

	printf("num : %g\n", num);
	printf("num : %g\n", *ptr);
	printf("num : %g\n\n", **dptr);

	**dptr = 5.0;
	printf("num : %g\n", num);
}

void swapNum(int num1, int num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;

	printf("함수 안 num1 : %d, num2 : %d\n", num1, num2);
}

void swapPtr(int* ptr1, int* ptr2) // 엄밀히, C에선 Call by Value만 사용되지만, 포인터로 Call by Reference 효과를 낸다고 보면 된다
{
	int* temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;

	printf("함수 안 ptr1 : %d, ptr2 : %d\n", *ptr1, *ptr2);
}

void swapPtr1(int** ptr1, int** ptr2) // 윗 함수와 달리 바로 값을 참조해서 바꾸는게 아닌, 포인터가 참조하는 변수의 주소값을 바꿔준다
{
	int* temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;

	printf("함수 안 ptr1 : %d, ptr2 : %d\n", **ptr1, **ptr2);
}
