(setq i 0)


(defun main ()
(print "Contando con while:")
(loop while (< i 3) do
(princ i)
(setf i (+ i 1))
)
(print "Fin del bucle")

)
 (main)
