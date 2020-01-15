(defun liniar(x)
  (cond
    (
      (atom x)
      (list x)
    )
    (
      t
      (mapcan ' liniar x)
    )
  )
)

(print (liniar '(((A B) C) (D E))))