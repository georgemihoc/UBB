(defun isThere(l x)
  (cond
   (
     (null l)
     nil
   )
   (
     (eq (car l) x)
     t
   )
   (
     (eq (car (cdr l)) 0)
     nil
   )
   (
     (eq (car (cdr l)) 1)
     (isThere (cdr (cdr l)) x)
   )
   (
     t
     (isThere (right (cdr (cdr l)) 1) x)
   )
 )
)
(defun right(l step)
  (cond
    (
      (and (not (numberp (car l))) (=  step 0))
      l
    )
    (
      (not (numberp (car l)))
      (right (cdr l) (- step 1))
    )
    (
      t
      (right (cdr l) (+ step (car l)))
    )
  )
)
(defun path(l x)
   (cond
    (
      (null l)
      nil
     )
     (
       (eq (car l) x)
        (list x)
      )
     (
       (eq (car (cdr l)) 0)
       nil
     )
     (
       (and (isThere l x) (eq (car (cdr l)) 1))
       (append (path (cdr (cdr l)) x) (list (car l)))
     )
     (
       (and (isThere (cdr (cdr l)) x) (eq (car (cdr l)) 2))
       (append (path (cdr (cdr l)) x) (list (car l)))
     )
     (
       (and (isThere (right (cdr (cdr l)) 1) x) (eq (car (cdr l)) 2))
       (append (path (right (cdr (cdr l)) 1) x) (list (car l)))
     )
   )
)


(print (path '(A 2 B 0 C 2 D 0 E 0) 'e))