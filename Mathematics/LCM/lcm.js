function gcd(a, b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
function lcm(a, b) {
  return Math.min(a, b) * gcd(a, b);
}

console.log(lcm(6, 9))