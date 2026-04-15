#!/bin/bash

# Array con las carpetas a procesar
carpetas=("test/00" "test/01" "test/02" "test/03")

echo "--- Iniciando compilación de archivos C de test ---"

for dir in "${carpetas[@]}"; do
    echo "==================================="
    echo " REVISANDO CARPETA: $dir/"
    echo "==================================="

    # Comprobar si hay archivos .c en la carpeta
    if ls "$dir"/*.c 1> /dev/null 2>&1; then
        for archivo_c in "$dir"/*.c; do
            # Quitar la extensión .c de la ruta para nombrar el ejecutable
            ejecutable="${archivo_c%.c}"

            echo "Compilando: $archivo_c"

            # Compilar con gcc
            gcc "$archivo_c" -o "$ejecutable"

            if [ $? -eq 0 ]; then
                echo "  -> [OK] Guardado como: $ejecutable"
            else
                echo "  -> [ERROR] Falló la compilación de $archivo_c"
            fi
        done
    else
        echo "No se encontraron archivos .c en $dir/"
    fi
    echo ""
done

echo "--- Proceso finalizado ---"