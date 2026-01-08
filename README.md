# 📚 Algorithms & Data Structures - C

[![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://github.com/EduardoFProenca/Algorithms-DataStructures-C)
[![GCC](https://img.shields.io/badge/GCC-Compiler-red?style=for-the-badge)](https://gcc.gnu.org/)
[![License](https://img.shields.io/badge/License-Educational-green?style=for-the-badge)](LICENSE)

> Compilado de algoritmos, estruturas de dados e exercícios desenvolvidos durante o curso de **Análise e Desenvolvimento de Sistemas** na **Fatec**.

---

## 📖 Sobre

Este repositório contém implementações de **algoritmos clássicos** e **estruturas de dados fundamentais** em linguagem C, desenvolvidos como parte dos estudos em disciplinas de programação e estrutura de dados.

O objetivo é consolidar conhecimentos em:
- Lógica de programação
- Manipulação de memória (ponteiros, alocação dinâmica)
- Estruturas de dados lineares e não-lineares
- Análise de complexidade algorítmica
- Boas práticas de programação em C

---

## 🗂️ Estrutura do Repositório

```
Algorithms-DataStructures-C/
│
├── 01-Fundamentos/              # Conceitos básicos
│   ├── variaveis-tipos.c
│   ├── operadores.c
│   └── estruturas-controle.c
│
├── 02-Ponteiros/                # Ponteiros e referências
│   ├── introducao-ponteiros.c
│   ├── ponteiros-arrays.c
│   └── ponteiros-funcoes.c
│
├── 03-Estruturas/               # Structs e Unions
│   ├── structs-basicas.c
│   ├── structs-aninhadas.c
│   └── typedef.c
│
├── 04-Alocacao-Dinamica/        # Gerenciamento de memória
│   ├── malloc-free.c
│   ├── calloc-realloc.c
│   └── vazamento-memoria.c
│
├── 05-Arrays-Strings/           # Manipulação de arrays
│   ├── arrays-unidimensionais.c
│   ├── matrizes.c
│   └── manipulacao-strings.c
│
├── 06-Algoritmos-Ordenacao/     # Sorting algorithms
│   ├── bubble-sort.c
│   ├── selection-sort.c
│   ├── insertion-sort.c
│   ├── merge-sort.c
│   └── quick-sort.c
│
├── 07-Algoritmos-Busca/         # Search algorithms
│   ├── busca-linear.c
│   ├── busca-binaria.c
│   └── busca-interpolacao.c
│
├── 08-Listas/                   # Listas ligadas
│   ├── lista-simples.c
│   ├── lista-dupla.c
│   └── lista-circular.c
│
├── 09-Pilhas/                   # Stacks (LIFO)
│   ├── pilha-array.c
│   ├── pilha-lista.c
│   └── aplicacoes-pilha.c
│
├── 10-Filas/                    # Queues (FIFO)
│   ├── fila-array.c
│   ├── fila-lista.c
│   └── fila-circular.c
│
├── 11-Arvores/                  # Estruturas hierárquicas
│   ├── arvore-binaria.c
│   ├── arvore-busca-binaria.c
│   └── percursos-arvore.c
│
├── 12-Recursao/                 # Funções recursivas
│   ├── fatorial.c
│   ├── fibonacci.c
│   └── torre-hanoi.c
│
├── 13-Projetos/                 # Projetos práticos
│   ├── calculadora/
│   ├── sistema-cadastro/
│   └── gerenciador-arquivos/
│
└── README.md                    # Este arquivo
```

---

## 🎯 Conteúdo por Categoria

### 🔹 **Fundamentos**
Conceitos básicos da linguagem C: tipos de dados, operadores, entrada/saída, estruturas de controle (if, switch, for, while).

### 🔹 **Ponteiros**
- Declaração e inicialização
- Aritmética de ponteiros
- Ponteiros para arrays e structs
- Ponteiros como parâmetros de funções

### 🔹 **Estruturas de Dados Lineares**
- **Listas:** Implementações com arrays e ponteiros
- **Pilhas:** Operações push, pop, peek
- **Filas:** Enqueue, dequeue, fila circular

### 🔹 **Estruturas de Dados Não-Lineares**
- **Árvores Binárias:** Inserção, remoção, busca
- **Árvores de Busca Binária (BST):** Percursos (in-order, pre-order, post-order)

### 🔹 **Algoritmos de Ordenação**

| Algoritmo | Complexidade Média | Estável? |
|-----------|-------------------|----------|
| Bubble Sort | O(n²) | ✅ Sim |
| Selection Sort | O(n²) | ❌ Não |
| Insertion Sort | O(n²) | ✅ Sim |
| Merge Sort | O(n log n) | ✅ Sim |
| Quick Sort | O(n log n) | ❌ Não |

### 🔹 **Algoritmos de Busca**
- **Busca Linear:** O(n)
- **Busca Binária:** O(log n) - requer array ordenado
- **Busca por Interpolação:** O(log log n) - melhor caso

---

## 🚀 Como Compilar e Executar

### **Compilar um arquivo individual:**
```bash
gcc nome-do-arquivo.c -o programa
./programa
```

### **Compilar com warnings e debugging:**
```bash
gcc -Wall -Wextra -g nome-do-arquivo.c -o programa
./programa
```

### **Usar o Makefile (se disponível):**
```bash
make
./programa
```

### **Limpar arquivos compilados:**
```bash
make clean
```

---

## 📊 Estatísticas do Repositório

- **Total de Algoritmos:** 50+
- **Estruturas de Dados:** 10+ implementações
- **Projetos Práticos:** 5+
- **Linguagem:** C (C99/C11)
- **Compilador:** GCC 9.0+

---

## 🧠 Conceitos Abordados

### **Programação:**
- Paradigma procedural
- Modularização de código
- Recursão vs Iteração
- Complexidade de tempo e espaço (Big O)

### **Gerenciamento de Memória:**
- Stack vs Heap
- Alocação estática e dinâmica
- Prevenção de memory leaks
- Ponteiros dangling (null pointers)

### **Boas Práticas:**
- Nomenclatura clara de variáveis
- Comentários explicativos
- Tratamento de erros
- Código limpo e legível

---

## 📚 Recursos de Estudo

### **Livros Recomendados:**
- *"C - Como Programar"* - Deitel & Deitel
- *"Estruturas de Dados e Algoritmos em C"* - Silvio do Lago Pereira
- *"Algoritmos: Teoria e Prática"* - Cormen et al.

### **Ferramentas Utilizadas:**
- **IDE:** Visual Studio Code, Code::Blocks
- **Compilador:** GCC (GNU Compiler Collection)
- **Debugger:** GDB (GNU Debugger)
- **Versionamento:** Git & GitHub

---

## 🎓 Disciplinas Relacionadas

Este repositório foi desenvolvido durante as seguintes disciplinas:

- **Algoritmos e Lógica de Programação**
- **Linguagem de Programação I (LP1)**
- **Estrutura de Dados**
- **Técnicas de Programação**

---

## 🔧 Pré-requisitos

Para compilar e executar os códigos, você precisa:

- **GCC** (GNU Compiler Collection) instalado
- Sistema operacional: Linux, macOS ou Windows (MinGW)
- Conhecimento básico de terminal/linha de comando

### **Instalar GCC no Linux:**
```bash
sudo apt update
sudo apt install build-essential
gcc --version
```

### **Instalar GCC no Windows:**
- Baixe o [MinGW](http://www.mingw.org/) ou use o [MSYS2](https://www.msys2.org/)

### **Instalar GCC no macOS:**
```bash
xcode-select --install
```

---

## 🐛 Contribuindo

Este é um repositório de estudos pessoais, mas sugestões são bem-vindas!

Se encontrar algum bug ou tiver sugestões de melhoria:
1. Abra uma [Issue](https://github.com/EduardoFProenca/Algorithms-DataStructures-C/issues)
2. Ou entre em contato diretamente

---

## 📈 Roadmap de Estudos

- [x] Fundamentos da linguagem C
- [x] Ponteiros e alocação dinâmica
- [x] Estruturas de dados lineares
- [x] Algoritmos de ordenação
- [ ] Estruturas de dados avançadas (Grafos, Hash Tables)
- [ ] Algoritmos de grafos (DFS, BFS, Dijkstra)
- [ ] Técnicas avançadas (Programação Dinâmica)

---

## 👨‍💻 Autor

**Eduardo Ferreira Proença**

🎓 Estudante de Análise e Desenvolvimento de Sistemas - Fatec  
💼 Foco em Desenvolvimento Back-end  


[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/eduardo-ferreira-39106b26a)
[![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/EduardoFProenca)
[![Gmail](https://img.shields.io/badge/Gmail-D14836?style=for-the-badge&logo=gmail&logoColor=white)](mailto:eduardo.ferreira.proenca.brasil@gmail.com)

---

## 📄 Licença

Este projeto foi desenvolvido para fins **educacionais** durante o curso de ADS na Fatec.  
Sinta-se livre para estudar e aprender com o código.

---

## ⭐ Gostou?

Se este repositório te ajudou nos estudos, deixe uma ⭐!

---

<div align="center">

**Desenvolvido com 💙 durante os estudos na Fatec**

*"A única maneira de aprender uma nova linguagem de programação é escrevendo programas nela."* - Dennis Ritchie

</div>
