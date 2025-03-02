#include <iostream>
#include <pthread.h>
#include <vector>
#include <chrono>
using namespace std;
#define MAX_NUM 100000000
typedef struct Arg
{
    vector<int> *v;
    int left;
    int right;
    int depth;
} args;
void Data(vector<int> &v)
{
    srand((size_t)time(NULL));
    for (int i = 0; i < MAX_NUM; i++)
        v.push_back(rand());
}
void merge(vector<int> &v, int left, int mid, int right)
{
    vector<int> tmp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
    {
        if (v[i] < v[j])
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
    while (j <= right)
    {
        tmp[k++] = v[j++];
    }
    for (k = 0; k < tmp.size(); k++)
    {
        v[left + k] = tmp[k];
    }
}
void *mergesort(void *arg)
{
    args *ag = (args *)arg;
    int left = ag->left, right = ag->right;
    ag->depth++;
    vector<int> &v = *(ag->v);
    if (left >= right)
    {
        delete ag;
        return nullptr;
    }
    int mid = left + (right - left) / 2;
    args *la = new args{&v, left, mid, ag->depth};
    args *lb = new args{&v, mid + 1, right, ag->depth};

    if (ag->depth < 8)
    {
        pthread_t pth1, pth2;
        pthread_create(&pth1, nullptr, mergesort, la);
        pthread_create(&pth2, nullptr, mergesort, lb);

        pthread_join(pth1, nullptr);
        pthread_join(pth2, nullptr);
    }
    else
    {
        mergesort(la);
        mergesort(lb);
    }
    delete ag;
    merge(v, left, mid, right);
    return nullptr;
}
int main()
{
    vector<int> v;
    Data(v);
    auto start = chrono::high_resolution_clock::now();
    args *av = new args{&v, 0, MAX_NUM - 1, 0};
    pthread_t main_pth;
    pthread_create(&main_pth, nullptr, mergesort, av);
    pthread_join(main_pth, nullptr);
    // for (int i = 0; i < MAX_NUM; i++)
    // {
    //     cout << v[i] << endl;
    // }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> time_s = end - start;
    cout << time_s.count() << endl;
}