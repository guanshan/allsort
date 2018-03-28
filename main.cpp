#include "allSort.h"

using namespace std;

int main()
{
	//在int上测试
	int a[]={3,2,6,7,1,9};
	allSort<int> iTest;
	iTest.insertSort(a,6);
	cout << "int 数组，插入排序结果：" << flush;
	iTest.printArray(a,6);
	cout << "============================" << endl;
/*	iTest.selectSort(a,6);
	cout << "int 数组，选择排序结果：" << flush;
	iTest.printArray(a,6);
	cout << "============================" << endl;
	iTest.bubbleSort(a,6);
	cout << "int 数组，冒泡排序结果：" << flush;
	iTest.printArray(a,6);
	cout << "============================" << endl;
	iTest.mergeSort(a,6);
	cout << "int 数组，归并排序结果：" << flush;
	iTest.printArray(a,6);
	cout << "============================" << endl;
	iTest.quickSort(a,6);
	cout << "int 数组，快速排序结果：" << flush;
	iTest.printArray(a,6);
	cout << "============================" << endl;
	iTest.heapSort(a,6);
	cout << "int 数组，堆排序结果：" << flush;
	iTest.printArray(a,6);
	cout << "============================" << endl;*/
	iTest.shellSort(a,6);
	cout << "int 数组，希尔排序结果：" << flush;
	iTest.printArray(a,6);
	cout << "============================" << endl;

	//在char上测试
/*	char b[]={'3','2','6','7','1','9'};
	allSort<char> cTest;
	cTest.insertSort(b,6);
	cout << "char数组，插入排序结果：" << flush;
	cTest.printArray(b,6);
	cout << "============================" << endl;
	cTest.selectSort(b,6);
	cout << "char数组，选择排序结果：" << flush;
	cTest.printArray(b,6);
	cout << "============================" << endl;
	cTest.bubbleSort(b,6);
	cout << "char数组，冒泡排序结果：" << flush;
	cTest.printArray(b,6);
	cout << "============================" << endl;
	cTest.mergeSort(b,6);
	cout << "char数组，归并排序结果：" << flush;
	cTest.printArray(b,6);
	cout << "============================" << endl;
	cTest.quickSort(b,6);
	cout << "char数组，快速排序结果：" << flush;
	cTest.printArray(b,6);
	cout << "============================" << endl;*/
	return 0;
}
