def suffixArray(string):
    #Generate an Array with suffix pairs (Suffix String & Suffex Number)
    suffixes = [(string[i:], i) for i in range(len(string))]
    #Sort the list by the suffix string
    suffixes.sort(key=lambda x: x[0])
    # Return the suffex numbers
    return print([string[1] for string in suffixes])

suffixArray("horse")