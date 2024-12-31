# Function to display the elements of the array
def display(array):
    for element in array:
        print(element, end="\t")  # Print each element separated by a tab
    print()  # Move to the next line after displaying all elements

# Function to sort the array using the Selection Sort algorithm
def selection_sort(array):
    size = len(array)
    for i in range(size - 1):
        # Find the index of the minimum element in the remaining unsorted part
        min_index = i
        for j in range(i + 1, size):
            if array[j] < array[min_index]:
                min_index = j  # Update min_index if a smaller element is found
        # Swap the smallest element with the current element at index i
        array[i], array[min_index] = array[min_index], array[i]

# Array initialization
array = [5, 3, 1, 9, 8, 2, 4, 7]

# Display the array before sorting
print("Before sorting:")
display(array)

# Sort the array
selection_sort(array)

# Display the array after sorting
print("After sorting:")
display(array)
