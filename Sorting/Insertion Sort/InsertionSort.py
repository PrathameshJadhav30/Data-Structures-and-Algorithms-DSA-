def insertion_sort(arr):
    """
    Perform insertion sort on the given array.

    Args:
    arr (list): List of elements to be sorted.

    Returns:
    None: The array is sorted in place.
    """
    # Iterate over the array starting from the second element
    for i in range(1, len(arr)):
        # Store the current element to be placed
        key = arr[i]
        j = i - 1

        # Move elements of arr[0..i-1], that are greater than key,
        # one position ahead of their current position
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]  # Shift element one position to the right
            j -= 1

        # Place the key element in its correct position
        arr[j + 1] = key

# Example usage of Insertion Sort
arr = [64, 34, 25, 12, 22, 11, 90]
print("Original array for Insertion Sort:", arr)
insertion_sort(arr)
print("Sorted array using Insertion Sort:", arr)
