#!/bin/bash

data= {50 100 150 200 250 300 350 400 450 500 550 600 650 700 750 800 850 900 950 1000}

for n in $(seq 50 50 1000)
do 
    for i in {1..50}
    do
        echo "Experimento (${i}) para n=${n}"
        ./determinante ${n} 1 100 >> resultados.txt
    done
done 






