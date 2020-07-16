(defun nrEls(l)
  (cond
    (
      (null l)
      0
    )
    (
      t
      (+ 1 (nrEls (cdr l)))
    )
  )
)

(defun convert(l)
  (cond
    (
      (null l)
      nil
    )
    (
      (not (listp (car l)))
      (append (list (car l) (nrEls (cdr l))) (convert (cdr l)))
    )
    (
      t
      (append (convert (car l)) (convert (cdr l)))
    )
  )
)

(print (convert '(A (B) (C (D) (E)))))