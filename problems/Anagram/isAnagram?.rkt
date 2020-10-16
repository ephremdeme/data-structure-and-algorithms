#lang racket
;Check weather the given two strings are anagrams of each other, i.e weather they contain the same letter.
;
;Example :
;Input: abc & cab //abc is anagrams with cab, bac, cab..
;Output: True

;; string -> boolean
;; retruns true of given strings have the same characters

;; code
;(define (isAnagram? s1 s2) true)  ; stub

(define (isAnagram? s1 s2)
  (local [(define (isAnagram? s1 s2)                                                                    ; helper function
            (cond
              [(and (empty? s1) (empty? s2)) true]                                                      ; basecase for recursion
              [else
               (and                                                                                     ; all the characters must match
                (equal? (first s1) (first s2))
                (isAnagram? (rest s1) (rest s2)))]))]
    (isAnagram? (sort (string->list s1) (lambda (a b) (> (char->integer a) (char->integer b))))         ; turning the string into a 
                (sort (string->list s2) (lambda (a b) (> (char->integer a) (char->integer b)))))))      ; sorted list





;; testing examples
;(equal? (isAnagram? "" "") true)    ; basecase
;(equal? (isAnagram? "abc" "cab") true)
;(equal? (isAnagram? "cat" "dog") false)