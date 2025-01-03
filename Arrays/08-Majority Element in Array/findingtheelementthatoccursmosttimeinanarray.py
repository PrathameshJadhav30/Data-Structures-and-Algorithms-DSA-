def find_majority_element(arr):
    """
    Finds the majority element in an array using the Boyer-Moore Voting Algorithm.
    A majority element is an element that appears more than n/2 times.
    
    :param arr: List of integers
    :return: Majority element if it exists, otherwise -1
    """
    candidate = None  # Candidate for the majority element
    count = 0         # Count of occurrences of the candidate element

    # Phase 1: Candidate selection
    for num in arr:
        if count == 0:
            # Set the current element as the candidate
            candidate = num
            count = 1
        elif num == candidate:
            count += 1  # Increment count if the current element matches the candidate
        else:
            count -= 1  # Decrement count if the current element does not match

    # Phase 2: Verification
    count = sum(1 for num in arr if num == candidate)  # Count occurrences of the candidate
    if count > len(arr) // 2:
        return candidate
    else:
        return -1  # Return -1 if no majority element exists


# Example usage
arr = [3, 3, 4, 2, 4, 4, 2, 4, 4]  # Example array
majority_element = find_majority_element(arr)

# Output the result
if majority_element != -1:
    print(f"Majority element is: {majority_element}")
else:
    print("No majority element found")
