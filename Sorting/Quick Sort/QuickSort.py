# Function to partition the array into two halves
def partition(array, low, high):
    pivot = array[high]  # Select the last element as the pivot
    i = low - 1  # Index for smaller element

    for j in range(low, high):
        if array[j] < pivot:  # If the current element is smaller than the pivot
            i += 1  # Move the index forward
            array[i], array[j] = array[j], array[i]  # Swap elements

    # Place the pivot in its correct position
    array[i + 1], array[high] = array[high], array[i + 1]
    return i + 1

# Function to perform quicksort recursively
def quick_sort(array, low, high):
    if low < high:
        pi = partition(array, low, high)  # Find the partition index

        # Recursively sort the elements before and after the partition
        quick_sort(array, low, pi - 1)
        quick_sort(array, pi + 1, high)

# Sample array to demonstrate quicksort
array = [7, 9, 1, 3, 5, 2, 6, 0, 4, 8]
print("Before Sorting:", array)

quick_sort(array, 0, len(array) - 1)  # Apply quicksort

print("After Sorting:", array)
