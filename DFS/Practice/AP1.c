
#include <stdio.h>
int main()
{
    int arr[10], freq[10];
    int  i, j, count;
    printf("this program is coded by Deepak(04335304421)\n ");
    // Input 10 of array 
    // Input elements in array 
    printf("Enter elements in array 10:\n ");
    for(i=0; i<10; i++)
    {
        scanf("%d", &arr[i]);
        /* Initially initialize frequencies to -1 */
        freq[i] = -1;
    }

    for(i=0; i<10; i++)
    {
        count = 1;
        for(j=i+1; j<10; j++)
        {
            // If duplicate element is found 
            if(arr[i]==arr[j])
            {
                count++;
                // Make sure not to count frequency of same element again 
                freq[j] = 0;
            }
        }
        /* If frequency of current element is not counted */
        if(freq[i]!= 0)
        {
            freq[i] = count;
        }
    }
     // Print frequency of each element
     
    printf("\nFrequency of all elements of array : \n");
    for(i=0; i<10; i++)
    {
        if(freq[i] != 0)
        {
            printf("%d occurs %d times\n", arr[i], freq[i]);
        }
    }

    return 0;
}