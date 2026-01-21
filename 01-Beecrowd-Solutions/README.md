# 🏆 Beecrowd Solutions

<div align="center">

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Beecrowd](https://img.shields.io/badge/Beecrowd-39-success?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Accepted-brightgreen?style=for-the-badge)

Soluções comentadas em C para problemas da plataforma [Beecrowd](https://www.beecrowd.com.br/) (antiga URI Online Judge).

**Total de problemas resolvidos:** 39 ✅
> Soluções completas e comentadas de 39 problemas do Beecrowd (antigo URI Online Judge), desenvolvidas em linguagem C com foco em clareza, eficiência e boas práticas de programação.

</div>

---

## 📋 Índice

- [Sobre o Projeto](#-sobre-o-projeto)
- [Estrutura do Repositório](#-estrutura-do-repositório)
- [Problemas Resolvidos](#-problemas-resolvidos)
  - [Matemática - Teoria dos Números](#-matemática---teoria-dos-números)
  - [Matemática - Geometria](#-matemática---geometria)
  - [Estruturas de Dados](#-estruturas-de-dados)
  - [Processamento de Strings](#-processamento-de-strings)
  - [Outros](#-outros)
- [Como Usar](#-como-usar)
- [Contribuindo](#-contribuindo)

---

## 💡 Sobre o Projeto

Este repositório contém implementações detalhadas e comentadas de problemas do Beecrowd, com foco em:

- ✨ **Código limpo e legível** com nomenclatura em português
- 📝 **Documentação completa** de cada algoritmo
- 🎯 **Explicações detalhadas** da lógica de solução
- ✅ **Soluções testadas** e aceitas pela plataforma
- 🚀 **Links diretos** para testar online no OnlineGDB

---

## 📁 Estrutura do Repositório

```
01-Beecrowd-Solutions/
├── Ad-Hoc/                    # Problemas ad-hoc
├── Bit-Manipulation/          # Manipulação de bits
├── Data-Structures/           # Estruturas de dados
│   ├── ADT/                   # Tipos abstratos de dados
│   ├── Binary-Trees/          # Árvores binárias
│   ├── Queues/                # Filas
│   └── Stacks/                # Pilhas
├── Mathematics/               # Matemática
│   ├── Geometry/              # Geometria
│   └── Number-Theory/         # Teoria dos números
├── Sorting/                   # Ordenação
└── String-Processing/         # Processamento de strings
```

---

## 🎯 Problemas Resolvidos

### 📐 Matemática - Teoria dos Números

<details>
<summary><b>MDC (Máximo Divisor Comum)</b></summary>

#### **1028 - Figurinhas**
Calcula o MDC entre quantidades de figurinhas usando o Algoritmo de Euclides recursivo.

**🔗 Problema:** [Beecrowd 1028](https://judge.beecrowd.com/pt/problems/view/1028)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/dLXgV2QIM)

</details>

<details>
<summary><b>MMC (Mínimo Múltiplo Comum)</b></summary>

#### **2063 - Caçando Digletts**
Determina quando Digletts aparecerão simultaneamente calculando o MMC progressivo de múltiplos intervalos de tempo.

**🔗 Problema:** [Beecrowd 2063](https://judge.beecrowd.com/pt/problems/view/2063)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/BCAplrj7J)

---

#### **2514 - Alinhamento Lunar**
Calcula o próximo alinhamento de três luas usando MMC de períodos orbitais. Implementa cálculo encadeado do MMC.

**🔗 Problema:** [Beecrowd 2514](https://judge.beecrowd.com/pt/problems/view/2514)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/h3OSW6tXkB)

</details>

<details>
<summary><b>Números Primos</b></summary>

#### **2180 - Viagem à Marte na Velocidade de Primo**
Calcula tempo de viagem a Marte somando os 10 primeiros números primos a partir de um número dado. Usa otimização 6k±1 para verificação de primos.

**🔗 Problema:** [Beecrowd 2180](https://judge.beecrowd.com/pt/problems/view/2180)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/Q5Ge4uneK)

---

#### **2589 - Maior Distância Entre Primos Consecutivos**
Encontra o maior gap entre números primos consecutivos em um intervalo de 2 até N. Percorre todos os números verificando primalidade.

**🔗 Problema:** [Beecrowd 2589](https://judge.beecrowd.com/pt/problems/view/2589)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/ckJlnq1koV)

---

#### **2674 - Super Primos - Ativar!**
Classifica números em três categorias: **Nada** (não primo), **Primo** (primo com dígito não primo) ou **Super** (primo com todos dígitos primos: 2, 3, 5, 7).

**🔗 Problema:** [Beecrowd 2674](https://judge.beecrowd.com/pt/problems/view/2674)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/j49Rpr8RP)

---

#### **3165 - Primos Gêmeos**
Encontra o maior par de primos gêmeos (dois primos com diferença de 2) menor ou igual a N. Busca regressiva a partir de N.

**🔗 Problema:** [Beecrowd 3165](https://judge.beecrowd.com/pt/problems/view/3165)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/XgOcRmMr48)

</details>

<details>
<summary><b>Fatoriais</b></summary>

#### **1153 - Fatorial Simples**
Cálculo básico de fatorial usando multiplicação iterativa de N até 1.

**🔗 Problema:** [Beecrowd 1153](https://judge.beecrowd.com/pt/problems/view/1153)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/sdzyjboRk)

---

#### **1161 - Soma de Fatoriais**
Calcula e soma os fatoriais de dois números. Suporta números grandes usando `long long`.

**🔗 Problema:** [Beecrowd 1161](https://judge.beecrowd.com/pt/problems/view/1161)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/c4YI0b-6qw)

---

#### **1429 - Fatorial de Novo!**
Processa um número dígito por dígito (da direita para esquerda), multiplicando cada dígito pelo fatorial da sua posição e somando os resultados.

**🔗 Problema:** [Beecrowd 1429](https://judge.beecrowd.com/pt/problems/view/1429)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/UarB1xhS0)

---

#### **1457 - Oráculo de Alexandria**
Calcula fatorial múltiplo baseado na quantidade de pontos de exclamação. Ex: `5!!` = 5×3×1, `7!!!` = 7×4×1.

**🔗 Problema:** [Beecrowd 1457](https://judge.beecrowd.com/pt/problems/view/1457)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/aWjKGlu4V)

---

#### **1936 - Fatorial**
Decompõe um número em soma mínima de fatoriais distintos usando algoritmo guloso (greedy). Começa pelo maior fatorial possível.

**🔗 Problema:** [Beecrowd 1936](https://judge.beecrowd.com/pt/problems/view/1936)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/5f3RUPqvaO)

---

#### **1980 - Embaralhando**
Calcula o número de permutações (anagramas) possíveis de uma palavra. Retorna N! onde N é o comprimento da string.

**🔗 Problema:** [Beecrowd 1980](https://judge.beecrowd.com/pt/problems/view/1980)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/ESKvwHjNk)

---

#### **2129 - Fatorial**
Calcula o último dígito não zero do fatorial de N. Remove zeros à direita iterativamente e usa módulo para evitar overflow.

**🔗 Problema:** [Beecrowd 2129](https://judge.beecrowd.com/pt/problems/view/2129)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/aVygJBIRia)

</details>

<details>
<summary><b>TDA Racionais</b></summary>

#### **1022 - TDA Racional**
Implementa operações aritméticas (+, -, *, /) entre frações. Simplifica resultados usando MDC.

**🔗 Problema:** [Beecrowd 1022](https://judge.beecrowd.com/pt/problems/view/1022)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/GPx82el7b)

---

#### **2443 - Soma de Frações**
Soma duas frações e retorna o resultado na forma irredutível (simplificada pelo MDC).

**🔗 Problema:** [Beecrowd 2443](https://judge.beecrowd.com/pt/problems/view/2443)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/e-bilRJbi)

</details>

---

### 📐 Matemática - Geometria

<details>
<summary><b>Problemas de Geometria Plana</b></summary>

#### **1015 - Distância Entre Dois Pontos**
Calcula a distância euclidiana entre dois pontos usando o Teorema de Pitágoras: `√((x2-x1)² + (y2-y1)²)`.

**🔗 Problema:** [Beecrowd 1015](https://judge.beecrowd.com/pt/problems/view/1015)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/O69c_ww3lv)

---

#### **1041 - Coordenadas de um Ponto**
Determina a localização de um ponto no plano cartesiano: Origem, Eixo X, Eixo Y ou Quadrantes (Q1, Q2, Q3, Q4).

**🔗 Problema:** [Beecrowd 1041](https://judge.beecrowd.com/pt/problems/view/1041)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/s76JBp6AeD)

---

#### **1247 - Guarda Costeira**
Problema de interceptação usando triângulo retângulo. Compara tempo de percurso da guarda (hipotenusa) com tempo do fugitivo.

**🔗 Problema:** [Beecrowd 1247](https://judge.beecrowd.com/pt/problems/view/1247)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/D6H1eiQxi)

---

#### **2177 - Rio 2016**
Sistema de radar que verifica quais pontos estão dentro de um raio de alcance calculando distâncias euclidianas.

**🔗 Problema:** [Beecrowd 2177](https://judge.beecrowd.com/pt/problems/view/2177)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/_iMqTeOWR)

---

#### **2203 - Tempestade de Corvos**
Verifica alcance de ataque combinando distância percorrida (velocidade × tempo) com distância euclidiana entre pontos.

**🔗 Problema:** [Beecrowd 2203](https://judge.beecrowd.com/pt/problems/view/2203)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/vuJFq6U2ie)

</details>

---

### 🗂️ Estruturas de Dados

<details>
<summary><b>Pilhas (Stacks)</b></summary>

#### **1062 - Trilhos**
Simula reorganização de vagões usando pilha. Verifica se uma permutação é possível com estrutura LIFO.

**🔗 Problema:** [Beecrowd 1062](https://judge.beecrowd.com/pt/problems/view/1062)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/Rm5z-nPuDj)

---

#### **1068 - Balanço de Parênteses I**
Verifica balanceamento de parênteses usando pilha. Cada `(` empilha `)`, cada `)` desempilha.

**🔗 Problema:** [Beecrowd 1068](https://judge.beecrowd.com/pt/problems/view/1068)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/ZmADDpHTy)

---

#### **1069 - Diamantes e Areia**
Conta pares `<>` (diamantes) usando pilha. Cada `<` empilha, cada `>` tenta desempilhar formando um diamante.

**🔗 Problema:** [Beecrowd 1069](https://judge.beecrowd.com/pt/problems/view/1069)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/TE6RVpyA_)

</details>

<details>
<summary><b>Filas (Queues)</b></summary>

#### **1110 - Jogando Cartas Fora**
Simula jogo de cartas: descarta a primeira, move a segunda para o fim. Usa fila FIFO.

**🔗 Problema:** [Beecrowd 1110](https://judge.beecrowd.com/pt/problems/view/1110)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/U06vOTjue)

---

#### **2460 - Fila**
Gerencia fila de pessoas com remoções específicas. Implementa busca e remoção em lista encadeada.

**🔗 Problema:** [Beecrowd 2460](https://judge.beecrowd.com/pt/problems/view/2460)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/FnO39a1CY)

---

#### **3163 - Controlador de Vôo**
Sistema de priorização de voos. Separa em 4 filas por prioridade e consolida na ordem: 1→3→2→4.

**🔗 Problema:** [Beecrowd 3163](https://judge.beecrowd.com/pt/problems/view/3163)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/G3uqH74p9)

</details>

<details>
<summary><b>Árvores Binárias de Busca (BST)</b></summary>

#### **1195 - Árvore Binária de Busca**
Constrói BST e imprime em três ordens: Pré-ordem (Raiz→Esq→Dir), Em-ordem (Esq→Raiz→Dir), Pós-ordem (Esq→Dir→Raiz).

**🔗 Problema:** [Beecrowd 1195](https://judge.beecrowd.com/pt/problems/view/1195)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/4wrAY3VDVr)

---

#### **1200 - Operações em ABP I**
BST com caracteres. Operações: Inserir (I), Pesquisar (P), Imprimir em Pré/In/Pós-ordem.

**🔗 Problema:** [Beecrowd 1200](https://judge.beecrowd.com/pt/problems/view/1200)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/jsC8DWVoU)

---

#### **1201 - Operações em ABP II**
BST avançada com operação de remoção. Trata 3 casos: folha, 1 filho, 2 filhos (usa antecessor).

**🔗 Problema:** [Beecrowd 1201](https://judge.beecrowd.com/pt/problems/view/1201)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/DpHpcf5Ko)

---

#### **1466 - Percurso em Árvore por Nível**
Travessia em largura (BFS/Level Order) usando fila. Visita nível por nível da esquerda para direita.

**🔗 Problema:** [Beecrowd 1466](https://judge.beecrowd.com/pt/problems/view/1466)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/g4rYocqyb-)

---

#### **3484 - Turma Dividida**
Encontra o menor valor em cada nível da BST usando BFS. Processa todos os nós de um nível antes de avançar.

**🔗 Problema:** [Beecrowd 3484](https://judge.beecrowd.com/pt/problems/view/3484)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/ptQxdTSvRt)

</details>

---

### 📝 Processamento de Strings

<details>
<summary><b>Manipulação de Strings</b></summary>

#### **2204 - Pare a Bomba!**
Compara duas strings. Se idênticas, imprime a string; caso contrário, imprime "1".

**🔗 Problema:** [Beecrowd 2204](https://judge.beecrowd.com/pt/problems/view/2204)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/xyeOjiwSSs)

---

#### **2242 - Huaauhahhuahau**
Verifica se uma risada é "engraçada". Extrai apenas vogais e verifica se formam um palíndromo.

**🔗 Problema:** [Beecrowd 2242](https://judge.beecrowd.com/pt/problems/view/2242)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/xjs0vJrxFN)

---

#### **2722 - Pegadinha de Evergreen**
Decifra mensagem intercalando 2 caracteres da linha 1, depois 2 da linha 2, alternadamente.

**🔗 Problema:** [Beecrowd 2722](https://judge.beecrowd.com/pt/problems/view/2722)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/iKVwlVVAV)

---

#### **3160 - Amigos**
Insere novo amigo em lista existente. Se "nao", adiciona no fim; senão, insere antes do nome indicado usando `strstr`.

**🔗 Problema:** [Beecrowd 3160](https://judge.beecrowd.com/pt/problems/view/3160)

</details>

---

### 🔧 Outros

<details>
<summary><b>Problemas Diversos</b></summary>

#### **1367 - Ajude!**
Calcula pontuação de maratona de programação. Conta problemas aceitos e soma tempo + penalidades (20 min por erro).

**🔗 Problema:** [Beecrowd 1367](https://judge.beecrowd.com/pt/problems/view/1367)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/AdLnDfNo9)

---

#### **1548 - Fila do Recreio**
Conta quantos alunos já estão na posição correta se a fila fosse ordenada por notas (decrescente). Usa Bubble Sort.

**🔗 Problema:** [Beecrowd 1548](https://judge.beecrowd.com/pt/problems/view/1548)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/vsqAUQCEb)

---

#### **2718 - Luzes de Natal**
Converte número decimal para binário e encontra a maior sequência consecutiva de bits '1'.

**🔗 Problema:** [Beecrowd 2718](https://judge.beecrowd.com/pt/problems/view/2718)  
**🌐 Testar online:** [![Run on OnlineGDB](https://img.shields.io/badge/Run%20on-OnlineGDB-blue?style=flat-square&logo=c)](https://onlinegdb.com/VliMRPslY)

</details>

---

## 🚀 Como Usar

**▶️ Compilar e executar qualquer solução:**

```bash
# Navegue até a pasta do problema
cd 01-Beecrowd-Solutions/<categoria>/<subcategoria>

# Compile (adicione -lm se usar funções matemáticas)
gcc nome-do-arquivo.c -o programa -lm

# Execute
./programa
```

**Exemplo:**
```bash
cd 01-Beecrowd-Solutions/Mathematics/Number-Theory/Prime-Numbers
gcc 2674-super-primos.c -o super -lm
./super
```

---

## 🤝 Contribuindo

Contribuições são bem-vindas! Para adicionar novas soluções:

1. **Fork** este repositório
2. Crie uma **branch** para sua solução (`git checkout -b problema-XXXX`)
3. Adicione o código com **comentários detalhados**
4. **Commit** suas mudanças (`git commit -m 'Add: Solução problema XXXX'`)
5. **Push** para a branch (`git push origin problema-XXXX`)
6. Abra um **Pull Request**

---

## 💡 Algoritmos Implementados

### Matemática:
- Algoritmo de Euclides (MDC)
- Cálculo de MMC via MDC
- Crivo de Eratóstenes (verificação de primos)
- Fatoriais iterativos e variações
- Distância Euclidiana
- TDA para números racionais

### Estruturas de Dados:
- Pilhas com lista encadeada (LIFO)
- Filas com lista encadeada (FIFO)
- Árvores Binárias de Busca (BST)
- Travessia em árvores (Pré, In, Pós-ordem)
- Travessia por nível (BFS)

### Strings:
- Palíndromo
- Intercalação
- Comparação e busca
- Processamento caractere a caractere

### Ordenação:
- Bubble Sort

---

## 📖 Como Usar Este Repositório

### Para Estudar:
1. Leia o problema no link do Beecrowd
2. Tente resolver por conta própria
3. Compare sua solução com a deste repositório
4. Teste no Online GDB para ver o funcionamento

### Para Referência:
- Use como base para resolver problemas similares
- Consulte as implementações de algoritmos específicos
- Aprenda padrões de estruturas de dados

### Para Praticar:
- Compile e execute os códigos localmente
- Modifique os algoritmos para aprender
- Submeta sua própria versão no Beecrowd

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

## 🏅 Conceitos Dominados

### Forte em:
- ✅ Fatoriais (7 problemas diferentes)
- ✅ Árvores Binárias de Busca (5 problemas)
- ✅ Números Primos (4 problemas)
- ✅ Pilhas e Filas (6 problemas)

### Experiência com:
- Algoritmos Recursivos
- Alocação Dinâmica de Memória
- Manipulação de Strings
- Geometria Computacional Básica
- Teoria dos Números

---

## 🎓 Sobre

Estas soluções foram desenvolvidas durante o curso de **Análise e Desenvolvimento de Sistemas** na **Fatec**, como parte dos estudos de Algoritmos e Estruturas de Dados.

**Objetivo:** Consolidar conhecimentos em programação C, estruturas de dados e resolução de problemas algorítmicos.

## ⚠️ Aviso

Estas soluções são fornecidas para fins **educacionais**. Recomenda-se:
- Sempre tentar resolver os problemas por conta própria primeiro
- Usar estas soluções como referência de estudo
- Entender a lógica antes de reutilizar o código
- Respeitar as regras de sua instituição de ensino sobre plágio


---

<div align="center">

**Desenvolvido com 💙 por Eduardo Ferreira Proença**

[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/eduardo-ferreira-39106b26a)
[![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/EduardoFProenca)
[![Gmail](https://img.shields.io/badge/Gmail-D14836?style=for-the-badge&logo=gmail&logoColor=white)](mailto:eduardo.ferreira.proenca.brasil@gmail.com)
[![Beecrowd](https://img.shields.io/badge/Beecrowd-39_problemas-success?style=for-the-badge)](https://judge.beecrowd.com/pt/profile/1105139)

⭐ **Se este repositório foi útil, considere dar uma estrela!** ⭐

</div>
