function gcd(a, b = null) {
  if (b != null) {
    if (a % b == 0) return b;
  } else {
    for (var i = 1; i < a.length; i++) a[0] = gcd(a[0], a[i]);
    return a[0];
  }

  return gcd(b, a % b);
}

console.log(gcd(9, 18));

console.log(gcd([6, 12, 18]));
