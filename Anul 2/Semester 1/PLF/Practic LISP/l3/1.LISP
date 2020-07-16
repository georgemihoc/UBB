(defun isMember(x e)
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
      (apply #'+(mapcar #'(lambda (x) (isMember x e)) x))
    )
  )
)

(defun isMember1(x e)
  (cond
    (
      (eq (isMember x e) 0)
      nil
    )
    (
      t
      t
    )
)
)
(print (isMember1 '(1 2 3 a( 4 b 3 (a b c) a )) 'f))