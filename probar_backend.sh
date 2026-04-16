#!/bin/bash

# Crear carpetas para los resultados del backend (extensión .fth)
mkdir -p out/00 out/01 out/02 out/03

carpetas=("00" "01" "02" "03")

echo "--- Iniciando Traducción Backend (Lisp -> Postfijo) ---"

for dir in "${carpetas[@]}"; do
    echo ""
    echo "=================================="
    echo " PROCESANDO LISO EN: out/$dir/"
    echo "=================================="

    # Comprobar si hay archivos .lsp en la carpeta de salida
    if ls out/$dir/*.lsp 1> /dev/null 2>&1; then
        for archivo_lsp in out/$dir/*.lsp; do
            nombre_base=$(basename "$archivo_lsp" .lsp)
            archivo_fth="out/$dir/$nombre_base.fth"

            echo "[LISP] -> $archivo_lsp"

            # Ejecutar el backend
            # Pasamos el lisp por la entrada estándar y guardamos el postfijo en .fth
            ./back1 < "$archivo_lsp" > "$archivo_fth"

            if [ $? -eq 0 ]; then
                echo "[POSTFIJO] Generado en: $archivo_fth"
                echo "[RESULTADO]:"
                echo "----------------------------------------"
                cat "$archivo_fth"
                echo -e "\n----------------------------------------"
            else
                echo "[ERROR] Falló la traducción backend de $archivo_lsp"
            fi
        done
    else
        echo "No se encontraron archivos .lsp en out/$dir/"
    fi
done

echo "--- Proceso de backend finalizado ---"