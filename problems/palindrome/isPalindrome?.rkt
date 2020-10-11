#lang racket
 
;Build a function that checks weather a given number is a palindrome or not without using a strings. Implement it using any language.
;
;For example:
;input: 12321
;output: true
;
; input: 12344321
; output: True

;; intution
;; n and reverse n will be same for a palindrome
;; will use reverse-number (see pr #341 for issue #35)

;; I got the Idea from link below
;; https://www.integers.co/questions-answers/is-12344321-a-palindrome-number.html



;; code
(define (isPalinDrome n)
  (local [
          (define (reverse-n n acc)                               ; using an decerasing accumulator
            (cond [(= (order-of-magnitude n) 0) n]                ; basecase, used to stop recursion
                  [else
                   (+ 
                    (* (modulo n 10) (expt 10 acc))               ; get the right-most digit of n, multiply it with 10^x
                    (reverse-n (quotient n 10) (sub1 acc)))]))

          (define (reverse-number num)
            (reverse-n num (order-of-magnitude num)))
          ]
    (= (reverse-number n) n)))

; test examples
;(equal? (isPalinDrome 9) true) 
;(equal? (isPalinDrome 12349321) false)
;(equal? (isPalinDrome 12321) true)
