class Hashing {
  constructor(MAX = 10) {
    this.MAX = MAX;
    this.keys = [];
    this.values = [];
    this.count = 0;
  }

  hash(key) {
    if (isNaN(key)) throw "Must be a Number";
    let hashedIndex = key % this.MAX;
    return hashedIndex;
  }

  /**
   * Put using linear probing technique.
   */
  put(key, value) {
    let hashedIndex = this.hash(key);
    if (this.count > this.MAX) return "Array Full";

    if (!this.keys[hashedIndex]) {
      this.keys[hashedIndex] = key;
      this.values[hashedIndex] = value;
    } else {
      hashedIndex = this.linearProbing(key);
      this.keys[hashedIndex] = key;
      this.values[hashedIndex] = value;
    }
    this.count++;
  }

  /**
   * Put using quadratic probing technique.
   */
  putQuadratic(key, value) {
    let hashedIndex = this.hash(key);
    if (this.count > this.MAX) return "Array Full";

    if (!this.keys[hashedIndex]) {
      this.keys[hashedIndex] = key;
      this.values[hashedIndex] = value;
    } else {
      hashedIndex = this.quadraticProbing(key);
      this.keys[hashedIndex] = key;
      this.values[hashedIndex] = value;
    }
    this.count++;
  }

  /**
   * Get value by key using linear probing
   *
   * @param {int} key
   */
  get(key) {
    let hashedIndex = this.hash(key);
    while (this.keys[hashedIndex] != key && this.keys[hashedIndex]) {
      hashedIndex++;
      hashedIndex = hashedIndex % this.MAX;
    }
    return this.values[hashedIndex];
  }

  /**
   * Get value by key using Quadratic probing
   *
   * @param {int} key
   */
  getQuadratic(key) {
    let hashedIndex = this.hash(key);
    let squareIndex = 1;
    if (!this.keys[hashedIndex]) return -1;
    while (this.keys[hashedIndex] != key && this.keys[hashedIndex]) {
      hashedIndex = Math.pow(squareIndex, 2);
      hashedIndex = hashedIndex % this.MAX;
      squareIndex++;
    }
    if (this.keys[hashedIndex] == key) return this.values[hashedIndex];
  }

  linearProbing(key) {
    let hashedIndex = this.hash(key);
    let i = hashedIndex + 1;
    for (i; i % this.MAX != hashedIndex; i++) {
      if (!this.keys[i]) {
        return i % this.MAX;
      }
    }
    return -1;
  }

  quadraticProbing(key) {
    let hashedIndex = this.hash(key);
    let i = hashedIndex + 1;
    for (i; i % this.MAX != hashedIndex; i++) {
      hashedIndex = (hashedIndex + i * i) % this.MAX;
      if (!this.keys[hashedIndex]) {
        return hashedIndex;
      }
    }
    return -1;
  }

  /**
   * Double Hashing probing technique
   * @param {*} hash1 
   */

  doubleHash(hash1) {
    let R = this.MAX - 1;

    return R - (hash1 % R);
  }

  size() {
    return this.count;
  }
}

let hash = new Hashing(11);
hash.put(12, "12");
hash.put(2, "2");
hash.put(1, "1");
hash.put(24, "24");
hash.put(31, "31");
hash.put(23, "23");
hash.put(34, "34");
console.log(hash.get(12));
console.log(hash.get(2));
console.log(hash.get(1));
console.log(hash.get(24));
console.log(hash.get(31));
console.log(hash.get(23));
console.log(hash.get(35));
console.log(hash.size());
