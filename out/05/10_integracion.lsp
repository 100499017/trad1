(setq global_val 0)

(defun procesar (x)
(case x
(1
(setf global_val 100)
)
(otherwise
(setf global_val (- 1))
))
(return-from procesar global_val)

)

(defun main ()
(setq main_i 0)
(setq vector (make-array 3))
(setf main_i 0)
(loop while (< main_i 3) do
(setf (aref vector main_i) (procesar 1))
(progn (princ (aref vector main_i))
(princ " "))

(setf main_i (+ main_i 1)))

)
 (main)
