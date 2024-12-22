def binary_search(arr, target):
    """
    Perform binary search to find the target element in a sorted array.

    Args:
    arr (list): Sorted list of elements to search through.
    target (any): Element to search for.

    Returns:
    int: Index of the target element if found, else -1.
    """
    # Define the initial left and right pointers
    left, right = 0, len(arr) - 1

    # Continue searching while the search space is not empty
    while left <= right:
        # Calculate the middle index
        mid = left + (right - left) // 2

        # Check if the middle element is the target
        if arr[mid] == target:
            return mid  # Return the index if target is found

        # If target is smaller, search in the left half
        elif arr[mid] > target:
            right = mid - 1

        # If target is larger, search in the right half
        else:
            left = mid + 1

    return -1  # Return -1 if target is not found

# Example usage of Binary Search
arr = [10, 20, 30, 40, 50]  # Array must be sorted
target = 40
result = binary_search(arr, target)
if result != -1:
    print(f"Element {target} found at index {result}")
else:
    print(f"Element {target} not found in the array")
