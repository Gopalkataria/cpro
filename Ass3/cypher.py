def findSpecialString(s, k):
    n = len(s)
    max_possible_distance = 0
    
    # Calculate the maximum possible cipher distance
    for i in range(n):
        max_possible_distance += min(ord(s[i]) - ord('a'), ord('z') - ord(s[i]))
    
    # Check if k is within the possible range
    if (k) < 0 or k > max_possible_distance:
        return -1
    
    # Initialize s' with all 'a' characters
    s_prime = ['a'] * n
    
    # Iterate through the characters of s and update s_prime
    for i in range(n):
        # Calculate the maximum possible increase in character value for s_prime[i]
        max_increase = min(ord(s[i]) - ord('a'), ord('z') - ord(s[i]))
        
        # Distribute the increase across the characters in s_prime to minimize lexicographic order
        if k >= max_increase:
            s_prime[i] = chr(ord(s[i]) + max_increase)
            k -= max_increase
        else:
            s_prime[i] = chr(ord(s[i]) + k)
            break
    
    return ''.join(s_prime)

# Example usage
s = input()
k = input() 
result = findSpecialString(s, k)
print(result)  # Output: "dbo"
