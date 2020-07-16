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
(defun postorder1(l)
  (cond
    (
      (eq (car (cdr l)) 0)
      (list (car l))
    )
    (
      (eq (car (cdr l)) 1)
      (append (postorder1 (cdr (cdr l))) (list (car l)))
    )
    (
      (eq (car (cdr l)) 2)
      (append (postorder1 (cdr (cdr l))) (append (postorder1 (right (cdr (cdr l)) 1)) (list (car l))))
    )
  )
)

(print (postorder1 '(A 2 B 0 C 2 D 0 E 0)))
    