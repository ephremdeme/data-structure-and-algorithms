#lang racket

;Armstrong number is a number that is equal to the sum of cubes of its digits. For example 0, 1, 153, 370, 371 and 407 are the Armstrong numbers.
;
;Let's try to understand why 153 is an Armstrong number.
;
;153 = (1*1*1)+(5*5*5)+(3*3*3)  
;where:  
;(1*1*1)=1  
;(5*5*5)=125  
;(3*3*3)=27  
;So:  
;1+125+27=153

;; I got help from this article
;; https://www.javatpoint.com/armstrong-number-in-c#:~:text=Armstrong%20number%20is%20a%20number,153%20is%20an%20Armstrong%20number.&text=Let's%20try%20to%20understand%20why%20371%20is%20an%20Armstrong%20number.

;; number -> boolean
;; code
;(define (armstrong-Number n) false)   ; stub

(define (armstrong-Number n)
  (local [(define (armstrong-sum n)                            ;; helper function to find the sum, of cubes, of digits, of n
            (cond [(zero? n) 0]                                ;; basecase to stop structural recirsion                               
                  [else
                   (+                                          ;; add them all
                    (expt (modulo n 10) 3)                     ;; get    the last digit of n by modulo 10 of n
                    (armstrong-sum (quotient n 10))) ]))]      ;; remove the last digit of n by quotient 10 of n - integer division by 10
    (= (armstrong-sum n) n)))                                  ;; compare the sum of cube of digits of n, and n




;; test examples
;(equal? (armstrong-Number 0) true)
;(equal? (armstrong-Number 1) true)
;(equal? (armstrong-Number 9) false)
;(equal? (armstrong-Number 153) true)
;(equal? (armstrong-Number 100) false)
;(= 153 (+ (expt 1 3) (expt 5 3) (expt 3 3)))
;
