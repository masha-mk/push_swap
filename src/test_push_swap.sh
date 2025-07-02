#!/bin/bash

# Nombre d'éléments à tester
SIZE=100

# Génère une liste de $SIZE entiers uniques et mélangés
ARG=$(seq 1 $SIZE | shuf | tr '\n' ' ')

# Compter le nombre d'instructions
COUNT=$(./push_swap $ARG | wc -l)
echo "Nombre de coups : $COUNT"

VALGRIND_OUTPUT=$(valgrind --leak-check=full --track-origins=yes ./push_swap $ARG 2>&1)

if echo "$VALGRIND_OUTPUT" | grep -q "ERROR SUMMARY: 0 errors from 0 contexts"; then
    echo "✅AUCUN LEAK"
else
    echo "❌LEAK DÉTECTÉ"
fi