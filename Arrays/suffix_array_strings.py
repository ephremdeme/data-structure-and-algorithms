from itertools import chain, islice
import functools
import time

def timer(func):
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        start_time = time.perf_counter()
        value = func(*args, **kwargs)
        end_time = time.perf_counter()
        run_time = end_time - start_time
        print("Finished {} in {} secs".format(repr(func.__name__), round(run_time, 100)))
        return value
    return wrapper

@timer
def NaiveSuffixArray(string):
    """Naive way to return a list of the starting positions of suffixes in a sorted order
    """
    #Generate an Array with suffix pairs (Suffix String & Suffex Number)
    suffixes = [(string[i:], i) for i in range(len(string))]
    #Sort the list by the suffix string
    suffixes.sort(key=lambda x: x[0])
    # Return the suffex numbers
    return print([string[1] for string in suffixes])

@timer
def ComplexSuffixArray(string):
    """A more complex way to return a list of the starting positions of suffixes in a sorted order by
    creating a list of pairs and counting through them in a sorted order
    """
    List = sorted((a, i) for i, a in enumerate(string)) # List of pairs 
    n = len(string)
    count = 1
    while count < n: # Count in a sorted order

        P = [0] * n
        for (r, i), (s, j) in zip(List, islice(List, 1, None)):
            P[j] = P[i] + (r != s)

        List = sorted(chain((((P[i],  P[i+count]), i) for i in range(n - count)),
                         (((P[i], -1), i) for i in range(n - count, n))))
        count *= 2
    return print([i for _, i in List])

NaiveSuffixArray("horse")
ComplexSuffixArray("horse")
