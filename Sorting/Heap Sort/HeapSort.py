# Function to heapify a subtree rooted at index i
def heapify(arr, n, i):
    largest = i  # Initialize the largest as root
    l = 2 * i + 1  # Left child index
    r = 2 * i + 2  # Right child index

    # If left child is larger than root
    if l < n and arr[l] > arr[largest]:
        largest = l

    # If right child is larger than the largest so far
    if r < n and arr[r] > arr[largest]:
        largest = r

    # If the largest is not the root
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # Swap root with the largest

        # Recursively heapify the affected subtree
        heapify(arr, n, largest)

# Function to perform Heap Sort
def heap_sort(arr):
    n = len(arr)

    # Build a max heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # Extract elements from heap one by one
    for i in range(n - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]  # Move current root to the end
        heapify(arr, i, 0)  # Call max heapify on the reduced heap

# Function to display the elements of an array
def display(arr):
    print("\t".join(map(str, arr)))

# Input array
arr = [1, 14, 3, 7, 0, 56]

print("Unsorted array:")
display(arr)  # Display unsorted array

heap_sort(arr)  # Sort the array

print("Sorted array:")
display(arr)  # Display sorted array
