(defun level(l node lvl)
  (cond
    (
      (null l)
      nil
    )
    (
      (and (atom (car l))(eq node (car l)))
      lvl
    )
    (
      t
      (or (level (car (cdr l)) node (+ lvl 1)) (level (car (cdr (cdr l))) node (+ 1 lvl)))
    )
)
)

(print (level '(A (B) (C (D) (E))) 'e 0))