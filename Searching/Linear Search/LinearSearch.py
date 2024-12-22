def linear_search(arr, target):
    """
    Perform linear search to find the target element in the array.

    Args:
    arr (list): List of elements to search through.
    target (any): Element to search for.

    Returns:
    int: Index of the target element if found, else -1.
    """
    # Loop through each element in the array
    for index in range(len(arr)):
        # Check if the current element matches the target
        if arr[index] == target:
            return index  # Return the index if target is found

    return -1  # Return -1 if target is not found

# Example usage of Linear Search
arr = [10, 20, 30, 40, 50]
target = 30
result = linear_search(arr, target)
if result != -1:
    print(f"Element {target} found at index {result}")
else:
    print(f"Element {target} not found in the array")
