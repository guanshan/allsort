#include "allSort.h"

using namespace std;

template <class T> void allSort<T>::insertSort(T a[],int n)
{
	T flag;//哨兵
	for(int i=1;i<n;++i)
	{
		flag = a[i];
		for(int j=i-1;j>=0;j--)
		{
			if(flag<a[j])
			{
				a[j+1]=a[j];
				a[j]=flag;
			}
		}
	}
}

template <class T> void allSort<T>::selectSort(T a[],int n)
{
	int min = -1;
	T temp;
	for(int i=0;i<n;++i)
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
	int i = 0;
	int j = 0;
	bool change=true;
	T temp;
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
	QuickSort(a,0,n-1);
}

template <class T> void allSort<T>::QuickSort(T a[],int low,int high)
{
	int i = low;
	int j = high;
	int key = a[low];
	while(low<high)
	{
		while(low<high && a[high]>key)
			--high;
		a[low] = a[high];
		while(low<high && a[low]<key)
			++low;
		a[high] = a[low];
		a[low] = key;
		QuickSort(a,i,low-1);
		QuickSort(a,low+1,j);
	}
}

template <class T> void allSort<T>::heapSort(T a[],int n)
{
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
