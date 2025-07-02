#!/bin/bash

# Nombre d'éléments à tester
SIZE=500

# Génère une liste de $SIZE entiers uniques et mélangés
ARG=$(seq 1 $SIZE | shuf | tr '\n' ' ')

# Compter le nombre d'instructions
COUNT=$(./push_swap $ARG | wc -l)
echo "🔢 Nombre de coups : $COUNT"
