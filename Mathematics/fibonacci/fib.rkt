#lang racket

;; The Fibonacci Sequence is the series of numbers:
;; 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

;; integer -> list of integers
;; building intution for fibn - inner helper function
;; fn = fn-1 + fn-2 where fn < 2 = n
;; f0 = 0, f1 = 1  ; basecases
;; f2 = f1 + f0 = 1 + 0 = 1
;; f3 = f2 + f1 = 1 + 1
;; f8 = f7 + f6 = 13 + 8 = 21

;; code
;(define (fib n) (list 0)) ; stub

(define (fib n)
  (local [(define (fibn n)                             ;; inner helper function to calculate (fib n)
            (cond [(= n 0) 0]
                  [(= n 1) 1]
                  [else
                   (+                                  ;; add fn-1 to fn-2
                    (fibn (- n 1))
                    (fibn (- n 2)))]))]                ;; self reference for structital recursion
    (build-list (add1 n) fibn)))
   
;; test examples for fibn
;(equal? (fibn 0) 0)                                   ;; base case for structural recursion
;(equal? (fibn 1)  1)                                  ;; base case for structural recursion
;(equal? (fibn 8) (+ (fibn 7) (fibn 6)))               ;; intution
;(equal? (fibn 8) 21)
;

;; test examples for fib
;(equal? (fib 0) (cons 0 empty))                  ;; base case for structural recursion
;(equal? (fib 1) (list 0 1))                ;; base case for structural recursion
;(equal? (fib 8) (list 0 1 1 2 3 5 8 13 21))