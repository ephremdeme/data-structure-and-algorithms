function reversedNumber(num) {
    return (parseFloat(num.toString().split('').reverse().join('')) * Math.sign(num))
}


console.log(reversedNumber(123456)) // 654321
console.log(reversedNumber(-54321)) // -12345
