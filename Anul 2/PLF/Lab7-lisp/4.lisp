;Sa se construiasca o functie care intoarce suma atomilor 
;numerici dintr-o lista, de la orice nivel

(defun suma(n)
	(cond 
		((numberp n) n)
		((atom n) 0)
		(t (apply #'+ (mapcar #' suma n)))
		)
)
; (suma '(1 a (2 (b 5) 3) 3)).