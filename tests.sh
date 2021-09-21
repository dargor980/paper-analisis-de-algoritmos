#!/bin/bash

cd app/dist/

for n in $(seq 50 50 1000)
do 
    for i in $(seq 1 1 20)
    do
        echo "Experimento (${i}) para n=${n}" 
        ./determinante ${n} 1 100 >> resultados.txt
    done
done 






