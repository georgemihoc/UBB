(defun right4(l step)
  (cond
    (
     (and (not(numberp (car l))) (eq step 0))
     l
   )
    (
      (numberp (car l))
      (right4 (cdr l) (+ step (car l)))
    )
    (
      t
      (right4 (cdr l) (- step 1))
    )
 )
)
(defun inorder1(l)
  (cond
    (
      (eq (car (cdr l)) 0)
      (list (car l))
    )
    (
      (eq (car (cdr l)) 1)
      (append (inorder1 (cdr (cdr l))) (list (car l)))
    )
    (
      (eq (car (cdr l)) 2)
      (append (inorder1 (cdr (cdr l))) (append (list (car l)) (inorder1 (right4 (cdr (cdr l)) 1))))
    )
  )
)

(print (inorder1 '(A 2 B 0 C 2 D 0 E 0)))
      