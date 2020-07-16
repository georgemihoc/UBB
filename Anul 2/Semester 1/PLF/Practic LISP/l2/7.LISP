(defun right5(l step)
  (cond
    (
     (and (not (numberp (car l))) (eq step 0))
     l
   )
    (
      (numberp (car l))
      (right5 (cdr l) (+ step (car l)))
    )
    (
      t
      (right5 (cdr l) (- step 1))
    )
  )
)

(defun isThere(l node)
  (cond
    (
      (eq (car l) node)
      t
    )
    (
      (and (not (eq (car l) node )) (eq (car (cdr l)) 0))
      nil
    )
    (
      (and (not (eq (car l) node)) (eq (car (cdr l)) 1))
      (isThere (cdr (cdr l)) node)
    )
    (
      (and (not (eq (car l) node)) (eq (car (cdr l)) 2))
      (or (isThere (cdr (cdr l)) node) (isThere (right5 (cdr (cdr l)) 5) node))
    )
)
)
(defun lvl(l node)
  (cond
   (
     (eq (car l) node)
     0
   )
   (
     (eq (car (cdr l)) 0)
     0
   )
   (
     (and (isThere (cdr (cdr l)) node) (eq (car (cdr l)) 1))
     (+ 1 (lvl (cdr (cdr l)) node))
   )
   (
     (and (isThere (right5 (cdr (cdr l)) 1) node) (eq (car (cdr l)) 2))
     (+ 1 (lvl (right5 (cdr (cdr l)) 1) node))
   )
   (
     (and (isThere (cdr (cdr l)) node) (eq (car (cdr l)) 2))
     (+ 1 (lvl (cdr (cdr l)) node))
   )
 )
)

(print (lvl '(A 2 B 0 C 2 D 0 E 0) 'e))