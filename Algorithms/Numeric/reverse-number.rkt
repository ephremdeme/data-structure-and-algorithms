#lang racket
 
;Build a function that, given a number, reverses it without using strings.
;
;input: 12345
;
;output: 54321

;; number -> number
;; reverses the given number without using strings

;; intution
;; (= 321 (+ (* 3  (expt 10 2)) (* 2 (expt 10 1)) 1 ))
;; (= 321 (+ (* (modulo 123 10) (expt 10 2)) (* (modulo 12 10) (expt 10 1)) 1 ))

;; code
(define (reverse-number num)
  (local [(define (reverse-n n acc)                               ; using an decerasing accumulator
            (cond [(= (order-of-magnitude n) 0) n]                ; basecase, used to stop recursion
                  [else
                   (+ 
                    (* (modulo n 10) (expt 10 acc))               ; get the right-most digit of n, multiply it with 10^x
                    (reverse-n (quotient n 10) (sub1 acc)))]))]   ; structural recursion with reduced digits, and decreased accumulator
    (reverse-n num (order-of-magnitude num))))                    ; using inner funtion "reverse-n" to return the reversed number 


; test examples
;(= (reverse-number 9) 9) ; basecase
;(= (reverse-number 12345) 54321)
;(= (reverse-number 1234500) 0054321)


;; I got help from this article
;; https://medium.com/@ManBearPigCode/how-to-reverse-a-number-mathematically-97c556626ec6
