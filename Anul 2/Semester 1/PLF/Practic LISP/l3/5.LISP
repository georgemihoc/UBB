(defun alternate(x)
  (cond
    (
      (and (numberp x) (eq (mod x 2) 0))
      x
    )
    (
      (and (numberp x) (eq (mod x 2) 1))
      (* -1 x)
    )
    (
      (atom x)
      0
    )
    (
      t
      (apply #'+(mapcar ' alternate x))
    )
  )
)

(print (alternate '(1 2 (a ( b 3) 4) 5)))
      