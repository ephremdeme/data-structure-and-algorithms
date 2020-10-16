let gcd = (num1, num2) => {
    //if num2 is 0 return num1;
    if(num2 === 0){
       return num1;
    }
    
    //call the same function recursively
    return gcd(num2, num1 % num2);

    // Note:
    // Time complexity: O(n) or O(log(a) + log(b)).
    // Space complexity: O(m + n).
 }

let lcm = (n1, n2) => {
    //Find the gcd first 
    let gcd = gcd(n1, n2);

    //then calculate the lcm
    return (n1 * n2) / gcd;

    //Note: 
    // Time complexity: O(log(a) + log(b)).
    // Space complexity: O(1).
}

console.log(gcd(60, 15));
console.log(lcm(15, 20));
