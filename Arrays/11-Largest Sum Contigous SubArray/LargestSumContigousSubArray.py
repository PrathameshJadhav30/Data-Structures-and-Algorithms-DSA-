# Input array
arr = [-2, -3, 4, -1, -2, 1, 5, -3]

# Initialize variables
max_sum = float('-inf')  # Tracks the maximum subarray sum
curr_sum = 0             # Tracks the sum of the current subarray

# Traverse the array
for i in range(len(arr)):
    curr_sum += arr[i]                # Add the current element to the subarray sum
    max_sum = max(max_sum, curr_sum)  # Update the maximum sum if needed

    # If the current sum becomes negative, reset it to 0
    if curr_sum < 0:
        curr_sum = 0

# Output the maximum subarray sum
print(max_sum)
