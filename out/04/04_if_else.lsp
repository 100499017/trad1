(setq num 10)


(defun main ()
(if (> num 20)
(print "El numero es mayor que 20")
(progn (print "El numero es menor o igual a 20")
(princ num))
)

)
 (main)
