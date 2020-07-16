(defun membership(x e)
  (cond
    (
      (and (atom x) (eq x e))
      1
    )
    (
      (and (atom x) (not (eq x e)))
      0
    )
    (
      t
      (apply #'+(mapcar #'(lambda (x) (membership x e)) x))
     )
  )
)

(defun members(x e)
  (cond
    (
      (eq (membership x e) 0)
      nil
    )
    (
      t
      t
    )
  )
)

(print (members '(a (b (c)) (d) (E (f))) 'n))