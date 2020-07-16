(defun postorder2(l)
  (cond
    (
     (null l)
     nil
    )
    (
      t
      (append (postorder2 (car (cdr l))) (append (postorder2 (car (cdr (cdr l)))) (list (car l))))
    )
  )
)

(print (postorder2 '(A (B) (C (D) (E)))))