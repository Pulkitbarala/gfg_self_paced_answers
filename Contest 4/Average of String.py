import math
def avgOfString(s):
    ascii_sum = sum(ord(char) for char in s)
    length = len(s)
    avg = ascii_sum / length
    return math.floor(avg)
