/*
 * =============================================================================
 *  Version: 0.1 (August 23, 2013)
 *  Author: Shanshan Guan (vipgss@gmail.com), Harbin Institute of Technology Shenzhen Graduate School
 *
 * =============================================================================
 *  Copyright (c) 2013. Shanshan Guan (vipgss@gmail.com).
 * =============================================================================
 *  Introduction.
 * 已经实现常见的七种排序算法，包括：插入排序、希尔排序、选择排序、冒泡排序、归并排序、快速排序、堆排序
 * 还有基数排序没有实现
 * =============================================================================*/

#ifndef ALLSORT_H_H_H___
#define ALLSORT_H_H_H___
#include <iostream>

using namespace std;

template <class T>
class allSort
{
public:
	//插入排序
	void insertSort(T a[],int n);//n is the size of array;
	//希尔排序
	void shellSort(T a[],int n);
	void shellInsert(T a[],int inc,int n);
	//选择排序
	void selectSort(T a[],int n);
	//冒泡排序
	void bubbleSort(T a[],int n);
	//归并排序
	void mergeSort(T a[],int n);
	void recursionMerge(T a[],int first,int last,T temp[]);
	void mergeArray(T a[],int first,int mid,int last,T temp[]);
	//快速排序
	void quickSort(T a[],int n);
	void QuickSort(T a[],int low,int high);
	//堆排序
	void heapSort(T a[],int n);
	void createMinHeap(T a[],int n);
	void filterMinHeap(T a[],int start,int n);
	void createMaxHeap(T a[],int n);
	void filterMaxHeap(T a[],int start,int n);
	//打印结果
	void printArray(T a[],int n);
};

// 模板类要统一定义在头文件里面
template <class T> void allSort<T>::insertSort(T a[],int n)
{
	if (a==NULL || n<=0)
	{
		cout << "输入参数有问题！" << endl;
		return ;
	}
	T flag;//哨兵
	int j = 0;
	for(int i=1;i<n;++i)
	{
		flag = a[i];
		for(j=i-1;j>=0;j--)
		{
			if(flag<a[j])
			{
				a[j+1]=a[j];
			}
			else
				break;
		}
		a[j+1]=flag;
	}
}

template <class T> void allSort<T>::shellSort(T a[],int n)
{
	if (a==NULL || n<=0)
	{
		cout << "输入参数有问题！" << endl;
		return ;
	}
	int inc = n/2;
	for(;inc>0;inc/=2)
	{
		shellInsert(a,inc,n);
	}
}

template <class T> void allSort<T>::shellInsert(T a[],int inc,int n)
{
	int j;
	T flag;
	for(int i=inc;i<n;i++)
	{
		flag = a[i];
		for(j=i-inc;j>=0;j-=inc)
		{
			if(flag<a[j])
			{
				a[j+inc]=a[j];
			}
			else
			{
				break;
			}
		}
		a[j+inc]=flag;
	/*	j = i;//风格与之前插入排序保持一致,所以用上面的代码
		while(j>=0 && a[j-inc]>flag)
		{
			a[j]=a[j-inc];
			j-=inc;
		}
		a[j]=flag;//是不是有可能j<0啊，这段代码有问题*/
	}
}

template <class T> void allSort<T>::selectSort(T a[],int n)
{
	if (a==NULL || n<=0)
	{
		cout << "输入参数有问题！" << endl;
		return ;
	}
	int min = -1;
	T temp;
	//i=n-1的时候已经不需要比了，所以是i<n-1
	for(int i=0;i<n-1;++i)
	{
		min=i;
		for(int j=i+1;j<n;++j)
		{
			if(a[min]>a[j])
			{
				min = j;
			}
		}
		if(min!=i)
		{
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}
}

template <class T> void allSort<T>::bubbleSort(T a[],int n)
{
	if (a==NULL || n<=0)
	{
		cout << "输入参数有问题！" << endl;
		return ;
	}
	int i = 0;
	int j = 0;
	bool change=true;
	T temp;
	//大的数字往下沉
	for (i=n-1;i>0&&change;--i)
	{
		change=false;
		for (j=0;j<i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				change = true;
			}
		}
	}
}

template <class T> void allSort<T>::mergeSort(T a[],int n)
{
	if (a==NULL || n<=0)
	{
		cout << "输入参数有问题！" << endl;
		return ;
	}
	int first = 0;
	int last = n-1;
	T * temp = new T[n];
	recursionMerge(a,first,last,temp);
}

template <class T> void allSort<T>::recursionMerge(T a[],int first,int last,T temp[])
{
	int mid = (first+last)/2;
	if(first<last)
	{
		recursionMerge(a,first,mid,temp);
		recursionMerge(a,mid+1,last,temp);
		mergeArray(a,first,mid,last,temp);
	}
}

template <class T> void allSort<T>::mergeArray(T a[],int first,int mid,int last,T temp[])
{
	int i = first;
	int j = mid+1;
	int m = mid;
	int n = last;
	int k = 0;
	while(i<=m&&j<=n)
	{
		if(a[i]<a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while(i<=m)
	{
		temp[k++] = a[i++];
	}
	while(j<=n)
	{
		temp[k++] = a[j++];
	}
	for (int index = 0; index < k; ++index)
	{
		a[first+index]=temp[index];
	}
}

template <class T> void allSort<T>::quickSort(T a[],int n)
{
	if (a==NULL || n<=0)
	{
		cout << "输入参数有问题！" << endl;
		return ;
	}
	QuickSort(a,0,n-1);
}

template <class T> void allSort<T>::QuickSort(T a[],int low,int high)
{
	int i = low;
	int j = high;
	int key = a[low];
	while(low<high)
	{
		while(low<high && a[high]>=key)
			--high;
		a[low] = a[high];
		while(low<high && a[low]<=key)
			++low;
		a[high] = a[low];
	}
	a[low] = key;
	if(low<high)
	{
		QuickSort(a,i,low-1);
		QuickSort(a,low+1,j);
	}
}

template <class T> void allSort<T>::heapSort(T a[],int n)
{
	if (a==NULL || n<=0)
	{
		cout << "输入参数有问题！" << endl;
		return ;
	}
	int size;
//	createMinHeap(a,n);
	createMaxHeap(a,n);
	for(size=n-1;size>0;size--)
	{
		swap(a[0],a[size]);
//		filterMinHeap(a,0,size);
		filterMaxHeap(a,0,size);
	}
}

template <class T> void allSort<T>::createMinHeap(T a[],int n)
{
	//为什么是(n-2)/2？本应该是(n-1)/2;但是因为下取整，分子上再减一
	int start = (n-2)/2;
	for (start = (n-2)/2; start >=0; start--)
	{
		filterMinHeap(a,start,n);
	}
}

template <class T> void allSort<T>::createMaxHeap(T a[],int n)
{
	//为什么是(n-2)/2？本应该是(n-1)/2;但是因为下取整，分子上再减一
	int start = (n-2)/2;
	for (start = (n-2)/2; start >=0; start--)
	{
		filterMaxHeap(a,start,n);
	}
}

//调整堆，以循环的方式实现，调整为最小堆
template <class T> void allSort<T>::filterMinHeap(T a[],int start, int n)
{
	int i=start;
	int j=2*i+1;
	T temp = a[i];
	while(j<n)
	{
		if(j+1<n && a[j]>a[j+1])
			++j;
		if(a[j]>temp)
			break;
		else
		{
			a[i] = a[j];
			i=j;
			j=2*i+1;
		}
		a[i]=temp;
	}
}

//调整堆，以递归的方式实现，调整为最大堆
template <class T> void allSort<T>::filterMaxHeap(T a[],int node,int n)
{
	int left = 2*node+1;
	int right = 2*node+2;
	int largest = node;
	if (left<n && a[left]>a[node])
		largest = left;
	if (right<n && a[right]>a[largest])
		largest = right;
	if (largest!=node)
	{
		swap(a[largest],a[node]);
		filterMaxHeap(a,largest,n);
	}

}

template <class T> void allSort<T>::printArray(T a[],int n)
{
	for(int i=0;i<n;++i)
		cout << a[i] << "  " << flush;
	cout << endl;
}
#endif
