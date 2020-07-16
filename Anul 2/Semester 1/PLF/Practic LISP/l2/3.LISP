(defun right(l step)
  (cond
    (
      (and (not (numberp (car l))) (eq step 0))
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

(defun numberl(l)
  (cond
    (
      (eq (car (cdr l)) 0)
      1
    )
    (
      (eq (car (cdr l)) 1)
      (+ 1 (numberl (cdr (cdr l))))
    )
    (
      (eq (car (cdr l)) 2)
      (+ 1 (max (numberl (cdr (cdr l))) (numberl (right (cdr (cdr l)) 1))))
    )
  )
)

(print (numberl '(A 2 B 0 C 2 D 0 E 0)))