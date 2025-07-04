#!/bin/bash

# === TESTS D'ERREURS DE push_swap ===

echo "=== TESTS D'ERREURS ==="

# Test 1 : Paramètre non numérique
echo -n "Test 1 (non numérique) : "
./push_swap 1 2 trois 4 > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo "❌ (doit afficher 'Error')"
else
    echo "✅"
fi

# Test 2 : Doublon
echo -n "Test 2 (doublon) : "
OUTPUT=$(./push_swap 1 2 3 2 4 5 2>&1)
if echo "$OUTPUT" | grep -q "Error"; then
    echo "✅"
else
    echo "❌ (doit afficher 'Error')"
fi

# Test 3 : Valeur > INT_MAX
echo -n "Test 3 (supérieur à INT_MAX) : "
OUTPUT=$(./push_swap 1 2 2147483648 2>&1)
if echo "$OUTPUT" | grep -q "Error"; then
    echo "✅"
else
    echo "❌ (doit afficher 'Error')"
fi

# Test 4 : Aucun paramètre
echo -n "Test 4 (aucun paramètre) : "
OUTPUT=$(./push_swap)
if [ -z "$OUTPUT" ]; then
    echo "✅"
else
    echo "❌ (ne doit rien afficher)"
fi

# === TEST DE TRI AVEC $SIZE ÉLÉMENTS ===

SIZE=$1
echo
echo "=== TEST DE TRI AVEC $SIZE ÉLÉMENTS ==="

ARG=$(seq 1 $SIZE | shuf | tr '\n' ' ')
SORTED=$(./push_swap $ARG)

echo "$SORTED"

COUNT=$(echo "$SORTED" | grep -E '^(pa|pb|sa|sb|ss|ra|rb|rr|rra|rrb|rrr)$' | wc -l)
echo "Nombre de coups : $COUNT"

# Décommenter cette section pour tester les fuites mémoire avec Valgrind
# echo
# echo "=== TEST VALGRIND ==="
VALGRIND_OUTPUT=$(valgrind --leak-check=full --track-origins=yes ./push_swap $ARG 2>&1)

if echo "$VALGRIND_OUTPUT" | grep -q "All heap blocks were freed"; then
    echo "✅ AUCUN LEAK"
else
    echo "❌ LEAK DÉTECTÉ"
fi