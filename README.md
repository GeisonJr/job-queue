Especificação para o Projeto 01 - Simulador de Escalonamento de Processos (v 1.0)
===========================================================================================================================

Implementar um programa que alimente e manipule uma tabela de processos e, com base nas informações existentes na mesma, simule o 
algoritimo de escalonamento atribuído para a equipe e determine, a partir de tal algoritimo, a ordem de término dos processos.

Observações Importantes.
===========================================================================================================================
> O PID deverá ser atribuído automaticamente para cada processo inserido na tabela de processos, iniciando do 100, incrementando de
  1 em 1 a cada processo inserido na tabela. // OK
> Será inserido um único processo por vez na tabela, ou seja, para cada processo o operador dever escolher a opção para tal no menu. // OK
> São informações básicas dos processos o PID, NOME, ciclos de CPU e ciclos de I/O. // OK
> Dependendo do algoritimo a ser usado, o processo também poderá ter como informação a PRIORIDADE (0-4) e o TIPO (SO, IN e NI). // OK
> O número de filas será 5, ou seja, de 0 até 4, tanto para o algoritimo de Prioridade Estática como para o de Prioridade Dinâmica. // ?
> A tabela de processos poderá permitir a existência de, no máximo, 10 processos ao mesmo tempo, cabendo ao programa controlar a isso. // ?
> A busca para exibição, alteração e remoção de um processo deve ser feita a partir de seu PID. // OK
> Será permitido alterar praticamente todos os dados de um processo, exceto seu PID. // OK
> O programa não poderá permitir a inserção de processos com o mesmo NOME. // +
> Utilizar as regras definidas para o escalonamento apresentadas na disciplina. // ?
> O programa deverá ser escrito em linguagem C para o Linux e será compilado e executado no SLAX usado nas aulas. // +
> A equipe poderá ser composta por, no máximo, 4 pessoas mas também poderá ser desenvolvido individualmente. // OK
> O nome completo de cada componente da equipe deve estar nas primeiras linhas do código-fonte, na forma de comentário. // OK



Telas e Interações do Programa
===========================================================================================================================

Menu Principal // OK
-----------------------------------------------------------
1. Incluir um Processo
2. Exibir os dados de um Processo
3. Alterar os dados de um Processo
4. Remover um Processo
5. Exibir toda a Tabela de Processos
6. Remover todos os Processos
7. Executar o Algoritimo
8. Exibir os Participantes da Equipe
9. Encerrar a execução do programa
-----------------------------------------------------------
Opcao (1-9):



Incluir um Processo // OK
-----------------------------------------------------------
PID: xxx (atribuído automaticamente)
NOME: (solicitar conteúdo ao operador)
CPU: (solicitar conteúdo ao operador)
I/O: (solicitar conteúdo ao operador)
Prioridade: (solicitar conteúdo ao operador)
Tipo: (solicitar conteúdo ao operador)
-----------------------------------------------------------
Confirmar a Inclusão (S/N): (solicitar confirmação ao operador)



Exibir os dados de um Processo // OK
-----------------------------------------------------------
PID: xxx (perguntar ao operador - chave de busca)
NOME: (exibir o conteúdor)
CPU:  (exibir o conteúdor)
I/O:  (exibir o conteúdor)
Prioridade:  (exibir o conteúdor)
Tipo:  (exibir o conteúdor)
-----------------------------------------------------------
Pressione ENTER para continuar ... (solicitar ao operador)



Alterar os dados de um Processo // OK
-----------------------------------------------------------
PID: xxx (perguntar ao operador - chave de busca)
NOME: (solicitar novo conteúdo ao operador)
CPU: (solicitar novo conteúdo ao operador)
I/O: (solicitar novo conteúdo ao operador)
Prioridade: (solicitar novo conteúdo ao operador)
Tipo: (solicitar novo conteúdo ao operador)
-----------------------------------------------------------
Confirmar a Alteração (S/N): (solicitar confirmação ao operador)



Remover um Processo // OK
-----------------------------------------------------------
PID: xxx (perguntar ao operador - chave de busca)
NOME: (exibir o conteúdor)
CPU: (exibir o conteúdor)
I/O: (exibir o conteúdor)
Prioridade: (exibir o conteúdor)
Tipo:(exibir o conteúdor)
-----------------------------------------------------------
Confirmar a Remoção (S/N): (solicitar confirmação ao operador)



Exibir toda a Tabela de Processos // OK
-----------------------------------------------------------
NOME    PID    PRI    CPU    I/O
xxxx    xxx    xxx    xxx    xxx
xxxx    xxx    xxx    xxx    xxx
xxxx    xxx    xxx    xxx    xxx
xxxx    xxx    xxx    xxx    xxx
xxxx    xxx    xxx    xxx    xxx
xxxx    xxx    xxx    xxx    xxx
xxxx    xxx    xxx    xxx    xxx
-----------------------------------------------------------
Pressione ENTER para continuar ... (solicitar ao operador)



Remover todos os Processos // OK
-----------------------------------------------------------
NOME    PID    PRI    CPU    I/O
xxxx    xxx    xxx    xxx    xxx
xxxx    xxx    xxx    xxx    xxx
xxxx    xxx    xxx    xxx    xxx
xxxx    xxx    xxx    xxx    xxx
xxxx    xxx    xxx    xxx    xxx
xxxx    xxx    xxx    xxx    xxx
xxxx    xxx    xxx    xxx    xxx
-----------------------------------------------------------
Confirmar a Remoção (S/N): (solicitar confirmação ao operador)



Executar o Algoritimo // OK
-----------------------------------------------------------
NOME    PID    PRI    CPU    I/O   TERMINO
xxxx    xxx    xxx    xxx    xxx     xxx
xxxx    xxx    xxx    xxx    xxx     xxx
xxxx    xxx    xxx    xxx    xxx     xxx
xxxx    xxx    xxx    xxx    xxx     xxx
xxxx    xxx    xxx    xxx    xxx     xxx
xxxx    xxx    xxx    xxx    xxx     xxx
xxxx    xxx    xxx    xxx    xxx     xxx
-----------------------------------------------------------
Pressione ENTER para continuar ... (solicitar ao operador)



Exibir os Participantes da Equipe // OK
-----------------------------------------------------------
Nome Completo do Participante
Nome Completo do Participante
Nome Completo do Participante
Nome Completo do Participante
-----------------------------------------------------------
Pressione ENTER para continuar ... (solicitar ao operador)



Regras para o Escalonamento
===========================================================================================================================

1. Carregar todos os processos presentes na Tabela de Processos para o ambiente simulador, respeitando-se a
   ordem dos PIDs. // OK

2. Uma vez realizado todo o carregamento e iniciado o escalonamento, não serão admitidos novos processos. // OK

3. A Fila de Bloqueados será única e terá uma única posição, portanto, para algum processo entrar aquele que ali
   estiver terá que sair. // OK

4. O processo deverá ter atendido um ciclo de execução (CPU) e um ciclo de bloqueio (I/O), se existir, e assim
   por diante até serem esgotados todos os ciclos. // OK

5. Caso não exista mais processos nos estados Pronto e Executando mas exista processo no estado Bloqueado, este
   deverá ser resgatado e posicionado na Fila de Prontos para que a simulação continue. // OK

6. Caso se realize a simulação de um algoritimo com múltiplas filas, deve-se esvaziar completamente uma fila de
   mais alta prioridade para então atender uma fila de menor prioridade. // OK