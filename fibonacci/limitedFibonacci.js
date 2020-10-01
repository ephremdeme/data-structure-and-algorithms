function limited_fibonacci_series (valueLimit) {
    // initial fibonacci sequence
    let fibonacciSequence = [0, 1]
    let lastTermIndex = 1

    // if the limit is given as 0
    if (valueLimit === 0) {
        return [0]
    } else {
        // generate sequence till the limit is reached
        while (fibonacciSequence[lastTermIndex] < valueLimit) {
            fibonacciSequence.push(fibonacciSequence[lastTermIndex] + fibonacciSequence[lastTermIndex - 1])
            lastTermIndex = lastTermIndex + 1
        }
        // if the limit is equal to the last generated term then return the whole series
        if (fibonacciSequence[lastTermIndex] === valueLimit) {
            return fibonacciSequence
        } else {
            // if the limit is less than the last generated term then remove the last generated term
            return fibonacciSequence.slice(0, fibonacciSequence.length - 1)
        }
    }
};

// call the generate the sequence with the parameter indicating the limit upto which the sequence is to be generated
limited_fibonacci_series(8);
