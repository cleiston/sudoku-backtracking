# sudoku-backtracking
Solving Sudoku puzzle using a backtracking algorithm

## Backtracking

Backtracking é um tipo de algoritmo que trás um refinamento da busca bruta.
O algoritmo busca construir candidatos a uma solução de maneira incremental. Ao perceber que um candidato não pode alcançar uma solução válida, o algoritmo volta (backtracks) para testar um candidato diferente.

## Backtracking Sudoku

O algoritmo tenta de forma ingênua acrecentar números de 1 a 9, nesta ordem, para posições vazias do tabuleiro, respeitando as regras do jogo. Quando o algoritmo não consegue chegar a uma solução, volta-se às posições preenchidas e tenta-se o número seguinte.

## Compilação e execução

#### Para compilar usando o gcc

gcc sudoku.c -o sudoku

#### Para executar o arquivo binário gerado

./sudoku
