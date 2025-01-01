# Declare and initialize a 2D list with 2 rows and 3 columns
x = [
    [1, 2, 3],
    [4, 5, 6]
]

# Loop through each row
for i in range(len(x)):  # len(x) gives the number of rows
    # Loop through each column in the current row
    for j in range(len(x[i])):  # len(x[i]) gives the number of columns in the current row
        # Print the value of the current element with its index
        print(f"Element at x[{i}][{j}]: {x[i][j]}")
