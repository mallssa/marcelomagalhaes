#include<stdio.h>
int* bubbleSort(int arr[])
{
    int compara=0, trocas=0;
    int n = arr[0];
    int i, j;
    for (i = 1; i < n+1 ; i++)

        // Os últimos i elementos estão no lugar certo
        for (j = 1; j < n - i+1 ; j++)
        {
            compara++;
            if (arr[j] > arr[j + 1])
            {
                int aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
                trocas++;
            }
        }
    arr[n+1] = compara;
    arr[n+2] = trocas;
    
    return arr;
}

int* selectionSort(int arr[])
{
    int n = arr[0];
    int i, j, min_idx;
    int compara=0, trocas=0;
    // One by one move boundary of unsorted subarray
    for (i = 1; i < n ; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++){
            compara++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element with the first element
        trocas++;
        int aux = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = aux;
    }
    arr[n+3] = compara;
    arr[n+4] = trocas;
   
    return arr;
}

int* insertionSort(int arr[])
{
    int compara=0, trocas=0;
    int n = arr[0];
    int i, key, j;
    for (i = 2; i < n+1; i++)
    {
        key = arr[i];
        j = i -1;

        /* Move elements of arr[0..i-1], that are 
          greater than key, to one position ahead 
          of their current position */
          compara++;
        while (j >= 0 && arr[j] > key)
        {   
            trocas++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        arr[j + 1] = key;
    }
    arr[n+5] = compara;
    arr[n+6] = trocas;
    
    return arr;
}


void merge(int arr[], int l, int m, int r) 
{ 
    int quantidade = arr[0];
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        arr[quantidade+10]++;
        if (L[i] <= R[j]) 
        { 
            arr[quantidade+11]++;
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[quantidade+11]++;
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[quantidade+11]++;
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[quantidade+11]++;
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
int* mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
    return arr;
} 