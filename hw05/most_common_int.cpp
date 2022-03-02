/*
 * most_common_int.cpp
 * 
 * By:  Eddy Zhang
 */
#include <iostream>

using namespace std;
 
 /*
  * Purpose:   get the integer that appears the most times
  * Returns:   the integer
  */
int most_common_int(int numbers[], int length);
void test(int arr[], int res, int length);
void print(int arr[], int length);

int main()
{       
        int arr1[] = {1,2,2,3,4,4,4,5};
        int arr2[] = {0};
        int arr3[] = {1,1,1,1,2,2,2,2};
        int arr4[] = {1,3,4,4,3,2,2,7,7};
        test(arr1, 4, 8);
        test(arr2, 0, 1);
        test(arr3, 1, 8);
        test(arr4, 2, 9);
        return 0;
}

/*
 * Purpose:   get the integer that appears the most times
 * Returns:   the integer
 */
int most_common_int(int numbers[], int length)
{
    int max = 999;
    int max_count = 0;
    for (int i = 0; i < length; i++)
    {
        int count = 1;
        
        for (int j = i + 1; j < length; j++)
        {
            if (numbers[i] == numbers[j])
            count ++;
        }
    
        if (count > max_count) 
        {
            max_count = count; 
            max = numbers[i];
        } 
        else if (count == max_count and numbers[i] < max)
            max = numbers[i];
    }
    return max;
}

/*
 * the test function for the main function
 */
void test(int arr[], int res, int length)
{
    cout << "TESTING: ";
    print(arr, length);
    cout << endl;
    if (most_common_int(arr, length) == res)
    cout << "SUCCESS: " << most_common_int(arr, length) << endl;
    else
    cout << "FAILURE: " << most_common_int(arr, length) << endl;
}

/*
 * the function that prints the array
 */
void print(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    cout << arr[i] << " ";
}