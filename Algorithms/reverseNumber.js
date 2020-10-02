function reversedNumber(num) {
    return (parseFloat(num.toString().split('').reverse().join('')) * Math.sign(num))
}

console.log(reversedNumber(123456))
