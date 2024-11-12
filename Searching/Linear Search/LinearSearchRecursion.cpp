// Time Complexity : O(N)
// Space Complexity : O(1)
// Auxiliary Space Complexity : O(N) due to function call stack
#include <iostream>
using namespace std;

int LinearSearch( int arr[], int index, int item)
{
    if(arr[index] == item)
        return index;
    else if(index == -1)
        return -1;

    return LinearSearch(arr,index - 1, item);
}

int main()
{
    int arr[] = {10, 5, 25, 21, -3, 7};
    //Calculating length of array
    int len = sizeof(arr)/sizeof(arr[0]);

    //item to be Serached
    int item = 21;
    
    int index = LinearSearch(arr,len - 1,item);

    if(index >= 0)
       cout<<"Item found at index: "<<index;
    else 
       cout<<"Item not Found";

    return 0;
}