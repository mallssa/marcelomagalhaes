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
    arr[n+3] = 1;
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
        for (j = i + 1; j < n+1; j++)
            compara++;
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        trocas++;
        int aux = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = aux;
    }
    arr[n+1] = compara;
    arr[n+2] = trocas;
    arr[n+3] = 2;
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
        while (j >= 0 && arr[j] > key)
        {   
            compara++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        trocas++;
        arr[j + 1] = key;
    }
    arr[n+1] = compara;
    arr[n+2] = trocas;
    arr[n+3] = 3;
    return arr;
}