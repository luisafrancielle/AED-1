# Trabalho Final - Algoritmos e Estruturas de Dados

Metódos de organização da Disciplina Algoritmos e Estruturas de Dados 1 do curso de Bacharelado em Inteligência Artificial.

# Etapas do projeto:

- `Atividade 1`: Implementar os métodos de Ordenação Simples (InsertionSort e SelectionSort) e ShellSort;
- `Atividade 2`: Implementar o algoritmo QuickSort;
- `Atividade 3`: Implementar o algoritmo MergeSort;
- `Atividade 4`: Implementar o método de busca;

# Metódos de Ordenação:

• InsertionSort • 

Vantagens:

Simples de implementar e compreender.<br />
Eficiente para pequenos conjuntos de dados ou para dados já parcialmente ordenados.<br />
Pode ser usado para ordenar uma lista à medida que é recebida, sem a necessidade de armazenar todos os dados antes de iniciar a ordenação.<br />

Desvantagens:

Tem complexidade de tempo O(n^2), o que o torna ineficiente para grandes conjuntos de dados.<br />
Não é escalável, já que sua complexidade de tempo aumenta dramaticamente com o tamanho dos dados.<br />
Pode ser bastante lento em conjuntos de dados desordenados.<br />

• ShellSort •

Vantagens:

Shellsort é uma ótima opção para arquivos de tamanho moderado;<br />
Sua implementação é simples e requer uma quantidade de código pequena.<br />

Desvantagens:

O tempo de execução do algoritmo é sensível à ordem inicial do arquivo;<br />
O método não é estável;<br />

• SelectIosort •

Vantagens:

• É um dos métodos mais simples de ordenação existentes.<br />
• Para arquivos com registros muito grandes e chaves pequenas, este deve ser o método a ser utilizado.<br />
• Com chaves do tamanho de uma palavra, este método torna se bastante interessante para arquivos pequenos.<br />

Desvantagens:

• O fato do arquivo já estar ordenado não ajuda em nada, pois o custo continua quadrático.<br />
• O algoritmo não é estável, pois ele nem sempre deixa os registros com chaves iguais na mesma posição relativa.<br />
