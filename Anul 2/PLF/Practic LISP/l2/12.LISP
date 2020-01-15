(defun preorder2(l)
  (cond
    (
      (null l)
      nil
    )
    (
      t
      (append (list (car l)) (append (preorder2 (car (cdr l))) (preorder2 (car (cdr (cdr l))))))
    )
 )
)

(print (preorder2 '(A (B (f)(g)) (C (D) (E)))))