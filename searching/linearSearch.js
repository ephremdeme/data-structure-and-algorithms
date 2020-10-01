const linearSearch = (arr = [], key) => {
  let index = -1;
  arr.forEach((ele, i) => {
    if (ele === key) index = i;
  });
  return index;
};

console.log(linearSearch([1, 2, 3, 4, 5, 6, 7, 8, 9], 10));
console.log(linearSearch([1, 2, 3, 4, 5, 6, 7, 8, 9], 5));
