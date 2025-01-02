# Function to left rotate an array by 'd' positions
def left_rotate(arr, d):
    n = len(arr)
    for _ in range(d):
        temp = arr[0]  # Store the first element
        # Shift all elements to the left
        for j in range(n - 1):
            arr[j] = arr[j + 1]
        arr[n - 1] = temp  # Place the first element at the end

# Function to right rotate an array by 'd' positions
def right_rotate(arr, d):
    n = len(arr)
    for _ in range(d):
        temp = arr[n - 1]  # Store the last element
        # Shift all elements to the right
        for j in range(n - 1, 0, -1):
            arr[j] = arr[j - 1]
        arr[0] = temp  # Place the last element at the beginning

# Example usage
arr = [1, 2, 3, 4, 5]  # Example array
d = 2  # Number of positions to rotate

print("Original Array:", arr)

# Perform left rotation
left_rotate(arr, d)
print("Left Rotated Array:", arr)

# Perform right rotation
right_rotate(arr, d)
print("Right Rotated Array:", arr)
