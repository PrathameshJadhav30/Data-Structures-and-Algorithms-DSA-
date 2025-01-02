# Initialize an array with some elements
arr = [1, 2, 3, 4, 5]

# Define start and end indices
start = 0
end = len(arr) - 1

# Reverse the array using the two-pointer approach
while start < end:
    # Swap elements at start and end
    arr[start], arr[end] = arr[end], arr[start]
    start += 1  # Move start pointer forward
    end -= 1    # Move end pointer backward

# Print the reversed array
print(arr)
