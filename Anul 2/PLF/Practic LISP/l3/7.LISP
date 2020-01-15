(defun substitu(x e l1)
  (cond
    (
      (and (atom x) (eq x e))
      l1
    )
    (
      (and (atom x) (not (eq x e)))
      list x
    )
    (
      t
      (mapcar #'(lambda (x) (substitu x e l1)) x)
    )
  )
)


(print (substitu '(1 2 (3 a b (2 4) 5) 6) 2 '(e f)))