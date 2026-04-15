#!/bin/bash

# 1. Crear directorio de salida
mkdir -p luis

# 2. Compilar según tu método
echo "--- Compilando traductor (Solo Bison) ---"
bison -d trad12.y

# Compilamos el archivo generado. 
# Nota: Si yylex() está dentro de trad12.y, esto es suficiente.
# Quitamos -lfl porque no usas la librería de Flex.
gcc trad12.tab.c -o traductor -w

if [ $? -ne 0 ]; then
    echo "Error en la compilación. Revisa el código C dentro de trad12.y"
    exit 1
fi

# 3. Procesar las pruebas
echo -e "\n--- Ejecutando pruebas ---"
for prueba in test/01/*.c; do
    base=$(basename "$prueba" .c)
    
    echo "------------------------------------"
    echo "Procesando: $base"
    
    # Generar la entrada transformada en la carpeta out
    ./traductor < "$prueba" > "luis/$base.l"
    
    if [ $? -eq 0 ]; then
        echo "Resultado en Lisp:"
        clisp "luis/$base.l"
    else
        echo "Error al traducir $prueba"
    fi
done