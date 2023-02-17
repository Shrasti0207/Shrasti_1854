#include <bits/stdc++.h>
using namespace std;

void swap(int* element1, int* element2)
{
    int temporary = *element1;
    *element1 = *element2;
    *element2 = temporary;
}
 
int partition(int arr[], int lowest_element, int highest_element)
{
    int pivot = arr[highest_element]; 
    int i = (lowest_element- 1); 
    for (int j = lowest_element; j <= highest_element - 1; j++) {
        if (arr[j] < pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[highest_element]);
    return (i + 1);
}

void quickSort(int arr[], int lowest_element, int highest_element)
{
    if (lowest_element < highest_element) {
        int pi = partition(arr, lowest_element, highest_element);
        // pi is the index of the pivot element after partition
        quickSort(arr, lowest_element, pi - 1);
        quickSort(arr, pi + 1, highest_element);
    }
}

int main()
{
    // N represent number of elements in the array
    int N;
    cin>>N;
    int newArr[N], arr[N];
    
    for(int i=0; i<N; i++){
        cin>>arr[i];
         newArr[i] = arr[i];
    }
       
    quickSort(newArr, 0, N-1);
    
    int i;
    // Map to store the rank of the array element
    
    map<int, int> ranks;
 
    int rank_pointer = 1;
 
    for(int index = 0; index < N; index++)
    {
 
        int element = newArr[index];
        // Update rank of element
        if (ranks[element] == 0)
        {
            ranks[element] = rank_pointer;
            rank_pointer++;
        }
    }
 
    for(int index = 0; index < N; index++)
    {
        int element = arr[index];
        arr[index] = ranks[arr[index]]-1;
    }
    // Print the array elements
    for(int i = 0; i < N ; i++)
    {
        cout << arr[i] << " ";
    }
    
}
