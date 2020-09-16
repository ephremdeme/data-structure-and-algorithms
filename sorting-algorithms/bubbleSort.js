function swap(array, index1, index2) {
  var temp = array[index1];
  array[index1] = array[index2];
  array[index2] = temp;
}

function bubbleSort(array){
    for(let i = 0, arrayLength = array.length; i<arrayLength; i++){
        for(let j = i; j<=arrayLength; j++){
            if(array[i]>array[j]){
                swap(array,i, j);
            }
        }
    }
    return array;
}

console.log(bubbleSort([2,5, 6, 1, 3, 7, 9, 4]));
