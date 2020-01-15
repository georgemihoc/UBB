(defun maximum(x)
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
      (apply #'max(mapcar ' maximum x))
    )
  )
)

(print (maximum '(a 1 3 b (c 5 ( 4 3 a) 2) 3)))