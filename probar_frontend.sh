#!/bin/bash

# Crear la estructura de carpetas de salida si no existe
mkdir -p out/00 out/01 out/02 out/03

# Array con las subcarpetas a procesar
carpetas=("00" "01" "02" "03")

echo "--- Iniciando proceso de traducción y ejecución ---"

for dir in "${carpetas[@]}"; do
    echo ""
    echo "===================================="
    echo " PROCESANDO CARPETA: test/$dir/"
    echo "===================================="

    # Comprobar si hay archivos .c en la carpeta
    if [ -n "$(ls test/$dir/*.c 2>/dev/null)" ]; then
        for archivo_c in test/$dir/*.c; do
            # Obtener el nombre del archivo sin extensión y sin ruta
            nombre_base=$(basename "$archivo_c" .c)
            archivo_lsp="out/$dir/$nombre_base.lsp"

            echo "[C] -> $archivo_c"

            # 1. Ejecutar el traductor trad12
            # Se asume que trad12 lee de la entrada estándar y escribe en la salida
            ./trad3 < "$archivo_c" > "$archivo_lsp"

            if [ $? -eq 0 ]; then
                echo "[LISP] Generado en: $archivo_lsp"
                echo "[SALIDA CLISP]:"
                echo "---------------------------------------"
                # 2. Ejecutar el archivo generado con clisp
                clisp "$archivo_lsp"
                echo "---------------------------------------"
            else
                echo "[ERROR] Falló la traducción de $archivo_c"
            fi
            echo ""
        done
    else
        echo "No se encontraron archivos .c en test/$dir/"
    fi
done

echo "--- Proceso finalizado ---"