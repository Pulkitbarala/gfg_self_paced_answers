def closestFriends(arr, n):
    result = []
    stack = []

    for i in range(n):
        while stack and arr[stack[-1]] >= arr[i]:
            stack.pop()
        
        if not stack:
            result.append(-1)
        else:
            result.append(stack[-1])
        
        stack.append(i)
    
    return result