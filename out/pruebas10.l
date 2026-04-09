(setq global 10)
(defun main ()
(setq main_opcion 2)
(setq main_resultado 0)
(case main_opcion
(1
(setf main_resultado 100))
(2
(setf main_resultado 200)
(print "Opcion 2 elegida"))
(otherwise
(setf main_resultado global)))
)
(main)
