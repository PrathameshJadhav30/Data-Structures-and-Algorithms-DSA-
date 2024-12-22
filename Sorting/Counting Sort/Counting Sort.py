# Counting Sort function
def counting_sort(arr):
    """
    Perform counting sort on the given list.
    """
    # Step 1: Find the maximum value in the array
    max_element = max(arr)
    
    # Step 2: Create a count array of size max_element + 1, initialized to 0
    count = [0] * (max_element + 1)
    
    # Step 3: Count occurrences of each element in the input array
    for num in arr:
        count[num] += 1
    
    # Step 4: Reconstruct the sorted array using the count array
    index = 0
    for i in range(len(count)):
        while count[i] > 0:
            arr[index] = i
            index += 1
            count[i] -= 1

# Example usage
if __name__ == "__main__":
    arr = [4, 2, 2, 8, 3, 3, 1]
    print("Original array:", arr)
    counting_sort(arr)
    print("Sorted array:", arr)
