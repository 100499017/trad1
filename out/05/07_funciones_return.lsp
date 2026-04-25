(setq resultado 0)
(defun sumar (a b)
(return-from sumar (+ a b))

)
(defun main ()
(print "Llamando a funcion externa:")
(setf resultado (sumar 5 5))
(princ resultado)

)
 (main)
