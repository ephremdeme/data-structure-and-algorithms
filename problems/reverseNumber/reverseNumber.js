function reverseNumber(num = 0) {
  var ans = 0;
  while (num > 0) {
    var remainder = num % 10;
    ans = ans * 10 + remainder;
    num = Math.floor(num / 10);
  }

  return ans;
}

// console.log(reverseNumber(123456));

var num = prompt("Enter a number to reverse: ");
console.log(reverseNumber(num));

