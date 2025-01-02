# Function to find all pairs in the array that sum up to the target_sum
def find_pairs(arr, target_sum):
    # Step 1: Sort the array to use the two-pointer technique
    arr.sort()

    left = 0              # Pointer starting from the beginning
    right = len(arr) - 1  # Pointer starting from the end

    # Step 2: Use the two-pointer technique to find pairs
    while left < right:
        curr_sum = arr[left] + arr[right]  # Calculate the sum of elements at the left and right pointers

        if curr_sum == target_sum:  # If the current sum matches the target sum
            print(f"Pair found: {arr[left]} and {arr[right]}")
            left += 1   # Move the left pointer forward
            right -= 1  # Move the right pointer backward
        elif curr_sum < target_sum:  # If current sum is less than the target
            left += 1  # Increase the sum by moving the left pointer forward
        else:  # If current sum is greater than the target
            right -= 1  # Decrease the sum by moving the right pointer backward


# Input array and target sum
arr = [5, 8, 1, 4, 6, 3, 2, 7]
target_sum = 10

# Call the function to find pairs
find_pairs(arr, target_sum)
