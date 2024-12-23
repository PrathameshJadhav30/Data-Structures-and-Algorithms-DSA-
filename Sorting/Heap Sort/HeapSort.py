# Function to heapify a subtree rooted at index 'i' in the array
def heapify(arr, n, i):
    """
    Ensures the subtree rooted at index 'i' satisfies the max-heap property.

    Args:
        arr (list): Array representation of the heap.
        n (int): Size of the heap.
        i (int): Index of the root of the subtree.

    Returns:
        None
    """
    largest = i  # Initialize the largest element as the root
    left = 2 * i + 1  # Left child index
    right = 2 * i + 2  # Right child index

    # Check if the left child exists and is greater than the root
    if left < n and arr[left] > arr[largest]:
        largest = left

    # Check if the right child exists and is greater than the current largest
    if right < n and arr[right] > arr[largest]:
        largest = right

    # If the largest is not the root, swap them and heapify the affected subtree
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # Swap
        heapify(arr, n, largest)  # Recursively heapify the affected subtree

# Function to perform Heap Sort
def heap_sort(arr):
    """
    Sorts an array using the Heap Sort algorithm.

    Args:
        arr (list): The array to be sorted.

    Returns:
        None (the array is sorted in place).
    """
    n = len(arr)  # Length of the array

    # Step 1: Build a max heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # Step 2: Extract elements from the heap one by one
    for i in range(n - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]  # Swap the root (largest) with the last element
        heapify(arr, i, 0)  # Reduce the heap size by 1 and heapify the root

# Example usage of Heap Sort
if __name__ == "__main__":
    # Input array
    arr = [12, 11, 13, 5, 6, 7]

    print("Original array:", arr)
    
    # Sort the array
    heap_sort(arr)

    print("Sorted array:", arr)
