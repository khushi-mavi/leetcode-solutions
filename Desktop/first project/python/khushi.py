def toggle_check(original, faulty):
    # Check how many bits differ between two 3x3 segments
    diff_count = 0
    for i in range(9):
        if original[i] != faulty[i]:
            diff_count += 1
    return diff_count == 1

def solve():
    # Read the first 3 lines representing the 3x3 matrices of digits 0 to 9
    digits_matrix = []
    for _ in range(3):
        digits_matrix.append(input().strip())
    
    # Create a dictionary mapping each digit (0-9) to its 3x3 bit string representation
    digits = {}
    for i in range(10):
        digit_bits = ""
        for row in range(3):
            digit_bits += digits_matrix[row][i*3:(i+1)*3]
        digits[i] = digit_bits
    
    # Read the next 3 lines representing the faulty 7-segment display of the number
    input_matrix = []
    for _ in range(3):
        input_matrix.append(input().strip())
    
    # Convert the input number into a list of 3x3 matrices (represented as strings)
    input_digits = []
    for i in range(0, len(input_matrix[0]), 3):
        input_digit_bits = ""
        for row in range(3):
            input_digit_bits += input_matrix[row][i:i+3]
        input_digits.append(input_digit_bits)
    
    total_sum = 0
    
    for input_digit in input_digits:
        possible_numbers = set()
        
        # Check the original input digit itself
        for i in range(10):
            if input_digit == digits[i]:
                possible_numbers.add(i)
        
        # Check if toggling any one bit can make it a valid number
        for i in range(10):
            if toggle_check(digits[i], input_digit):
                possible_numbers.add(i)
        
        # If no valid transformation found, print "Invalid" and return
        if not possible_numbers:
            print("Invalid")
            return
        
        # Add the numbers to the sum
        total_sum += sum(possible_numbers)
    
    print(total_sum)

