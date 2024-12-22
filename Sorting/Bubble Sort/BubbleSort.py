def bubble_sort(arr):
    """
    Perform bubble sort on the given array.

    Args:
    arr (list): List of elements to be sorted.

    Returns:
    None: The array is sorted in place.
    """
    n = len(arr)  # Get the length of the array

    # Loop through the entire array multiple times
    for i in range(n):
        # Flag to check if any swapping happened in this pass
        swapped = False

        # Compare adjacent elements and swap if needed
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]  # Swap
                swapped = True

        # If no elements were swapped, the array is already sorted
        if not swapped:
            break

# Example usage of Bubble Sort
arr = [64, 34, 25, 12, 22, 11, 90]
print("Original array for Bubble Sort:", arr)
bubble_sort(arr)
print("Sorted array using Bubble Sort:", arr)
