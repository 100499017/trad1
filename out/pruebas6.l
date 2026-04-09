(setq contador 0)
(defun main ()
	(print "Iniciando bucle")
	(loop while (< contador 5) do
	(princ contador)
	(setq contador (+ contador 1)))
	(print "Fin del programa")
)
(main)
