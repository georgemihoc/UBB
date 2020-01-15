(defun klevel(x k level)
  (cond
    (
      (and (atom x ) (eq level k))
      1
    )
    (
      (and (atom x) (not (eq level k)))
      0
    )
    (
      t
      (apply #'+(mapcar #'(lambda (x) (klevel x k (+ level 1))) x))
    )
)

)


(print (klevel '(a (b (c)) (d) (e (f))) 1 -1))