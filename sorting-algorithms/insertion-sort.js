/*

Insertion sort says you divide your array in two parts(left and right),
the left part is the sorted part and the right part is the unsorted part.
Now assume that the first element(index 0) is already sorted, so for every
element starting from index 1 keep checking where it belongs in the sorted
array and insert it there shifting the necessary elements to the right.

*/

function insertionSort(arr) {
  // start from index 1
  for (let i = 1; i < arr.length; i++) {
    let temp = arr[i];

    let j = i - 1;
    // compare the current element to its predicessor
    while (j >= 0 && arr[j] > temp) {
      arr[j + 1] = arr[j];
      // keep iterating till the predicessor becomes smaller than the current item
      j--;
    }

    // insert it at the right place
    arr[j + 1] = temp;
  }
  return arr;
}

var arr = [4, 1, 3, 2, 1];

console.log(insertionSort(arr))

// This has the time complexity of O(n^2)
