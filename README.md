# Busca - Algoritmos de busca 
Repositório para resolução de questões relacionadas à algoritmos de busca e hash table.

## Aluno  
| Matrícula | Nome |  
|-----------------------|---------------------|  
| 19/0010495 | Arthur Alves de Matos |

## Descrição do projeto
O objetivo do projeto é responder questões disponíveis em juízes online sobre algoritmos de busca, as questões serão de média e alta complexidade.

## Guia de instalação
**Linguagem**: C<br>

### Dependências do projeto
Para a utilização do projeto, deve-se ter acesso ao compilador de linguagem C gcc.

### Como executar o projeto
## Uso 
Cada questão foi separada em uma pasta diferente e para executar os códigos de cada uma das questões é necessário a execução dos 3 seguintes comandos adaptados ao nome do arquivo de cada questão. Ex:

```sh
    cd Questoes/xxx/
    gcc -o xxx xxx.c
    ./xxx < xxx.txt
```

### Execuções do repositório
- Beecrowd 1025 - Onde está o Mármore?
```sh
    cd Questoes/1025/
    gcc -o 1025 1025.c
    ./1025 < 1025.txt
```


- Beecrowd 1382 - Elementar, meu Caro Watson!
```sh
    cd Questoes/1382/
    gcc -o 1382 1382.c
    ./1382 < 1382.txt
```

- LeetCode - 149. Max Points on a Line

Adaptada para teste fora do ambiente do leetcode, a function main não é utilizada para o submit da resposta no online judge.
```sh
    cd /Questoes/max-points-on-a-line/
    gcc -o resposta resposta.c
    ./resposta < resposta.txt
```

- LeetCode - 3. Longest Substring Without Repeating Characters

Adaptada para teste fora do ambiente do leetcode, a function main não é utilizada para o submit da resposta no online judge.
```sh
    cd /Questoes/longest-substring/
    gcc -o resposta resposta.c
    ./resposta < resposta.txt
```

## Capturas de tela
Todo: Adicionar capturas de tela

## Conclusões
As questões abordadas no projeto foram:

- [LeetCode - 149. Max Points on a Line](https://leetcode.com/problems/max-points-on-a-line/description/)
- [LeetCode - 3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)
- [Beecrowd - 1025 Onde está o Mármore?](https://judge.beecrowd.com/pt/problems/view/1025)

### Extra
Questão extra, não está dentro do assunto de Algoritmos de busca diretamente, mas tem na resolução um endereçamento direto no array de "permutacao" que consulta em O(1).

- [Beecrowd - 1382 Elementar, meu Caro Watson!](https://judge.beecrowd.com/pt/problems/view/1382)
