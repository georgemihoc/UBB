(defun right(l step)
  (cond
    (
      (and (not(numberp (car l))) (eq step 0))
      l
    )
    (
      (numberp (car l))
      (right (cdr l) (+ step (car l)))
    )
    (
      t
      (right (cdr l) (- step 1))
    )
 )
)

(defun nodelvl(l node)
  (cond
    (
      (eq (car l) node)
      0
    )
    (
      (eq (car (cdr l)) 0)
      0
    )
    (
      (eq (car (cdr l)) 1)
      (+ 1 (nodelvl (cdr (cdr l)) node))
    )
    (
      (eq (car (cdr l)) 2)
      (+ 1 (max (nodelvl (cdr (cdr l)) node) (nodelvl (right (cdr (cdr l)) 1) node)))
    )
  )
)

(print (nodelvl '(A 2 B 0 C 2 D 0 E 0) 'e))
