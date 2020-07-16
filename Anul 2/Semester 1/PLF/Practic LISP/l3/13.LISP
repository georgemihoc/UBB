(defun depth1(x)
  (cond
    (
      (atom x)
      0
    )
    (
      t
      (+ 1 (apply #'max(mapcar 'depth1 x )))
    )
  )
)

(print (depth1 '(a (b (c)) (d) (e (f)))))