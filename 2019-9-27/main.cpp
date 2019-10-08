#include <iostream>
#include <algorithm>
#include "sortTestHelper.h"
#include "MergeSortHelper.h"
using namespace std;
using namespace SortTestHelper;
using namespace MergeSortHelper;

//mergeSortBU means "bottom up"
template <typename T>
void mergeSortBU(T arr[], int n){
    //首轮循环，对元素的个数进行遍历，元素个数变化，1,2,4,8...
    for(int sz = 1; sz <= n; sz+=sz)
    {
        //第二轮循环，是具体每一论在归并过程中起始的元素位置
        //处理第一个越界问题：把i<n改成i+sz<n
        for (int i = 0; i+sz < n; i+=sz+sz)
        {
            //对arr[i...i+sz-1]  和 arr[i+sz...i+2*sz-1]进行归并
            //归并就是要将两个有序的部分合并成一个有序的部分
            //处理第二个越界问题： i+2*sz-1 可能会大于n, 所以取 i+2*sz-1 和 n-1的最小值
            //i--l, i+sz--mid, min(i+2*sz-1, n-1)---r
            __merge(arr, i, i+sz-1, min(i+2*sz-1, n-1));

        }
    }
}
//**********************************************************************
//快速排序
//*********************************************************************
//对arr[l,...,r]部分进行partition操作
//返回一个索引值 p ， 使得arr[l...p-1] < arr[p]; arr[p] < arr[p+1...r]



template <typename T>
int __partition(T arr[], int l, int r)
{
    //先取一个标准 （最左侧的元素） v
    T v = arr[l];
    //将l+1到r之间的元素分成两部分
    //一部分arr[l+1...j] < v; 另一部分 arr[j+1...i) > v
    //i表示当前遍历到的元素的位置， i <= r

    int j = l;  //j 初始化为l, 这样在初始的情况下arr[l+1...j]数组为空
    for (int i = l+1; i <= r; i++)
    {
        //令i=l+1, 初始化， 使得数组   arr[j+1...i) 为空
       /* if(arr[i] > v) //如果当前元素大于v, 只需要i++，其他都不需要*/
        if(arr[i] < v)
        {
            //交换j+1位置的元素和i位置的元素
            swap(arr[j+1], arr[i]);
            j++;
            //或者将上面两个语句直接写成swap(arr[++j], arr[i]);
        }
    }
    //最后要做的事情就是将l位置的元素v与j的位置元素进行交换
    swap(arr[l], arr[j]);
    return j;
}

//对arr[l,...,r]部分进行快速排序
template <typename T>
void __quickSort(T arr[], int l, int r)
{
    if(l >= r)
    {
        return;
    }
    //调用子函数patition, 对arr数组进行partition操作，返回一个索引值给p
    //再调用__quickSort函数，即可
    int p = __partition(arr, l, r);
    //递归
    __quickSort(arr, l, p-1);
    __quickSort(arr, p+1, r);


}

//使用递归，对整个数组进行快快速排序
template <typename T>
void quickSort(T arr[], int n)
{
    __quickSort(arr, 0, n-1);
}


int main() {

    int n = 1000000;

    cout << "test for random array, size = " << n << "random range [0, " << n << "]" << endl;
    int* arr1 = generateRandomArray(n, 0, n);
    int* arr2 = copyIntArray(arr1, n);

    testSort("merge sort", mergeSort, arr1, n);
    testSort("quick sort", quickSort, arr2, n);

    delete[] arr1;
    delete[] arr2;
    cout << endl;



    return 0;
}