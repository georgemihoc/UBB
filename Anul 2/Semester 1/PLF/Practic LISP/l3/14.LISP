(defun counta(x)
  (cond
    (
      (atom x)
      1
    )
    (
      t
      (apply #'+(mapcar ' counta x))
    )
  )
)

(print (counta '(1 2 (4 a ( 5 b) 4))))