function fibonacciSeries(n) {
  if (n >= 1) console.log(1);

  var a = 1,
    b = 1;

  while (b <= n) {
    console.log(b);
    b = b + a;
    a = b - a;
  }

  
}

fibonacciSeries(9)
