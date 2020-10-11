#lang racket


;; returns factorial of the given number
;; Number -> Number
;; code
;(define (fact n) 1) ; stub

(define (fact n)
  (cond
    [(zero? n) 1]                       ;; basecase
    [else
     (*                                 ;;  
      n
      (fact (sub1 n)))]))               ;; structural recursion and reduction of n




;; test examples
;(equal? (fact 0) 1)  ;basecase
;(equal? (fact 1) 1)
;(equal? (fact 3) (* 3 (* 2 1)))