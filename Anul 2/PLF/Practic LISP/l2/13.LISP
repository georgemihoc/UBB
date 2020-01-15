(defun isThere(l node)
  (cond
    (
     (null l)
     nil
   )
    (
      (eq node (car l))
      t
    )
    (
      t
      (or (isThere (car (cdr l)) node) (isThere (car (cdr (cdr l))) node))
    )
  )
)
(defun path(l node)
  (cond
   (
     (eq (car l) node)
     (list node)
   )
   (
     (isThere (car (cdr l)) node)
     (append (list (car l)) (path (car (cdr l)) node))
   )
   (
     (isThere (car (cdr (cdr l))) node)
     (append (list (car l)) (path (car (cdr (cdr l))) node))
   )
)
)

(print (path '(A (B) (C (D) (E))) 'e))
