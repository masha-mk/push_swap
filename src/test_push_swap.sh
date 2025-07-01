#!/bin/bash

# Nombre d'éléments à tester
SIZE=100

# Génère une liste de $SIZE entiers uniques et mélangés
ARG=$(seq 1 $SIZE | gshuf)

# Vérification de doublons (sécurité)
DUPLICATES=$(echo "$ARG" | tr ' ' '\n' | sort | uniq -d)

if [ -n "$DUPLICATES" ]; then
    echo "❌ Doublons détectés :"
    echo "$DUPLICATES"
    exit 1
fi

echo "🎲 Test avec $SIZE éléments :"
echo "$ARG"

# Lancer push_swap + checker
RESULT=$(./push_swap $ARG | ./checker_Mac $ARG)

if [ "$RESULT" = "OK" ]; then
    echo "✅ Tri réussi"
else
    echo "❌ Checker a répondu : $RESULT"
fi

# Compter le nombre d'instructions
COUNT=$(./push_swap $ARG | wc -l)
echo "🔢 Nombre de coups : $COUNT"
