# Function to merge two subarrays
def merge(arr, left, mid, right):
    # Sizes of the two subarrays
    n1 = mid - left + 1
    n2 = right - mid

    # Create temporary arrays
    L = [arr[left + i] for i in range(n1)]
    R = [arr[mid + 1 + i] for i in range(n2)]

    # Merge temporary arrays back into arr
    i = 0  # Index for L
    j = 0  # Index for R
    k = left  # Index for main array

    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    # Copy any remaining elements of L[]
    for x in range(i, n1):
        arr[k] = L[x]
        k += 1

    # Copy any remaining elements of R[]
    for x in range(j, n2):
        arr[k] = R[x]
        k += 1

# Function to perform merge sort
def merge_sort(arr, left, right):
    if left < right:
        # Find the middle point
        mid = left + (right - left) // 2

        # Recursively sort first and second halves
        merge_sort(arr, left, mid)
        merge_sort(arr, mid + 1, right)

        # Merge the sorted halves
        merge(arr, left, mid, right)

# Test the Merge Sort
arr = [38, 27, 43, 3, 9, 82, 10]
print("Original array:", arr)

merge_sort(arr, 0, len(arr) - 1)

print("Sorted array:", arr)
