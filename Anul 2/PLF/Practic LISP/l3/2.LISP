(defun suma(x)
  (cond
   (
    (numberp x)
    x
    )
  (
    (atom x)
    0
  )
  (
    t
    (apply #'+(mapcar 'suma x))
  )
)
)

(print (suma '(1 a b (2 3 (c d (3 4) 5)))))