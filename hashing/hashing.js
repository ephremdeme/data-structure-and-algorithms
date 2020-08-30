class Hashing{
    constructor( MAX = 10 ){
        this.MAX = MAX;
        this.keys = []
        this.values = []
        this.size = 0;
    }

    hash(key){
        if(isNaN(key)) throw "Must be a Number";
        let hashedIndex = key % this.MAX;
        return hashedIndex;
    }

    put(key, value){
        let hashedIndex = this.hash(key);
        if(this.size>this.MAX) return "Array Full";

        if(!this.keys[hashedIndex]){
            this.keys[hashedIndex] = key;
            this.values[hashedIndex] = value;
        }else{
            hashedIndex = this.linearProbing(key);
            this.keys[hashedIndex] = key;
            this.values[hashedIndex] = value;
        }
        this.size++
    }

    get(key){
        let hashedIndex = this.hash(key);
        let i = 0;
        while(!this.keys[hashedIndex] == key && i<this.MAX){
             hashedIndex = this.linearProbing(key)
             i++;
        }
        return this.values[hashedIndex];
    }

    linearProbing(key){
        let hashedIndex = this.hash(key);
        let i=hashedIndex+1;
        for(i; i%this.MAX!=hashedIndex; i++){
            if(!this.keys[i]){
                return i;
            }
        }
        return -1;
    }
}

let  hash = new  Hashing(11);
hash.put(12, "12");
hash.put(2, "2");
hash.put(1, "1");
hash.put(24, "24");
hash.put(31, "31");
console.log(hash.get(12))
console.log(hash.get(2))
console.log(hash.get(1))
console.log(hash.get(24))
console.log(hash.get(91))

