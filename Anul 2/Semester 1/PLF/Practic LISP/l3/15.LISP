(defun reversel(x)
  (cond
    (
      (atom x)
      x
    )
    (
      t
      (reverse(mapcar ' reversel x))
    )
  )
)

(print (reversel '(1 2 (3 4 (5 6) 2) 3)))
    