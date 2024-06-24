#include <iostream> 
using namespace std; 

int Max(int arr[], int n) 
{ 
  int a = arr[0]; 
  for (int i = 1; i < n; i++) 
    if (arr[i] > a) 
      a = arr[i]; 
  return a; 
} 
void cSort(int arr[], int n, int exp) 
{ 
  int output[n];
  int i, count[10] = { 0 }; 

  for (i = 0; i < n; i++) 
    count[(arr[i] / exp) % 10]++; 

  for (i = 1; i < 10; i++) 
    count[i] += count[i - 1]; 

  for (i = n - 1; i >= 0; i--) { 
    output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
    count[(arr[i] / exp) % 10]--; 
  } 

  for (i = 0; i < n; i++) 
    arr[i] = output[i]; 
} 

void radixsort(int arr[], int n) 
{  
  int m = Max(arr, n); 

  for (int exp = 1; m / exp > 0; exp *= 10) 
    cSort(arr, n, exp); 
} 


void print(int arr[], int n) 
{ 
  for (int i = 0; i < n; i++) 
    cout << arr[i] << " "; 
} 

int main() 
{ 
  int arr[] = { 85,14,94,105,436,39,23,76,174 }; 
  int n = sizeof(arr) / sizeof(arr[0]); 
  
  radixsort(arr, n); 
  print(arr, n); 
  return 0; 
}