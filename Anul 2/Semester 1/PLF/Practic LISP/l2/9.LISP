(defun right6(l step)
  (cond
    (
      (and (not (numberp (car l))) (eq step 0))
      l
    )
    (
      (numberp (car l))
      (right6 (cdr l) (+ step (car l)))
    )
    (
      t
      (right6 (cdr l) (- step 1))
    )
  )
)
(defun convert2(l)
  (cond
    (
      (eq (car (cdr l)) 0)
      (list (car l))
    )
    (
      (eq (car (cdr l)) 1)
      (cons (car l) (convert2 (cdr (cdr l))))
    )
    (
      (eq (car (cdr l)) 2)
      (cons (car  l) (append (list (convert2 (cdr (cdr l)))) (convert2 (right6 (cdr (cdr l)) 1))))
    )
  )
)

(print (convert2 '(A 2 B 0 C 2 D 0 E 0)))