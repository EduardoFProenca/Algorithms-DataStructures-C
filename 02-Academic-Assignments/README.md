# 02-Academic-Assignments

Coleção de exercícios acadêmicos de programação em C, organizados em 4 assignments que cobrem estruturas de dados fundamentais e algoritmos clássicos.

---

## 📋 Índice

- [Assignment 01 - Fundamentos e Algoritmos Básicos](#assignment-01---fundamentos-e-algoritmos-básicos)
- [Assignment 02 - Strings, Estruturas e Arrays](#assignment-02---strings-estruturas-e-arrays)
- [Assignment 03 - Listas Encadeadas e Pilhas](#assignment-03---listas-encadeadas-e-pilhas)
- [Assignment 04 - Árvores Binárias](#assignment-04---árvores-binárias)
- [Como Executar](#como-executar)

---

## Assignment 01 - Fundamentos e Algoritmos Básicos

### Q1 - IAC Calculator
**Arquivo:** `Q1-iac-calculator.c`

Calcula o Índice de Adiposidade Corporal (IAC) e classifica o nível de gordura corporal baseado no sexo biológico.

**Fórmula:** `IAC = (Circunferência do Quadril / (Altura * √Altura)) - 18`

**Funcionalidades:**
- Entrada de dados: Sexo (M/F), Circunferência e Altura
- Cálculo automático do IAC
- Classificação em 6 categorias (Excesso, Moderada, Ideal, Baixa, Excepcionalmente baixa, Inválido)
- Loop contínuo até digitar 'X'

**🌐 Testar online:**  
[![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=for-the-badge&logo=c)](https://onlinegdb.com/XOyMbEYAo)

---

### Q2 - Date Validator
**Arquivo:** `Q2-date-validator.c`

Validador avançado de datas com suporte ao Calendário Gregoriano e cálculo do dia da semana.

**Funcionalidades:**
- Validação completa de datas (ano, mês, dia)
- Verificação de anos bissextos
- Tratamento da transição histórica de 1582 (dias 5-14 de outubro não existem)
- Cálculo do dia da semana usando o Algoritmo de Congruência de Zeller
- Loop até entrada `0 0 0`

**🌐 Testar online:**  
[![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=for-the-badge&logo=c)](https://onlinegdb.com/_9N8PALMX)

---

### Q3 - Statistics Calculator
**Arquivo:** `Q3-statistics.c`

Realiza análise estatística básica sobre 15 números inteiros.

**Estatísticas calculadas:**
- Média Aritmética
- Variância
- Desvio Padrão
- Moda (com critério de desempate: maior valor em caso de empate)

**🌐 Testar online:**  
[![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=for-the-badge&logo=c)](https://onlinegdb.com/KzJbkaWcF)

---

### Q4 - Ackermann Function
**Arquivo:** `Q4-ackermann.c`

Implementação da Função de Ackermann-Péter, demonstrando recursão profunda.

**Definição matemática:**
```
A(m, n) = 
  n + 1                     se m = 0
  A(m - 1, 1)               se m > 0 e n = 0
  A(m - 1, A(m, n - 1))     se m > 0 e n > 0
```

⚠️ **Aviso:** Valores altos de m (> 3) podem causar Stack Overflow.

**🌐 Testar online:**  
[![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=for-the-badge&logo=c)](https://onlinegdb.com/DoG3TNho_)

---

## Assignment 02 - Strings, Estruturas e Arrays

### Q1 - Password Checker
**Arquivo:** `Q1-check-password.c`

Validador de senhas com regras de segurança específicas.

**Critérios de validação:**
- Nova senha deve ser igual à senha anterior
- Mínimo de 6 caracteres
- Pelo menos 1 letra minúscula
- Pelo menos 1 letra maiúscula
- Pelo menos 1 dígito numérico

**🌐 Testar online:**  
[![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=for-the-badge&logo=c)](https://onlinegdb.com/yMfHtyNN0)

---

### Q2 - Euclidean Distance
**Arquivo:** `Q2-euclidean-distance.c`

Calcula a distância Euclidiana entre dois pontos no plano cartesiano 2D.

**Fórmula:** `d = √((x2 - x1)² + (y2 - y1)²)`

**Funcionalidades:**
- Uso de `struct` para representar pontos
- Loop contínuo até entrada `0 0 0 0`
- Precisão de 2 casas decimais

**🌐 Testar online:**  
[![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=for-the-badge&logo=c)](https://onlinegdb.com/98j5WzohB)

---

### Q3 - Point in Rectangle
**Arquivo:** `Q3-point-in-rectangle.c`

Verifica se um ponto está contido dentro de um retângulo.

**Entrada:** `x0 y0 x1 y1 x y` (2 pontos do retângulo + 1 ponto de teste)

**Saída:** "Contido" ou "Nao-contido"

**🌐 Testar online:**  
[![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=for-the-badge&logo=c)](https://onlinegdb.com/4IWOn3dMj)

---

### Q4 - Production Cost Calculator
**Arquivo:** `Q4-production-cost-calculator.c`

Sistema de controle financeiro para produção fabril usando matrizes.

**Estrutura de dados:**
- Matriz 3×3: Produção de 3 peças em 3 meses
- Matriz 3×2: Custo e Lucro unitário por peça
- Matriz 3×2: Totais mensais (Custo Total e Lucro Total)

**🌐 Testar online:**  
[![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=for-the-badge&logo=c)](https://onlinegdb.com/M0qtRRADL)

---

### Q5 - Bubble Sort Counter
**Arquivo:** `Q5-bubble-sort-counter.c`

Implementação otimizada do algoritmo Bubble Sort com contador de trocas.

**Funcionalidades:**
- Ordena 10 números inteiros em ordem crescente
- Conta o total de trocas realizadas
- Detecção se o vetor já estava ordenado
- Otimização: Para quando nenhuma troca é necessária

**🌐 Testar online:**  
[![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=for-the-badge&logo=c)](https://onlinegdb.com/B47ZgcS3b)

---

## Assignment 03 - Listas Encadeadas e Pilhas

### Q1 - Shopping List (Dynamic)
**Arquivos:** `lista.h`, `lista.c`, `main.c`

Lista de compras usando Lista Duplamente Encadeada com alocação dinâmica.

**Operações:**
- `I` - Incluir produto (nome e quantidade)
- `P F` - Imprimir lista (ordem normal)
- `P R` - Imprimir lista (ordem reversa)
- `A` - Atualizar (marcar como comprado)
- `X` - Excluir produto
- `*` - Sair

**Características:**
- Ordenação alfabética automática
- Navegação bidirecional (prev/next)
- Contadores de itens totais e comprados

**🌐 Testar online:**  
[![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=for-the-badge&logo=c)](https://onlinegdb.com/pFqoFwZEg)

---

### Q2 - Shopping List (Static)
**Arquivos:** `lista_estatica.h`, `lista_estatica.c`, `main.c`

Versão da lista de compras usando Array Estático (capacidade máxima: 50 itens).

**Diferenças da versão dinâmica:**
- Limite fixo de memória
- Deslocamento de elementos em inserções/exclusões
- Sem alocação dinâmica

**🌐 Testar online:**  
[![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=for-the-badge&logo=c)](https://onlinegdb.com/W_MeVc1XP)

---

### Q3 - Linked List Concatenator
**Arquivo:** `Q3-linked-list-concatenator.c`

Gerencia e concatena listas encadeadas dinâmicas.

**Funcionalidades:**
- Criação de listas com números reais (float)
- Concatenação de listas (preserva originais)
- Inserção eficiente no final (ponteiro tail)
- Gerenciamento de memória com `malloc` e `free`

**🌐 Testar online:**  
[![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=for-the-badge&logo=c)](https://onlinegdb.com/kOMt3F57L)

---

### Q4 - Balanced Parentheses
**Arquivo:** `Q4-balanced-parentheses.c`

Verifica balanceamento de delimitadores em expressões aritméticas usando Pilha (Stack).

**Delimitadores suportados:** `{ } [ ] ( )`

**Estratégia:**
- Ao encontrar abertura: empilha o fechamento correspondente
- Ao encontrar fechamento: desempilha e verifica correspondência
- LIFO (Last In, First Out)

**🌐 Testar online:**  
[![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=for-the-badge&logo=c)](https://onlinegdb.com/_uRFTrFCiK)

---

## Assignment 04 - Árvores Binárias

### Q1 - Binary Search Tree with Frequency
**Arquivo:** `Q1-tree-frequency.c`

Árvore Binária de Busca (BST) com contador de frequência para duplicatas.

**Funcionalidades:**
- Inserção ordenada (esquerda < raiz < direita)
- Contador de duplicatas por nó
- Impressão visual da árvore (rotação 90°)
- Busca de valores
- Exibição de ancestrais (caminho até a raiz)
- Estatísticas: total de nós únicos e total de valores

**🌐 Testar online:**  
[![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=for-the-badge&logo=c)](https://onlinegdb.com/cn1w9E1vJ)

---

### Q2 - Complete Binary Tree
**Arquivo:** `Q2-complete-tree.c`

Implementação de Árvore Binária Completa com inserção nível por nível.

**Características:**
- Inserção sequencial (esquerda → direita, nível a nível)
- Impressão por níveis (BFS - Breadth-First Search)
- Uso de Fila para navegação
- Estatísticas: total de nós, altura, quantidade de pares

**Diferença da BST:** Não considera valores para posicionamento, apenas mantém estrutura cheia.

**🌐 Testar online:**  
[![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=for-the-badge&logo=c)](https://onlinegdb.com/EsI_WTNjF)

---

### Q3 - Heap Validator
**Arquivo:** `Q3-heap-validator.c`

Verifica se uma sequência de números forma um Heap válido.

**Processo:**
1. Constrói Árvore Binária Completa
2. Verifica propriedades de Heap:
   - **Max-Heap:** Pai ≥ Filhos
   - **Min-Heap:** Pai ≤ Filhos

**Entrada:** Múltiplos casos de teste (EOF)  
**Saída:** `max`, `min` ou `nada`

**🌐 Testar online:**  
[![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=for-the-badge&logo=c)](https://onlinegdb.com/a8TXtnt44)

---

## 🚀 Como Executar

### Opção 1: Online (Recomendado)
Clique nos badges **"Run on OnlineGDB"** fornecidos para cada exercício. O código já está pré-carregado e pronto para execução.

### Opção 2: Compilação Local

#### Programas simples (arquivo único):
```bash
gcc Q1-iac-calculator.c -o iac -lm
./iac
```

#### Programas modulares (múltiplos arquivos):
```bash
# Assignment 03 - Q1
gcc main.c lista.c -o shopping -lm
./shopping

# Assignment 03 - Q2
gcc main.c lista_estatica.c -o shopping_static -lm
./shopping_static
```

**Nota:** A flag `-lm` é necessária para programas que usam a biblioteca `math.h`.

---

## 📚 Conceitos Abordados

- ✅ Estruturas de controle (loops, condicionais)
- ✅ Funções e modularização
- ✅ Arrays e matrizes
- ✅ Strings e manipulação de caracteres
- ✅ Structs e tipos definidos pelo usuário
- ✅ Ponteiros e alocação dinâmica de memória
- ✅ Listas encadeadas (simples e duplamente)
- ✅ Pilhas (Stack - LIFO)
- ✅ Filas (Queue - FIFO)
- ✅ Árvores Binárias (BST, Complete, Heap)
- ✅ Recursão (simples e profunda)
- ✅ Algoritmos de ordenação (Bubble Sort)
- ✅ Algoritmos de busca (linear, binária em árvore)
- ✅ Travessias de árvore (in-order, level-order)

---

## 📝 Notas Adicionais

- Todos os códigos incluem comentários detalhados em português
- Inputs são validados quando aplicável
- Gerenciamento de memória adequado (malloc/free)
- Tratamento de casos extremos e erros

---
## 🔗 Links Úteis

- [Beecrowd](https://www.beecrowd.com.br/) - Plataforma de juiz online
- [Online GDB](https://www.onlinegdb.com/) - Compilador online para testar
- [GCC Documentation](https://gcc.gnu.org/onlinedocs/) - Documentação do compilador

---

## 📝 Convenções de Código

- **Nomenclatura:** CamelCase para funções, snake_case para variáveis locais
- **Comentários:** Todos os códigos possuem comentários explicativos
- **Indentação:** 4 espaços
- **Idioma:** Comentários em português, código em inglês

---

## 🎓 Sobre

Estas soluções foram desenvolvidas durante o curso de **Análise e Desenvolvimento de Sistemas** na **Fatec**, como parte dos estudos de Algoritmos e Estruturas de Dados.

**Objetivo:** Consolidar conhecimentos em programação C, estruturas de dados e resolução de problemas algorítmicos.




---

<div align="center">

**Desenvolvido com 💙 por Eduardo Ferreira Proença**

[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/eduardo-ferreira-39106b26a)
[![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/EduardoFProenca)
[![Gmail](https://img.shields.io/badge/Gmail-D14836?style=for-the-badge&logo=gmail&logoColor=white)](mailto:eduardo.ferreira.proenca.brasil@gmail.com)


⭐ **Se este repositório foi útil, considere dar uma estrela!** ⭐

</div>
