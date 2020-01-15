(defun replacee2(x e o)
  (cond
    (
      (and (atom x) (eq x e))
      o
    )
    (
      (and (atom x) (not (eq x e)))
      x
    )
    (
      t
      (mapcar #'(lambda (x) (replacee2 x e o)) x)
    )
  )
)

(print (replacee2 '(a (b (c)) (d) (e (f))) 'e 'o))