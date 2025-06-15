# Super Trunfo em C — Comparação de Cartas

Este projeto é uma implementação do jogo educativo *Super Trunfo* em linguagem C, focado em cidades. O programa permite o cadastro de duas cartas com atributos reais de cidades brasileiras e compara seus valores com base em atributos escolhidos pelo usuário.

## 🚀 Funcionalidades

- Leitura de duas cartas (cidades) com dados como população, área, PIB e pontos turísticos
- Cálculo automático de:
  - Densidade populacional
  - PIB per capita
  - Super Poder (métrica composta)
- Comparação automática entre todas as cartas
- Escolha de dois atributos para comparar usando menu interativo
- Comparação baseada nas regras:
  - Atributos numéricos: maior valor vence
  - Densidade populacional: menor valor vence
- Resultado claro e organizado da carta vencedora ou empate

## 🛠️ Como compilar e executar

### Pré-requisitos

- Um compilador C, como o `gcc`
- Terminal com acesso ao arquivo fonte

### Compilação

Execute no terminal:

```bash
gcc -o super_trunfo super_trunfo_final.c
