(defun depth(x)
  (cond
    (
      (atom x)
      0
    )
    (
      t
      (+ 1 (apply #'max(mapcar 'depth x)))
    )
  )
)

(print (depth '(a (b (c)) (d) (e (f)))))