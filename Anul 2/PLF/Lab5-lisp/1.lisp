;;13.
;;a) Sa se intercaleze un element pe pozitia a n-a a unei liste liniare.
;;b) Sa se construiasca o functie care intoarce suma atomilor numerici dintr-o
;;       lista, de la orice nivel.
;;c) Sa se scrie o functie care intoarce multimea tuturor sublistelor unei
;;liste date. Ex: Ptr. lista ((1 2 3) ((4 5) 6)) => ((1 2 3) (4 5) ((4 5) 6))
;;d) Sa se scrie o functie care testeaza egalitatea a doua multimi, fara sa se
;;      faca apel la diferenta a doua multimi.

;;pct a)
(defun insert-at (list index item)
  (cond
    ;;((< index 1) (error "Index too small" index))
    ((= index 1) (cons item list))
    ;((endp list) (error "Index too big"))
    ((null list) '()) 
    (t (cons (car list) (insert-at (cdr list) (1- index) item )))))

;;		(insert-at '(1 2 3 4) 2 5)

;;pct b)
(defun sum (list)
  (cond ((null list)         0)                     
        ((numberp (car list)) (+ (car list)      
                                (sum (cdr list)))) 
        ((listp (car list))                   (+ (sum (car list))
                                (sum (cdr list))))
        (t (sum (cdr list)))
        )
  )
;;		(sum '(1 2 3 (1 (3 4) 2) 4))

;;pct c)
(defun functie (elements)
    (cond
        ((null elements) '()) 
        ((listp (car elements))
        	(append (functie(car elements)) (append (list (car elements)) (functie(cdr elements)) ))
        )
        (t (functie(cdr elements)))
    )
)
;;		(functie '((1 2 3)((4 5) 6)))

;;pct d)
(defun removee (l e)
    (cond
        ((null l) nil)
        ((equal (car l) e) (removee (cdr l) e))
        (T (cons (car l) (removee (cdr l) e)))
    )
)

(defun same-elements (l k)
    (cond
        ((and (null l) (null k)) T)
        ((or (null l) (null k)) nil)
        (T (same-elements (cdr l) (removee k (car l))))
    )
)
;;		(same-elements '(1 2 4 3) '(4 1 2 3))

;(defun same-elements (l1 l2)
 ; (and (subsetp l1 l2) (subsetp l2 l1)))
;;		(same-elements '(1 2 4 3) '(4 1 2 3))