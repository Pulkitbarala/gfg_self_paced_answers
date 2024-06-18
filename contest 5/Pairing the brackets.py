def pairingBrackets(s):
    stack = []
    pairs = []

    for i, char in enumerate(s):
        if char == '(':
            stack.append(i)
        elif char == ')' and stack:
            opening_index = stack.pop(0)
            pairs.append((opening_index, i))
    
    return pairs