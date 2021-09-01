#!/bin/bash

for n in $(seq 50 50 1000)
do 
    for i in {1..50}
    do
        echo "Experimento (${i}) para n=${n}"
        ./determinante ${n} 1 100 >> resultados.txt
    done
done 






