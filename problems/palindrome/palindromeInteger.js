function isPalindrome(num){
  if(num < 0) return false

  let reversed = 0, x = num

  while (x > 0) {
    const lastDigit = x % 10
    reversed = (reversed * 10) + lastDigit
    x = (x / 10) | 0
  }
  return num === reversed
}


//Test case
console.log(isPalindrome(121))
console.log(isPalindrome(221))
console.log(isPalindrome(5123215))
console.log(isPalindrome(12321))
console.log(isPalindrome(29378))