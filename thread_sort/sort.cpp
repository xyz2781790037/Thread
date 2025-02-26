#include <iostream>
#include <vector>
#include <iterator>
#include <climits>
using namespace std;
#define MAX_NUM 100000
void merge(vector<int> &v, int left, int mid, int right)
{
    vector<int> tmp(right - left + 1); // 临时数组存放合并结果
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
    {
        if (v[i] <= v[j])
        {
            tmp[k++] = v[i++];
        }
        else
        {
            tmp[k++] = v[j++];
        }
    }
    while (i <= mid)
    {
        tmp[k++] = v[i++];
    }
    while(j <= right)
    {
        tmp[k++] = v[j++];
    }
    for (k = 0; k < tmp.size();k++)
    {
        v[left + k] = tmp[k];
    }
}
void mergeSort(vector<int> &nums, int left, int right)
{
    // 终止条件
    if (left >= right)
        return; // 当子数组长度为 1 时终止递归
    // 划分阶段
    int mid = left + (right - left) / 2; // 计算中点
    // 通过这种方式来避免溢出
    mergeSort(nums, left, mid);      // 递归左子数组
    mergeSort(nums, mid + 1, right); // 递归右子数组
    // 合并阶段
    merge(nums, left, mid, right);
}
int main()
{
    vector<int> v = {1, 10, 4, 5, 3, 2, 7, 8, 6, 9};
    mergeSort(v, 0, v.size() - 1);
    for (int i = 0; i < 10; i++)
    {
        cout << v[i] << endl;
    }
    return 0;
}