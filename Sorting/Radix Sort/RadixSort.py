# Function to get the largest element from the array
def get_max(arr):
    return max(arr)

# Counting sort to sort elements based on the digit represented by `place`
def counting_sort(arr, place):
    base = 10  # Base of the number system
    n = len(arr)
    output = [0] * n  # Output array
    count = [0] * base  # Count array

    # Count occurrences of each digit at the given place
    for num in arr:
        digit = (num // place) % base
        count[digit] += 1

    # Calculate cumulative count to determine positions
    for i in range(1, base):
        count[i] += count[i - 1]

    # Build the output array
    for i in range(n - 1, -1, -1):
        digit = (arr[i] // place) % base
        output[count[digit] - 1] = arr[i]
        count[digit] -= 1

    # Copy the sorted elements back to the original array
    for i in range(n):
        arr[i] = output[i]

# Main function to implement Radix Sort
def radix_sort(arr):
    # Get the maximum number to determine the number of digits
    max_num = get_max(arr)

    # Perform counting sort for each digit, starting from least significant
    place = 1
    while max_num // place > 0:
        counting_sort(arr, place)
        place *= 10

# Function to display the array
def display(arr):
    print("\t".join(map(str, arr)))

# Demonstration of the radix sort
arr = [112, 400, 543, 441, 678, 675, 9, 777]
print("Before sorting:")
display(arr)

radix_sort(arr)

print("After sorting:")
display(arr)
