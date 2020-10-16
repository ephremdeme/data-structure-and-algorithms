function isArmstrong (valueToCheck) {
    let digits = []
    let numberOfDigits = 0
    let sum = 0
    let valueToCheckCopy = valueToCheck

    // we will extract all the digits from the number to be checked
    while (valueToCheckCopy > 0) {
        digits.push(valueToCheckCopy % 10)
        valueToCheckCopy = parseInt(valueToCheckCopy / 10)
    }
    // then we find the number of digits in the number
    numberOfDigits = digits.length

    // we compute the sum of the digits to the power number of digits
    digits.forEach(digit => {
        sum = sum + Math.pow(digit, numberOfDigits)
    })

    return (sum === valueToCheck)
}