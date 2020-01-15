(defun product(x)
  (cond
    (
      (numberp x)
      x
    )
    (
      (atom x)
      1
    )
    (
      t
      (apply #'*(mapcar ' product x))
    )
  )
)

(print (product '(1 2 a (b c (d 3 ) 2) 2)))