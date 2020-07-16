(defun replacee(x e o)
   (cond
     (
       (and (atom x) (eq x e))
       o
     )
     (
       (and (atom x) (not (eq x e)))
       x
     )
     (
       t
       (mapcar #'(lambda (x) (replacee x e o)) x)
     )
   )
)

(print (replacee '(a (b (c)) (d) (e (f))) 'e 'h))