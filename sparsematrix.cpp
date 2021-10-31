#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void Bsort(int arr[], int n, int k)
{
    int max_ele = arr[0];
    // max element
    for (int i = 1; i < n; i++)
    {
        max_ele = max(max_ele, arr[i]);
    }
    max_ele++;
    vector<int> bkt[k];
    // filling buckets
    for (int i = 0; i < n; i++)
    {
        int b = (k * arr[i]) / max_ele;
        bkt[b].push_back(arr[i]);
    }
    // sorting elements in buckets
    for (int i = 0; i < k; i++)
    {
        sort(bkt[i].begin(), bkt[i].end());
    }
    // concatinating
    int index = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < bkt[i].size(); j++)
        {
            arr[index++] = bkt[i][j];
        }
    }
}
int main()
{
 int arr[10] = {34,21,32,45,85,91,23,65,5,73};
 Bsort(arr, 10, 4);
 for (auto &x : arr)
    {
        cout << x << " ";
    }

    return 0;
}