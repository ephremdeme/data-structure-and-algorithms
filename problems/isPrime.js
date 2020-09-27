function isPrime(num =0){
    for(let i=2; i<=Math.sqrt(num); i++){
        if(num%i==0) return false
    }
    return true
}

console.log(isPrime(1109));