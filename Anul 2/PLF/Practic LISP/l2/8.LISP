(defun inorder2(l)
  (cond
    (
      (null l)
      nil
    )
    (
      t
      (append (inorder2 (car (cdr l))) (append (list (car l)) (inorder2 (car (cdr (cdr l))))))
    )
  )
)

(print (inorder2 '(A (B) (C (D) (E)))))