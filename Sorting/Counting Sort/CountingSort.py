# Function to perform Counting Sort
def count_sort(arr):
    # Find the largest element in the array
    max_val = max(arr)
    count = [0] * (max_val + 1)  # Initialize count array
    output = [0] * len(arr)  # Output array to store sorted elements

    # Store the count of each element in the input array
    for num in arr:
        count[num] += 1

    # Update the count array to store the cumulative count
    for i in range(1, len(count)):
        count[i] += count[i - 1]

    # Build the output array by placing elements at their correct positions
    for num in reversed(arr):
        output[count[num] - 1] = num
        count[num] -= 1

    # Copy the sorted elements from the output array back to the input array
    for i in range(len(arr)):
        arr[i] = output[i]

# Function to display an array
def display(arr):
    print(" ".join(map(str, arr)))

# Input array
array = [2, 5, 2, 8, 1, 4, 1]
count_sort(array)  # Call the counting sort function
display(array)  # Display the sorted array
