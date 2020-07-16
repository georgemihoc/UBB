(defun removeoc(x e)
  (cond
    (
      (and (atom x) (eq x e))
      nil
    )
    (
      (and (atom x) (not (eq x e)))
      (list x)
    )
    (
     t
      (mapcan #'(lambda (x) (removeoc x e)) x)
    )
  )
)

(print (removeoc '(1 2 3 ( 4 3 (2 3 5) 5) (3 4)) '3))