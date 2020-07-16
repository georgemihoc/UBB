;sa se inlocuiasca fiecare sublista a unei liste cu ultimul ei element
(defun sublista (l)
   (cond
		((null l) nil)
		((atom l) l)
		((atom (car l)) (cons (car l) (sublista (cdr l))))
		(t (cond
				((eq (cdr(car l)) nil) (cons (sublista (caar l)) (sublista (cdr l)))) 
				(t (append (sublista (cdr (car l))) (sublista (cdr l))))
			)
		)
   ) 
)


(defun rev (l)
  (cond
    ((null l) '())
    (t (append (rev (cdr l)) (list (car l)))))) 

(defun ultimul_elem (l)
	(cond
		((atom l) l)
        (t(ultimul_elem (car (rev l))))
    )
)

(defun functie (l)
	(cond
		((null l) nil)
		((listp (car l)) (cons (ultimul_elem (car l)) (functie (cdr l))))
		(t (cons (car l) (functie (cdr l))))
	)
)

(print (functie '(a(b((c)))(d(e(f))))))
;(print (functie '(a (b c) (d ((e) f)))))

