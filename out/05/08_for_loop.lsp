(setq j 0)


(defun main ()
(print "Bucle for ascendente:")
(setf j 0)
(loop while (< j 3) do
(princ j)

(setf j (+ j 1)))
(print "Bucle for descendente:")
(setf j 3)
(loop while (> j 0) do
(princ j)

(setf j (- j 1)))

)
 (main)
