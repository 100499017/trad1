(setq opcion 2)


(defun main ()
(print "Probando switch:")
(case opcion
(1
(print "Opcion 1 elegida")
)
(2
(print "Opcion 2 elegida")
)
(otherwise
(print "Opcion por defecto")
))

)
 (main)
