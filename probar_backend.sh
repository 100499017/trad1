#!/bin/bash

# Solo procesamos la carpeta 00
carpetas=("00")

echo "--- Iniciando Traducción Backend y Ejecución Forth ---"

for dir in "${carpetas[@]}"; do
    echo ""
    echo "========================================"
    echo " PROCESANDO LISP EN: out/$dir/"
    echo "========================================"

    # Comprobar si hay archivos .lsp en la carpeta de salida
    if ls out/$dir/*.lsp 1> /dev/null 2>&1; then
        for archivo_lsp in out/$dir/*.lsp; do
            nombre_base=$(basename "$archivo_lsp" .lsp)
            archivo_fth="out/$dir/$nombre_base.fth"

            echo "[LISP] -> $archivo_lsp"
            
            # 1. Ejecutar el backend (Lisp a Forth)
            ./back2 < "$archivo_lsp" > "$archivo_fth"

            if [ $? -eq 0 ]; then
                echo "[POSTFIJO] Generado en: $archivo_fth"
                echo "[CÓDIGO FORTH]:"
                cat "$archivo_fth"
                echo ""
                echo "[EJECUCIÓN GFORTH]:"
                echo "----------------------------------------"
                
                # 2. Ejecutar con gforth y salir automáticamente al terminar
                gforth "$archivo_fth" -e bye
                
                echo -e "\n----------------------------------------"
            else
                echo "[ERROR] Falló la traducción backend de $archivo_lsp"
            fi
            echo ""
        done
    else
        echo "No se encontraron archivos .lsp en out/$dir/"
    fi
done

echo "--- Proceso de backend finalizado ---"