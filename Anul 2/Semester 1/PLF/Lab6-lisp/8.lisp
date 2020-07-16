;validate if given parameter is a binary tree or not
(defun is-tree(tree)
    (cond 
         ((null tree) NIL)
         ((< (list-length tree) 2) NIL)
         (t)
    )
)
(defun inordine(tree)
    (cond 
        ( (AND (is-tree (cadr tree))  (is-tree (caddr tree))) (append 
                 												(inordine (cadr tree))
                 												(list (car tree))
                 												(inordine (caddr tree))
 															)
        )
      	((is-tree (cadr tree)) (append 
									(inordine (cadr tree))
									(list (car tree))
									(caddr tree)
								)
      	)
      	((is-tree (caddr tree))(append 
									(car (cadr tree))
									(list (car tree))
									(inordine (caddr tree))
 								)
      	)
      	(t (append
      		(cadr tree ) 
      		(list (car tree)) 
      		(caddr tree))
      	)
    )
)



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

(print (inorder2 '(1 (2 (4) (5)) (3))))
;(inordine'(1 (2 (4) (5)) (3))). => (4 2 5 1 3)
;(inordine '(1 (2 () (8) ) (3 () ( 5 (6) (7) ) ))). => (2 8 1 3 6 5 7)
