(defun right2(l step)
  (cond
    (
      (eq step 0)
      l
    )
    (
      (not (numberp (car l)))
      (right2 (cdr l) (- step 1))
    )
    (
      t
      (right2 (cdr l) (+ step (car l)))
    )
  )
)
(defun nodeLevel(l k p)
  (cond
    (
      (and (eq k p) (eq (car (cdr l)) 0))
      (list (car l))
    )
    (
      (and (eq k p) (eq (car (cdr l)) 1))
      (list (car l))
    )
    (
      (and (eq k p) (eq (car (cdr l)) 2))
      (list (car l))
    )
    (
      (and (not (eq k p)) (eq (car (cdr l)) 0))
      nil
    )
    (
     (and (not (eq k p)) (eq (car (cdr l)) 1))
      (nodeLevel (cdr (cdr l)) k (+ p 1))
    )
    (
      t
      (append (nodeLevel (cdr (cdr l)) k (+ p 1)) (append (nodeLevel (right2 (cdr (cdr l)) 1) k (+ p 1))))
    )
  )
)

(print (nodeLevel '(A 2 B 0 C 2 D 0 E 0) 2 0))

      